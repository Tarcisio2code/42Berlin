# USER DOCUMENTATION

## What is this project?

Inception runs a self-hosted WordPress website using three containerized services:

| Service | Role | Port |
|---|---|---|
| NGINX | HTTPS reverse proxy, sole entry point | 443 (external) |
| WordPress + php-fpm | Web application | 9000 (internal only) |
| MariaDB | Database | 3306 (internal only) |

Only NGINX is reachable from outside. WordPress and MariaDB are internal and never directly accessible from the host.


## Starting the project

```bash
cd ~/inception
make build
```

This will build all Docker images and start all three containers. First build takes several minutes — subsequent starts are fast.

To verify everything is running:

```bash
make ps
```

You should see three containers with status `Up`:

```
NAME        STATUS
nginx       Up
wordpress   Up
mariadb     Up
```


## Stopping the project

```bash
# Stop containers but keep data
make down

# Start again without rebuilding
make
# or
make up
```


## Accessing the website

Open a browser and go to:

```
https://tsilva.42.fr
```

You will see a security warning because the SSL certificate is self-signed. This is expected — click **Advanced** → **Accept the risk and continue** (Firefox) or **Proceed anyway** (Chrome).

The WordPress site will load on the front page.

### Accessing the administration panel

```
https://tsilva.42.fr/wp-admin
```


## Locating and managing credentials

All non-sensitive configuration is in `srcs/.env`:

```bash
cat srcs/.env
```

Sensitive passwords are stored as Docker secrets in the `secrets/` directory:

```
secrets/
├── db_user_password.txt  # Database user password
├── db_root_password.txt  # Database root password
├── wp_admin_password.txt # WordPress administrator password
└── wp_user_password.txt  # WordPress user password
```

To read a secret:
```bash
cat secrets/db_user_password.txt
```

**Never commit these files to git.** The secrets folder is listed in `.gitignore`.

### WordPress users

The project creates two WordPress users:

| Role | Username | Where defined |
|---|---|---|
| Administrator | `WP_ADMIN_USER` in `.env` | `srcs/.env` |
| Editor | `WP_USER` in `.env` | `srcs/.env` |

Note: the administrator username must not contain "admin" or "administrator".


## Understanding the services

### NGINX
- Handles all incoming HTTPS traffic on port 443
- Terminates SSL using a self-signed certificate
- Forwards PHP requests to WordPress via FastCGI on port 9000
- Only TLSv1.2 and TLSv1.3 are accepted

### WordPress + php-fpm
- Runs the WordPress application
- Communicates with MariaDB for all data storage
- Serves PHP files to NGINX via FastCGI
- WordPress files are stored in the `wp_data` volume

### MariaDB
- Stores all WordPress content (posts, users, settings)
- Only accessible from within the Docker network
- Database files are stored in the `mariadb_data` volume


## Checking that services are running correctly

### Quick status check

```bash
make ps
```

### Check a specific container

```bash
docker compose -f srcs/docker-compose.yml logs <conatiner name>
```

### Test NGINX is responding

```bash
curl -k https://tsilva.42.fr
# Should return HTML output
```

### Test MariaDB is running

```bash
docker exec -it mariadb mysqladmin ping -uroot -p$(cat secrets/db_root_password.txt) --silent
# Should print: mysqld is alive
```

### Test WordPress database connection

```bash
docker exec -it wordpress wp db check --allow-root
# Should print: Success: Database connection is successful
```


## Data persistence

All data survives container restarts and rebuilds:

| Data | Volume | Host path |
|---|---|---|
| WordPress files | `wp_data` | `~/data/wordpress` |
| Database | `mariadb_data` | `~/data/mariadb` |

To inspect stored data:

```bash
ls ~/data/wordpress/
ls ~/data/mariadb/
```

To fully reset all data:

```bash
make clean
```

Warning: this permanently deletes all WordPress content and database data.
