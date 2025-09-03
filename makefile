.PHONY: all lint typecheck format complexity

all: lint typecheck complexity

install:
	poetry install

shell:
	poetry shell

lint:
	poetry run ruff check s_call_graph/

typecheck:
	poetry run mypy s_call_graph/

complexity:
	poetry run radon cc  s_call_graph/ -s -a

pyupgrade:
	poetry run pyupgrade --keep-runtime-typing --py312-plus s_call_graph/*.py
