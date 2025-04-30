FROM klee/klee:3.1


WORKDIR /home

COPY entry.sh .
COPY generate.py .
COPY schema.yaml .
COPY template.c.jinja2 .
COPY s_call_graph/ ./s_call_graph
COPY Samples/ ./Samples

RUN pip install Jinja2 pyyaml yamale pycparser rustworkx pydot

ENTRYPOINT ["./entry.sh"]
