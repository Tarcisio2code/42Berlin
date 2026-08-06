# DEVELOPER DOCUMENTATION

## Project structure

```
inception/
├── Makefile                          # Build and lifecycle management
├── README.md
├── USER_DOC.md
├── DEV_DOC.md
├── secrets/                          # Secret files — gitignored, never committed
│   ├── db_user_password.txt          # MariaDB wordpress user password
│   ├── db_root_password.txt          # MariaDB root password
│   ├── wp_admin_password.txt         # WordPress administrator password
│   └── wp_user_password.txt          # WordPress user password
└── srcs/
    ├── .env                          # Non-sensitive config — gitignored
    ├── docker-compose.yml
    └── requirements/
        ├── nginx/
        │   ├── Dockerfile
        │   ├── conf/
        │   │   └── nginx.conf        # nginx config
        │   └── tools/
        │       └── init.sh           # nginx entrypoint
        ├── wordpress/
        │   ├── Dockerfile
        │   ├── conf/
        │   │   └── www.conf          # php-fpm pool config
        │   └── tools/
        │       └── init.sh           # WordPress entrypoint
        └── mariadb/
            ├── Dockerfile
            ├── conf/
            │   └── mariadb.cnf       # MariaDB config
            └── tools/
                └── init.sh           # Database entrypoint
```

## Prerequisites

- Debian Bookworm (12) — either bare metal or inside a VM
- Docker Engine (not Docker Desktop)
- Docker Compose plugin (`docker compose` v2)
- `make`, `curl`, `git`, `openssl`

### Install Docker Engine on Debian Bookworm

```bash
# Remove old versions
sudo apt-get remove -y docker docker-engine docker.io containerd runc 2>/dev/null; true

# Install dependencies
sudo apt-get update
sudo apt-get install -y ca-certificates curl gnupg lsb-release

# Add Docker GPG key
sudo mkdir -p /etc/apt/keyrings
curl -fsSL https://download.docker.com/linux/debian/gpg | \
    sudo gpg --dearmor -o /etc/apt/keyrings/docker.gpg
sudo chmod a+r /etc/apt/keyrings/docker.gpg

# Add Docker repository
echo \
  "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.gpg] \
  https://download.docker.com/linux/debian \
  $(lsb_release -cs) stable" | \
  sudo tee /etc/apt/sources.list.d/docker.list > /dev/null

# Install
sudo apt-get update
sudo apt-get install -y \
    docker-ce \
    docker-ce-cli \
    containerd.io \
    docker-buildx-plugin \
    docker-compose-plugin

# Add user to docker group (no sudo needed for docker commands)
sudo usermod -aG docker $USER
newgrp docker

# Clean credential config
mkdir -p ~/.docker
echo '{"auths":{}}' > ~/.docker/config.json

# Verify
docker run --rm hello-world
docker compose version
```

## Setting up the environment from scratch

### 1. Clone the repository

### 2. Create secret files

```bash
echo "your_db_user_password"   > secrets/db_user_password.txt
echo "your_db_root_password"   > secrets/db_root_password.txt
echo "your_wp_admin_password"  > secrets/wp_admin_password.txt
echo "your_wp_user_password"   > secrets/wp_user_password.txt
```

These files are gitignored. Choose strong passwords. They are mounted read-only inside containers via Docker secrets at `/run/secrets/`.

### 3. Create the .env file

```bash
cat > srcs/.env << 'EOF'
DOMAIN_NAME=tsilva.42.fr

# MariaDB
MYSQL_DATABASE=wordpress
MYSQL_USER=wpuser
MYSQL_ROOT_PASSWORD=your_db_root_password

# WordPress admin (must NOT contain admin/administrator in username)
WP_ADMIN_USER=wpmaster
WP_ADMIN_EMAIL=wpmaster@tsilva.42.fr

# WordPress second user (editor)
WP_USER=wpeditor
WP_USER_EMAIL=wpeditor@tsilva.42.fr
EOF
```

Note: passwords are NOT stored in `.env` — they come from Docker secrets. Only usernames and non-sensitive config go here.

### 4. Generate SSL certificate

```bash
mkdir -p srcs/requirements/nginx/tools
openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout srcs/requirements/nginx/tools/nginx.key \
    -out    srcs/requirements/nginx/tools/nginx.crt \
    -subj "/C=FR/ST=IDF/L=Paris/O=42/CN=tsilva.42.fr"
```

### 5. Add domain to /etc/hosts (inside VM)

```bash
echo "127.0.0.1 tsilva.42.fr" | sudo tee -a /etc/hosts
```

## Building and launching the project

```bash
# Full build and start
make

# Which runs:
# 1. mkdir -p ~/data/mariadb ~/data/wordpress
# 2. docker compose -f srcs/docker-compose.yml up -d --build
```

### Environment-aware DATA_PATH

The Makefile detects whether it's running on a 42 cluster (goinfre) or a local VM:

```makefile
ifeq ($(shell test -d /goinfre && echo yes), yes)
    DATA_PATH = /goinfre/$(LOGIN)/data
else
    DATA_PATH = $(HOME)/data
endif
```

`DATA_PATH` is exported and used by `docker-compose.yml` for volume device paths:

```yaml
volumes:
  mariadb_data:
    driver_opts:
      device: ${DATA_PATH}/mariadb
  wp_data:
    driver_opts:
      device: ${DATA_PATH}/wordpress
```

