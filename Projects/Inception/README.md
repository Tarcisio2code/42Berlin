# 42 Berlin - Projects - Inception
![Makefile](https://img.shields.io/badge/build-Makefile-orange.svg)
![Docker](https://img.shields.io/badge/docker-%230db7ed.svg?style=flat&logo=docker&logoColor=white)
![Docker Compose](https://img.shields.io/badge/docker%20compose-%232496ED.svg?style=flat&logo=docker&logoColor=white)
![Nginx](https://img.shields.io/badge/nginx-%23009639.svg?style=flat&logo=nginx&logoColor=white)
![WordPress](https://img.shields.io/badge/wordpress-%231177bb.svg?style=flat&logo=wordpress&logoColor=white)
![MariaDB](https://img.shields.io/badge/MariaDB-%23003545.svg?style=flat&logo=mariadb&logoColor=white)
![Alpine Linux](https://img.shields.io/badge/Alpine_Linux-%230D597F.svg?style=flat&logo=alpine-linux&logoColor=white)
![42](https://img.shields.io/badge/school-42Berlin-black.svg)
![Status](https://img.shields.io/badge/status-completed-success?style=flat-square)

*This project has been created as part of the 42 curriculum by tsilva.*

## Description

Inception is a system administration project from the 42 curriculum. The goal is to deepen knowledge of Docker by building a small but complete infrastructure composed of multiple services, each running in its own dedicated container, orchestrated with Docker Compose inside a Virtual Machine.

The infrastructure consists of:
- **NGINX** — the sole entry point to the infrastructure, handling HTTPS traffic on port 443 using TLSv1.2 or TLSv1.3
- **WordPress + php-fpm** — the web application, running without NGINX
- **MariaDB** — the relational database backend for WordPress

All services communicate through an isolated Docker network. Persistent data is stored in named Docker volumes mapped to the host filesystem.

### Design Choices

#### Virtual Machines vs Docker
A Virtual Machine emulates an entire operating system, including its own kernel, which makes it heavy, slow to start, and resource-intensive. Docker containers share the host kernel and isolate only the application layer, making them lightweight, fast to start, and efficient. However, VMs provide stronger isolation. In this project, Docker runs **inside** a VM — combining the isolation of a VM for the overall environment with the efficiency of containers for each service.

#### Secrets vs Environment Variables
Environment variables are convenient but potentially exposed through process listings, logs, or child processes. Docker secrets are mounted as files inside `/run/secrets/` inside the container, accessible only to that container and never exposed in the image layers or environment. In this project, sensitive credentials (database passwords) are stored as Docker secrets, while non-sensitive configuration (usernames, domain name, database name) lives in the `.env` file.

#### Docker Network vs Host Network
With `network: host`, containers share the host's network namespace directly — no isolation, any port conflict affects the host. A Docker bridge network (`driver: bridge`) creates an isolated virtual network where containers communicate by service name (DNS), and only explicitly published ports are reachable from outside. This project uses a custom bridge network called `inception`, keeping all inter-container traffic internal and only exposing port 443 via NGINX.

#### Docker Volumes vs Bind Mounts
Bind mounts directly map a host path into a container — simple but tightly coupled to the host filesystem structure. Named volumes are managed by Docker, portable, and the recommended approach for persistent data. This project uses named volumes with `driver_opts` to store data at a specific host path (`~/data/`), satisfying the subject requirement while keeping the compose file portable via the `${DATA_PATH}` environment variable.

## Instructions

### Prerequisites

- A Virtual Machine (Linux Environment)
- Docker Engine and Docker Compose plugin installed
- `git` and `make` installed
- Port 443 available on the host

### Installation

Clone the repository

```bash
# Create secret files (never commit these)
mkdir -p secrets
echo "your_db_user_password"   > secrets/db_user_password.txt
echo "your_db_root_password"   > secrets/db_root_password.txt
echo "your_wp_admin_password"  > secrets/wp_admin_password.txt
echo "your_wp_user_password"   > secrets/wp_user_password.txt

# Copy and edit the environment file
cp srcs/.env.example srcs/.env

# Add domain to /etc/hosts (inside the VM)
echo "127.0.0.1 tsilva.42.fr" | sudo tee -a /etc/hosts
```

### Running the project

```bash
# Build images and start all containers
make build

# Check container status
make ps
```

### Accessing the site

Open a browser and navigate to:
```
https://tsilva.42.fr
```

Accept the self-signed certificate warning. WordPress will load on the first visit.

### Stopping the project

```bash
make down    # stop and remove containers
make clean   # full cleanup including images and data
```

## Resources

### Docker & Infrastructure
- [Docker official documentation](https://docs.docker.com/)
- [Docker Compose reference](https://docs.docker.com/compose/compose-file/)
- [Docker secrets documentation](https://docs.docker.com/engine/swarm/secrets/)
- [NGINX documentation](https://nginx.org/en/docs/)
- [MariaDB documentation](https://mariadb.com/kb/en/documentation/)
- [WordPress CLI (WP-CLI)](https://wp-cli.org/)
- [PHP-FPM configuration](https://www.php.net/manual/en/install.fpm.configuration.php)
- [Best practices for writing Dockerfiles](https://docs.docker.com/develop/develop-images/dockerfile_best-practices/)
- [PID 1 and Docker](https://docs.docker.com/reference/dockerfile/#exec-form/best-practices-for-building-containers#signal-handling)
- [TLS protocol overview](https://www.cloudflare.com/learning/ssl/transport-layer-security-tls/)

### 42 / Project specific
- [Alpine vs Debian for Docker base images](https://wiki.alpinelinux.org/wiki/Comparison_with_other_distros)
- [Understanding Docker networking](https://docs.docker.com/network/)
- [Named volumes vs bind mounts](https://docs.docker.com/storage/volumes/)

### Use of Artificial Intelligence

In strict compliance with the AI Instructions outlined in Chapter IV of the subject, Artificial Intelligence was utilized during this project as a tool to reduce repetitive tasks and optimize technical learning. No code was blindly copy-pasted. Instead, AI acted as an interactive assistant, with all generated content being thoroughly questioned, tested, and fully understood before integration.

- **Infrastructure & PID 1 Understanding:** AI was instrumental in researching how daemons work and analyzing best practices for PID 1 in the entrypoint scripts.
- **Debugging** — diagnosing errors in init scripts, volume mount issues, and container startup failures.
- **Documentation** — helping structure and draft this README, USER_DOC, and DEV_DOC according to the subject requirements.
- **Systematic Testing:** — All AI technical explanations and configuration snippets were isolated and validated locally via the command line to ensure precision.
