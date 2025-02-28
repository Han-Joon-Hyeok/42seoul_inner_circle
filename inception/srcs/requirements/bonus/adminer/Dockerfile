FROM alpine:3.20

RUN apk add --no-cache \
    dumb-init \
    php-fpm \
    php-opcache \
    php-mysqli \
    php-pdo_mysql \
    php-json \
    php-xml \
    php-gd \
    php-dom \
    php-zip \
    php-session \
    php-curl \
    php-openssl \
    php-mbstring \
    php-ctype \
    php-tokenizer \
    php-simplexml \
    php-fileinfo \
    php-exif \
    php-cli \
    php-gd \
    php-phar \
    curl \
    wget \
    supervisor \
    && mkdir -p /var/www/html

RUN wget --user-agent=Mozilla/5.0 --retry-connrefused --waitretry=3 -O /var/www/html/index.php https://github.com/vrana/adminer/releases/download/v4.17.1/adminer-4.17.1.php \
    && chmod 755 /var/www/html/index.php

COPY conf/supervisord.conf /etc/supervisord.conf

COPY conf/php.ini /etc/php83/php.ini

EXPOSE 8080

ENTRYPOINT [ "/usr/bin/dumb-init", "--" ]

CMD ["/usr/bin/supervisord", "-c", "/etc/supervisord.conf"]
