FROM klee/klee:3.0

WORKDIR /home

COPY entry.sh .
COPY template.c.jinja2 .
COPY schema.yaml .

RUN pip install Jinja2 pyyaml yamale

ENTRYPOINT ["./entry.sh"]
