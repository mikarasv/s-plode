import os
from collections.abc import Callable

import pydot

from .custom_types import EdgeData, EdgeLabel, EdgeType, NodeDict
from .rustworkX import GraphRx


class Drawer:
    def __init__(
        self,
        file_path: str,
        graph: GraphRx,
        end: str,
        operations: list[str] = [],
        draw: bool = False,
        globals_: set[str] = set(),
    ) -> None:
        self.file_path = file_path
        self.graph = graph
        self.operations = operations
        self.end = end
        self.draw = draw
        self.globals = globals_

    @staticmethod
    def get_style(source: EdgeType) -> str:
        match source:
            case EdgeType.HOAS:
                return "dotted"
            case EdgeType.AST:
                return "solid"

    @staticmethod
    def edge_attr(data: EdgeData) -> dict[str, str]:
        style = Drawer.get_style(data.get("from_"))
        label = str(data["index"])

        label_type = data.get("label")
        if label_type == EdgeLabel.INVIS:
            return {"label": label, "style": "invis"}
        if label_type == EdgeLabel.UNIDIR:
            return {"style": style, "label": label, "dir": "forward"}

        return {"style": style, "label": label, "dir": "both"}

    def node_attr(self, data: NodeDict) -> dict[str, str]:
        return {
            "label": f"{str(data['name'])}",
            "color": "gray",
            "fillcolor": self._get_fill_color(data),
            "style": "filled",
            "fontcolor": "white",
        }

    def _get_fill_color(self, data: NodeDict) -> str:
        is_op = data["name"] in self.operations
        is_global = data["scope"] == "Global"
        is_known_global = data["name"] in self.globals

        return {
            (True,): "red",
            (False, True, True): "blue",
        }.get((is_op,) if is_op else (is_op, is_global, is_known_global), "black")

    def node_attr_factory(self) -> Callable[[NodeDict], dict[str, str]]:
        return self.node_attr

    def draw_graph(self) -> None:
        if not self.draw:
            print(f"{self.end:^100}".replace(" ", "-"))
        else:
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
