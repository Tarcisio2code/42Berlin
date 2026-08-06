NAME = inception

DATA_PATH = /home/tsilva/data
DB_PATH = $(DATA_PATH)/mariadb
WP_PATH = $(DATA_PATH)/wordpress

DOCKER_COMPOSE = docker compose -f srcs/docker-compose.yml

all: up

build:
	@mkdir -p $(DB_PATH)
	@mkdir -p $(WP_PATH) 
	@$(DOCKER_COMPOSE) up --build -d

up:
	@$(DOCKER_COMPOSE) up -d

down:
	@$(DOCKER_COMPOSE) down

ps:
	@$(DOCKER_COMPOSE) ps

volume:
	docker volume ls

image:
	docker image ls

clean:
	@$(DOCKER_COMPOSE) down --rmi all

fclean: clean
	@$(DOCKER_COMPOSE) down -v --rmi all
	@docker system prune -f
	sudo rm -rf /home/tsilva/data/wordpress
	sudo rm -rf /home/tsilva/data/mariadb

re: fclean build

.PHONY: all build up down ps volume image clean fclean re
