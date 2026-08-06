#!/bin/bash

# Exit immediately if a command fails
set -e

MARIADB_USER_PASSWORD=$(cat /run/secrets/db_user_password)
MARIADB_ROOT_PASSWORD=$(cat /run/secrets/db_root_password)

DATA_DIR="/var/lib/mysql"

mkdir -p /run/mysqld
chown mysql:mysql /run/mysqld

# Initialize MariaDB system tables if the data directory is empty
if [ ! -d "$DATA_DIR/mysql" ]; then
    mariadb-install-db --user=mysql --datadir="$DATA_DIR" > /dev/null
fi

# Start MariaDB in background with networking disabled for initial setup
mysqld --user=mysql --datadir="$DATA_DIR" --skip-networking &
MYSQL_PID="$!"

# Wait for the database service to be ready
until mysqladmin ping >/dev/null 2>&1; do
    sleep 1
done

# Checks if the root user already has a password configured; otherwise (first boot), applies the security password.
if ! mysql -u root -p"${MARIADB_ROOT_PASSWORD}" >/dev/null 2>&1 <<SQL
SELECT 1;
SQL
then
    mysql -u root <<SQL
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MARIADB_ROOT_PASSWORD}';
SQL
fi

# Execute SQL commands to secure root and create the WordPress database/user
mysql -u root -p"${MARIADB_ROOT_PASSWORD}" <<SQL
CREATE DATABASE IF NOT EXISTS ${MARIADB_DATABASE};
CREATE USER IF NOT EXISTS '${MARIADB_USER}'@'%' IDENTIFIED BY '${MARIADB_USER_PASSWORD}';
ALTER USER '${MARIADB_USER}'@'%' IDENTIFIED BY '${MARIADB_USER_PASSWORD}';
CREATE USER IF NOT EXISTS '${MARIADB_USER}'@'wordpress.srcs_inception' IDENTIFIED BY '${MARIADB_USER_PASSWORD}';
ALTER USER '${MARIADB_USER}'@'wordpress.srcs_inception' IDENTIFIED BY '${MARIADB_USER_PASSWORD}';
GRANT ALL PRIVILEGES ON ${MARIADB_DATABASE}.* TO '${MARIADB_USER}'@'%';
GRANT ALL PRIVILEGES ON ${MARIADB_DATABASE}.* TO '${MARIADB_USER}'@'wordpress.srcs_inception';
FLUSH PRIVILEGES;
SQL

# Shutdown the temporary background instance
mysqladmin -u root -p"${MARIADB_ROOT_PASSWORD}" shutdown
wait "$MYSQL_PID"

# Start MariaDB in foreground as PID 1
exec mysqld --user=mysql --datadir="$DATA_DIR"