FROM klee/klee:3.1


WORKDIR /home

COPY entry.sh .
COPY template.c.jinja2 .
COPY schema.yaml .

RUN pip install Jinja2 pyyaml yamale pycparser networkx

ENTRYPOINT ["./entry.sh"]
