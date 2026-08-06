FROM debian:bookworm

# Install NGINX and OpenSSL, then clear cache
RUN apt-get update && apt-get install -y \
    nginx \
    openssl \
    && rm -rf /var/lib/apt/lists/*

# Copy custom config and SSL keys/certs
COPY conf/nginx.conf /etc/nginx/conf.d/default.conf
COPY tools/init.sh /usr/local/bin/init.sh

RUN chmod +x /usr/local/bin/init.sh

EXPOSE 443

ENTRYPOINT ["/usr/local/bin/init.sh"]