FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    build-essential \
    g++ \
    make \
    gdb \
    valgrind \
    zip \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . /app

RUN make clean && make

CMD ["./taskforge"]