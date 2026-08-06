#!/bin/bash
set -e

MARIADB_PASSWORD=$(cat /run/secrets/db_user_password)
WP_ADMIN_PASSWORD=$(cat /run/secrets/wp_admin_password)
WP_USER_PASSWORD=$(cat /run/secrets/wp_user_password)

while ! mariadb-admin ping -h"mariadb" -u"$MARIADB_USER" -p"$MARIADB_PASSWORD" --silent; do
    sleep 2
done

# Ensure the web root directory exists
mkdir -p /var/www/html

cd /var/www/html

# Check if WordPress is already installed to avoid overwriting
if [ ! -f "wp-includes/version.php" ]; then
    wp core download --allow-root
fi

if [ ! -f "wp-config.php" ]; then
    wp config create --allow-root \
        --dbname=$MARIADB_DATABASE \
        --dbuser=$MARIADB_USER \
        --dbpass=$MARIADB_PASSWORD \
        --dbhost=mariadb
fi

if ! wp core is-installed --allow-root >/dev/null 2>&1; then
    wp core install --allow-root \
        --url=$DOMAIN_NAME \
        --title="$WP_TITLE" \
        --admin_user=$WP_ADMIN_USER \
        --admin_password=$WP_ADMIN_PASSWORD \
        --admin_email=$WP_ADMIN_EMAIL

    if ! wp user get "$WP_USER" --allow-root >/dev/null 2>&1; then
        wp user create \
            $WP_USER \
            $WP_USER_EMAIL \
            --user_pass=$WP_USER_PASSWORD \
            --role=author \
            --allow-root
    fi
fi

# Ensure the web server user owns the files 
chown -R www-data:www-data /var/www/html

# Launch PHP-FPM in foreground to keep the container running
exec php-fpm8.2 -F
