FROM klee/klee:3.1


WORKDIR /home

COPY entry.sh .
COPY generate.py .
COPY schema.yaml .
COPY template.c.jinja2 .
COPY s_call_graph/ ./s_call_graph
COPY Samples/ ./Samples

RUN pip install --no-cache-dir Jinja2==3.1.5 pyyaml==6.0.2 yamale==6.0.0 pycparser==2.22 rustworkx==0.16.0 pydot==3.0.4 networkx==3.1 typing-extensions

ENTRYPOINT ["./entry.sh"]
