FROM ubuntu:22.04

# Toolchain required by the practical: compile, run and investigate.
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        g++ make gdb valgrind && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . /app

# Build on image creation so the container is ready to run.
RUN make

CMD ["./taskforge"]
