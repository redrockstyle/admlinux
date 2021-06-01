FROM ubuntu:20.04

RUN apt update
RUN apt install -y openssh-server whois nano netcat
RUN useradd -m -p $(mkpasswd -m sha-512 12345) -s /bin/bash user
RUN mkdir /var/run/sshd

EXPOSE 22
EXPOSE 8000
CMD ["/usr/sbin/sshd", "-D"]
