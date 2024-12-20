FROM klee/klee:3.0

WORKDIR /home

COPY entry.sh .
COPY template.c.jinja2 .

RUN pip install Jinja2 && pip install pyyaml

ENTRYPOINT ["./entry.sh"]