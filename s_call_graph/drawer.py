import os
from typing import Any, Callable, Dict, List

import pydot

from .custom_types import EdgeType, NodeDict, NodeType
from .rustworkX import GraphRx


class Drawer:
    def __init__(
        self,
        file_path: str,
        graph: GraphRx,
        end: str,
        operations: List[str] = [],
        draw: bool = False,
    ) -> None:
        self.file_path = file_path
        self.graph = graph
        self.operations = operations
        self.end = end
        self.draw = draw

    @staticmethod
    def edge_attr(data: Dict[str, Any]) -> Dict[str, str]:
        def get_style(source: EdgeType) -> str:
            match source:
                case EdgeType.HOAS:
                    return "dotted"
                case EdgeType.AST:
                    return "solid"

        style = get_style(data.get("from", ""))
        label = str(data["index"])

        label_type = data.get("label")
        if label_type == "invisible":
            return {"label": label, "style": "invis"}
        if label_type == "unidir":
            return {"style": style, "label": label, "dir": "forward"}

        return {"style": style, "label": label, "dir": "both", "fontcolor": "white"}

    def node_attr_factory(self) -> Callable[[NodeDict], Dict[str, str]]:
        def node_attr(data: NodeDict) -> Dict[str, str]:
            if data["name"] in self.operations:
                color = "red"
            elif data["scope"] == "Global" and data["node_type"] == NodeType.ID:
                color = "blue"
            else:
                color = "black"
            return {
                # "label": str(data["name"]) + str(data["node_index"]),
                "label": str(data["name"]),
                "color": "gray",
                "fillcolor": color,
                "style": "filled",
                "fontcolor": "white",
            }

        return node_attr

    def draw_graph(self) -> None:
        if not self.draw:
            print(f"{self.end:^100}".replace(" ", "-"))
        else:
            node_attr_func = self.node_attr_factory()
            dot_str = self.graph.graph.to_dot(
                node_attr=node_attr_func,
                edge_attr=self.edge_attr,
            )
            if not dot_str:
                raise ValueError("dot_str is empty or None!")

            dot = pydot.graph_from_dot_data(dot_str)[0]
            folder_path = os.path.splitext(self.file_path)[0]
            os.makedirs(folder_path, exist_ok=True)
            dot.write_png(folder_path + "/" + self.end + ".png")
