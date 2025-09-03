import os
from collections.abc import Callable
from pathlib import Path

import pydot

from .custom_types import EdgeData, EdgeLabel, EdgeType, NodeDict
from .params_n_globals import ParamsNGlobalsParser
from .rustworkX import GraphRx


class Drawer:
    def __init__(
        self,
        file_path: Path,
        graph: GraphRx,
        end: str,
        ansatz: str | None = None,
        operations: list[str] = [],
        draw: bool = False,
    ) -> None:
        self.file_path = file_path
        self.graph = graph
        self.operations = operations
        self.end = end
        self.draw = draw
        self.ansatz = ansatz

    @staticmethod
    def _get_style(source: EdgeType) -> str:
        match source:
            case EdgeType.NAME_RES:
                return "dotted"
            case EdgeType.AST:
                return "solid"
            case _:
                raise ValueError(f"Unknown edge type: {source}")

    @staticmethod
    def _edge_attr(data: EdgeData) -> dict[str, str]:
        edge_type = data["from_"]
        style = Drawer._get_style(edge_type)
        edge_index = str(data["edge_index"])
        if edge_index == "None":
            edge_index = ""

        edge_label = data["label"]
        if edge_label == EdgeLabel.INVIS:
            return {"style": "invis"}
        if edge_label == EdgeLabel.UNIDIR:
            return {"style": style, "dir": "forward"}

        return {"style": style, "dir": "both"}

    def _get_fill_color(self, data: NodeDict) -> str:
        is_op = data["name"] in self.operations
        names_parser = ParamsNGlobalsParser(self.graph, self.ansatz)
        names_parser.get_globals_n_params()
        is_posible_sym_var = data["name"] in names_parser.get_sym_var_names()

        return {
            (True,): "red",
            (False, True): "blue",
        }.get((is_op,) if is_op else (is_op, is_posible_sym_var), "black")

    def _node_attr(self, data: NodeDict) -> dict[str, str]:
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

    def _node_attr_factory(self) -> Callable[[NodeDict], dict[str, str]]:
        return self._node_attr

    def draw_graph(self) -> None:
        if self.draw:
            node_attr_func = self._node_attr_factory()
            dot_str = self.graph.to_dot(
                node_attr=node_attr_func,
                edge_attr=self._edge_attr,
            )
            if not dot_str:
                raise ValueError("dot_str is empty or None!")

            dot = pydot.graph_from_dot_data(dot_str)[0]
            folder_path = os.path.splitext(self.file_path)[0]
            os.makedirs(folder_path, exist_ok=True)
            dot.write_png(folder_path + "/" + self.end + ".png")
