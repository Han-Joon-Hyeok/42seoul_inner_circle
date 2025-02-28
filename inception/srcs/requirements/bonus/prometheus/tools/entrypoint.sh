#!/bin/sh
set -e

echo "Starting Prometheus..."
exec /usr/local/bin/prometheus \
    --config.file=/etc/prometheus/prometheus.yaml \
    --storage.tsdb.path=/var/lib/prometheus \
    --web.console.templates=/etc/prometheus/consoles \
    --web.console.libraries=/etc/prometheus/console_libraries \
    --web.enable-lifecycle
