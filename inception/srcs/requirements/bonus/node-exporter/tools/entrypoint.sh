#!/bin/sh
set -e

echo "Starting Node Exporter..."
exec /usr/local/bin/node_exporter --web.listen-address=":9100"
