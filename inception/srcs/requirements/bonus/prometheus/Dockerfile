FROM alpine:3.20

ENV PROMETHEUS_VERSION=3.2.1

RUN apk add --no-cache \
    dumb-init \
    wget \
    tar \
    gzip \
    bash \
    libc6-compat \
    && mkdir -p /etc/prometheus /var/lib/prometheus

RUN wget -O /tmp/prometheus.tar.gz https://github.com/prometheus/prometheus/releases/download/v${PROMETHEUS_VERSION}/prometheus-${PROMETHEUS_VERSION}.linux-amd64.tar.gz \
    && tar -xzf /tmp/prometheus.tar.gz -C /tmp \
    && mv /tmp/prometheus-${PROMETHEUS_VERSION}.linux-amd64/prometheus /usr/local/bin/ \
    && mv /tmp/prometheus-${PROMETHEUS_VERSION}.linux-amd64/promtool /usr/local/bin/ \
    && rm -rf /tmp/prometheus*

COPY conf/prometheus.yaml /etc/prometheus/prometheus.yaml

COPY tools/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

VOLUME [ "/var/lib/prometheus" ]

EXPOSE 9090

ENTRYPOINT [ "/usr/bin/dumb-init", "--" ]

CMD [ "/bin/sh", "/entrypoint.sh" ]
