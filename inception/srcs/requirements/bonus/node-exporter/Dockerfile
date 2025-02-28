FROM alpine:3.20

ENV NODE_EXPORTER_VERSION=1.9.0

RUN apk add --no-cache \
    dumb-init \
    wget \
    tar \
    gzip \
    bash \
    libc6-compat \
    && mkdir -p /etc/node-exporter /var/lib/node-exporter

RUN wget -O /tmp/node-exporter.tar.gz https://github.com/prometheus/node_exporter/releases/download/v${NODE_EXPORTER_VERSION}/node_exporter-${NODE_EXPORTER_VERSION}.linux-amd64.tar.gz \
    && tar -xzf /tmp/node-exporter.tar.gz -C /tmp \
    && mv /tmp/node_exporter-${NODE_EXPORTER_VERSION}.linux-amd64/node_exporter /usr/local/bin/ \
    && rm -rf /tmp/node-exporter*

COPY ./tools/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

EXPOSE 9100

ENTRYPOINT [ "/usr/bin/dumb-init", "--" ]

CMD [ "/bin/sh", "/entrypoint.sh" ]
