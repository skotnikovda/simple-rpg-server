FROM ubuntu:latest as env

ARG DEBIAN_FRONTEND=noninteractive

RUN apt update
RUN apt install -y gcc g++ libboost-dev cmake
RUN apt install -y libpq-dev postgresql-server-dev-all
RUN apt install -y curl

FROM env as build

COPY . /app

WORKDIR /app/bin

RUN cmake ..
RUN cmake --build . --target domain_test

WORKDIR /app

RUN groupadd -r sample && useradd -r -g sample sample
USER sample

EXPOSE 8080

ENTRYPOINT ./bin/domain_test
