# Base image
FROM alpine:3.16

# Install necessary packages
RUN apk add --no-cache \
    dumb-init \
    curl \
    ca-certificates

RUN apk add --no-cache \
    php-fpm \
    php-opcache \
    php-mysqli \
    php-pdo_mysql \
    php-json \
    php-xml \
    php-gd \
    php-dom \
    php-zip \
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
    mariadb-client

# Create directories for wordpress
RUN mkdir -p /var/www/html/wordpress

# Download wp-cli
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/bin/wp

# Copy php-fpm configuration file
COPY ./conf/www.conf /etc/php8/php-fpm.d/

RUN chmod +x /usr/bin/dumb-init
COPY ./tools/entrypoint.sh /entrypoint.sh

# Expose port 9000 for php-fpm
EXPOSE 9000

# Start dumb-init for PID 1
ENTRYPOINT ["/usr/bin/dumb-init", "--"]

# Start php-fpm in the foreground
CMD ["/bin/sh", "entrypoint.sh"]
