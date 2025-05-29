import os
from collections.abc import Callable
from pathlib import Path

import pydot

from .custom_types import EdgeData, EdgeLabel, EdgeType, NodeDict
from .rustworkX import GraphRx


class Drawer:
    def __init__(
        self,
        file_path: Path,
        graph: GraphRx,
        end: str,
        operations: list[str] = [],
        draw: bool = False,
        sym_var: set[str] = set(),
    ) -> None:
        self.file_path = file_path
        self.graph = graph
        self.operations = operations
        self.end = end
        self.draw = draw
        self.sym_var_names = sym_var

    @staticmethod
    def get_style(source: EdgeType) -> str:
        match source:
            case EdgeType.HOAS:
                return "dotted"
            case EdgeType.AST:
                return "solid"
            case _:
                raise ValueError(f"Unknown edge type: {source}")

    @staticmethod
    def edge_attr(data: EdgeData) -> dict[str, str]:
        edge_type = data["from_"]
        style = Drawer.get_style(edge_type)
        edge_index = str(data["edge_index"])

        edge_label = data["label"]
        if edge_label == EdgeLabel.INVIS:
            return {"label": edge_index, "style": "invis"}
        if edge_label == EdgeLabel.UNIDIR:
            return {"style": style, "label": edge_index, "dir": "forward"}

        return {"style": style, "label": edge_index, "dir": "both"}

    def node_attr(self, data: NodeDict) -> dict[str, str]:
        name = data["name"]
        if isinstance(name, str):
            name = name.replace('"', "")
        else:
            name = str(name)
        return {
            "label": name,
            "color": "gray",
            "fillcolor": self._get_fill_color(data),
            "style": "filled",
            "fontcolor": "white",
        }

    def _get_fill_color(self, data: NodeDict) -> str:
        is_op = data["name"] in self.operations
        is_global = data["scope"] == "Global"
        is_known_global = data["name"] in self.sym_var_names

        return {
            (True,): "red",
            (False, True, True): "blue",
        }.get((is_op,) if is_op else (is_op, is_global, is_known_global), "black")

    def node_attr_factory(self) -> Callable[[NodeDict], dict[str, str]]:
        return self.node_attr

    def draw_graph(self) -> None:
        if self.draw:
            node_attr_func = self.node_attr_factory()
            dot_str = self.graph.to_dot(
                node_attr=node_attr_func,
                edge_attr=self.edge_attr,
            )
            if not dot_str:
                raise ValueError("dot_str is empty or None!")

            dot = pydot.graph_from_dot_data(dot_str)[0]
            folder_path = os.path.splitext(self.file_path)[0]
            os.makedirs(folder_path, exist_ok=True)
            dot.write_png(folder_path + "/" + self.end + ".png")