## How secrets work

Passwords are never stored in environment variables or Dockerfiles. They are passed as Docker secrets:

```yaml
# docker-compose.yml
secrets:
  db_user_password:
    file: ../secrets/db_user_password.txt
  db_root_password:
    file: ../secrets/db_root_password.txt
```

Inside containers they are mounted at `/run/secrets/<name>`. Scripts read them with a helper function that falls back to env vars if the secret file isn't available (WSL2 compatibility):

```bash
read_secret() {
    local secret_file="/run/secrets/$1"
    local env_var="$2"
    if [ -f "$secret_file" ] && [ ! -d "$secret_file" ]; then
        cat "$secret_file"
    else
        echo "${!env_var}"
    fi
}

DB_PASS=$(read_secret "db_user_password" "MYSQL_PASSWORD")
```

## Managing containers and volumes

### Makefile targets

```bash
make          # setup + build + start (default)
make up       # build and start containers
make down     # stop and remove containers
make start    # start existing containers
make stop     # stop containers without removing
make clean    # down + remove images + delete data volumes
make re       # clean + all (full rebuild from scratch)
make logs     # follow all container logs
make status   # show container status
```

### Useful Docker commands

```bash
# List running containers
docker ps

# Enter a container shell
docker exec -it mariadb bash
docker exec -it wordpress bash
docker exec -it nginx bash

# View container logs
docker logs -f mariadb
docker logs -f wordpress
docker logs -f nginx

# Inspect a volume
docker volume inspect srcs_mariadb_data
docker volume inspect srcs_wp_data

# List all volumes
docker volume ls

# Remove a specific volume manually
docker volume rm srcs_mariadb_data
```

### Checking the Docker network

```bash
# Inspect the inception network
docker network inspect srcs_inception

# Verify containers are connected
docker network inspect srcs_inception --format \
    '{{range .Containers}}{{.Name}} {{.IPv4Address}}{{"\n"}}{{end}}'
```

## Where data is stored and how it persists

### Volume mapping

| Docker volume | Mount inside container | Host path |
|---|---|---|
| `srcs_mariadb_data` | `/var/lib/mysql` | `~/data/mariadb` |
| `srcs_wp_data` | `/var/www/html` | `~/data/wordpress` |

Both are named volumes using `driver: local` with `type: none` and `o: bind`, which means Docker manages the volume metadata but the actual files live at the specified host path.

### Data persistence across operations

| Operation | Data survives? |
|---|---|
| `make down` + `make up` | Yes |
| `make stop` + `make start` | Yes |
| Container crash + auto-restart | Yes |
| `make re` / `make clean` | No — data is deleted |
| Host reboot | Yes |

### Inspecting data directly

```bash
# WordPress files
ls ~/data/wordpress/wp-content/

# MariaDB files
ls ~/data/mariadb/

# Query the database directly
docker exec -it mariadb mysql \
    -u$(grep MYSQL_USER srcs/.env | cut -d= -f2) \
    -p$(cat secrets/db_user_password.txt) \
    $(grep MYSQL_DATABASE srcs/.env | cut -d= -f2) \
    -e "SHOW TABLES;"
```

## Container startup sequence

Understanding the boot order helps diagnose failures:

```
mariadb starts
    └── init-db.sh runs
        ├── mysql_install_db (first run only)
        ├── mysqld_safe --skip-networking (temporary)
        ├── creates database + user
        ├── stops temporary instance
        └── exec mysqld_safe (PID 1, permanent)

wordpress starts (depends_on: mariadb)
    └── wp-setup.sh runs
        ├── waits for MariaDB port to accept connections
        ├── wp core download (first run only)
        ├── wp config create (first run only)
        ├── wp core install (first run only)
        ├── wp user create editor (first run only)
        ├── chown www-data
        └── exec php-fpm -F (PID 1, permanent)

nginx starts (depends_on: wordpress)
    └── nginx -g "daemon off;" (PID 1, permanent)
```

All entrypoints end with `exec` so the service process becomes PID 1 and receives signals correctly. No `tail -f`, `sleep infinity`, or infinite loops are used.

## Rebuilding a single service

```bash
# Rebuild only wordpress image and restart its container
docker compose -f srcs/docker-compose.yml up -d --build wordpress

# Same for others
docker compose -f srcs/docker-compose.yml up -d --build mariadb
docker compose -f srcs/docker-compose.yml up -d --build nginx
```

## Common issues

### MariaDB access denied after rebuild

If you rebuild without `make clean`, the old database files in `~/data/mariadb` still have the old root password. The init script won't re-run because the data directory already exists.

```bash
# Full reset
make clean
make
```

### WordPress stuck waiting for MariaDB

The `wp-setup.sh` script pings MariaDB before proceeding. If it loops forever:

```bash
# Check MariaDB logs
docker logs mariadb

# Manually test connection from wordpress container
docker exec -it wordpress mysqladmin ping -h mariadb --silent
```

### Volume mount fails — no such file or directory

The host data directories must exist before Docker can bind-mount them. The `make setup` target creates them, but if you run `docker compose up` directly:

```bash
mkdir -p ~/data/mariadb ~/data/wordpress
```

### Port 443 already in use

```bash
sudo ss -tlnp | grep 443
# Find and stop whatever is using it, then:
make up
```