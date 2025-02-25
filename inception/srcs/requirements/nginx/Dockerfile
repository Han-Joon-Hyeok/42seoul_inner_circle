# Base image
FROM alpine:3.20

# Install nginx, dumb-init, openssl
RUN apk add --no-cache nginx dumb-init openssl

# Create directories for SSL certificates and Nginx logs
RUN mkdir -p /etc/nginx/certs /var/log/nginx
# Generate a self-signed SSL certificate using OpenSSL
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
  -keyout /etc/nginx/certs/server.key \
  -out /etc/nginx/certs/server.crt \
  -subj "/C=KR/ST=Seoul/O=42Seoul/CN=joonhan.42.fr/emailAddress=joonhan.42seoul.kr/"

# Copy Nginx configuration file
COPY conf/my.conf /etc/nginx/http.d

# Expose port 443
EXPOSE 443

# Start dumb-init for PID 1
ENTRYPOINT ["/usr/bin/dumb-init", "--"]

# Start Nginx in the foreground
CMD ["nginx", "-g", "daemon off;"]
