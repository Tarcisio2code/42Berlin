FROM debian:bookworm

# Install PHP-FPM, MySQL extensions, and essential tools
RUN apt-get update && apt-get upgrade -y && \
    apt-get install -y wget curl php8.2 php-fpm php-mysql mariadb-client && \
    rm -rf /var/lib/apt/lists/*

# Install WP-CLI to automate installation
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

# Copy PHP-FPM pool config and the setup script
COPY conf/www.conf /etc/php/8.2/fpm/pool.d/www.conf
COPY tools/init.sh /usr/local/bin/init.sh
RUN chmod +x /usr/local/bin/init.sh

RUN mkdir -p /run/php && chown www-data:www-data /run/php

# Set the working directory to the web root
WORKDIR /var/www/html

ENTRYPOINT ["/usr/local/bin/init.sh"]