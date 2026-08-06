FROM debian:bookworm

# Install MariaDB server and clear apt cache
RUN apt-get update && apt-get upgrade -y && \
    apt-get install -y mariadb-server && \
    rm -rf /var/lib/apt/lists/*

# Copy custom configuration and database setup script
COPY tools/init.sh /usr/local/bin/init.sh
COPY conf/mariadb.cnf /etc/mysql/mariadb.conf.d/99-custom.cnf
RUN chmod +x /usr/local/bin/init.sh

EXPOSE 3306

ENTRYPOINT ["/usr/local/bin/init.sh"]