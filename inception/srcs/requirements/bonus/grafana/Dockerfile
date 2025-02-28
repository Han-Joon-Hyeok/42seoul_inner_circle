FROM alpine:3.20

ENV GRAFANA_VERSION=11.5.2

RUN apk add --no-cache \
    dumb-init \
    wget \
    bash \
    libc6-compat \
    && mkdir -p /var/lib/grafana /usr/share/grafana/ /etc/grafana/provisioning

RUN wget -O /tmp/grafana.tar.gz https://dl.grafana.com/oss/release/grafana-${GRAFANA_VERSION}.linux-amd64.tar.gz \
    && tar -xzf /tmp/grafana.tar.gz -C /tmp \
    && mv /tmp/grafana-v${GRAFANA_VERSION}/* /usr/share/grafana/ \
    && rm -rf /tmp/grafana*

COPY conf/grafana.ini /etc/grafana/grafana.ini
COPY provisioning /etc/grafana/provisioning

VOLUME [ "/var/lib/grafana" ]

EXPOSE 3000

ENTRYPOINT [ "/usr/bin/dumb-init", "--" ]

CMD [ "/usr/share/grafana/bin/grafana", "server", "--homepath=/usr/share/grafana/", "--config=/etc/grafana/grafana.ini" ]
