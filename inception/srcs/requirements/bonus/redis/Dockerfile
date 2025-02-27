FROM alpine:3.20

RUN apk add --no-cache dumb-init redis

EXPOSE 6379

ENTRYPOINT ["/usr/bin/dumb-init", "--"]

CMD ["redis-server", "--protected-mode", "no"]