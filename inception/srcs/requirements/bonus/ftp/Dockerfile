FROM alpine:3.20

RUN apk add --no-cache dumb-init vsftpd bash openrc

RUN adduser -D -h /var/www/html/wordpress ftpuser && \
    echo "ftpuser:joonhan" | chpasswd

COPY conf/vsftpd.conf /etc/vsftpd/vsftpd.conf

RUN mkdir -p /var/run/vsftpd/empty

EXPOSE 21 21000-21010

COPY tools/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

ENTRYPOINT ["/usr/bin/dumb-init", "--"]

CMD ["/entrypoint.sh"]