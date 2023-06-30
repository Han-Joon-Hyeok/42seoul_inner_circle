# Base image
FROM alpine:3.16

# Install necessary packages
RUN apk add --no-cache \
	dumb-init \
    mariadb \
	mariadb-client

# Create mysql directories
RUN mkdir -p /run/mysqld /var/lib/mysql

# MariaDB 10.4 이후 버전부터 root 계정 인증을 unix_socket 으로 한다.
# 이 방식은 유닉스 계열 시스템의 root 계정이 MariaDB 의 root 계정을 소유하며 관리할 수 있는 방식이다.
# 그래서 유닉스 계열 운영체제의 root 사용자가 실행한 프로세스에 MariaDB 에 접속하는 경우,
# 소켓 시스템 변수에 정의된 로컬 Unix 소켓 파일을 통해 암호 입력 없이 로그인을 한다.
# 그래서 암호를 입력해서 MariaDB 를 실행하려면 -auth-root-authentication-method 옵션을 normal 로 바꾸어야 한다.
RUN mariadb-install-db --datadir=/var/lib/mysql --auth-root-authentication-method=normal

# Copy mariadb configuration files
COPY ./conf/my.cnf /etc/my.cnf
COPY ./conf/mariadb-server.cnf /etc/my.cnf.d/mariadb-server.cnf

RUN chmod +x /usr/bin/dumb-init
COPY ./tools/entrypoint.sh /entrypoint.sh

# Expose port 3306 for mariadb
EXPOSE 3306

# Start dumb-init for PID 1
ENTRYPOINT ["/usr/bin/dumb-init", "--"]

# Start mariadb in the foreground
CMD ["/bin/sh", "entrypoint.sh"]
