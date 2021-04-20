FROM debian:buster-slim

ENV DEBIAN_FRONTEND=noninteractive

RUN apt update
RUN apt install -y libreadline-dev wget cmake valgrind make clang

RUN mkdir /test_dir
WORKDIR /test_dir
RUN useradd -m user1
RUN apt install sudo

ENTRYPOINT cp -r /minishell/* /test_dir && make run
