FROM ubuntu:latest as env

ARG DEBIAN_FRONTEND=noninteractive

RUN apt update
RUN apt install -y gcc g++ libboost-dev cmake
RUN apt install -y libpq-dev postgresql-server-dev-all
RUN apt install -y curl

FROM env as build

COPY . /app

WORKDIR /app/bin

RUN mkdir /app/logs
RUN touch /app/logs/basic-log.txt

RUN groupadd -r sample && useradd -r -g sample sample
RUN chown -R sample:sample /app
RUN chmod 777 /app/logs/basic-log.txt
USER sample

RUN cmake ..
#RUN cmake --build . --target domain_test
RUN cmake --build . --target server

WORKDIR /app

EXPOSE 8080

#ENTRYPOINT ./bin/domain/domain_test 

ENTRYPOINT ./bin/server
