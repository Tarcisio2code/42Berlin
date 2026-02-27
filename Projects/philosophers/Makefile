# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 23:39:14 by tsilva            #+#    #+#              #
#    Updated: 2024/12/12 17:36:53 by tsilva           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
GREEN 		  = \033[0;32m
YELLOW 		  = \033[0;33m
RED 		  = \033[0;31m
CYAN          = \033[0;36m
GOLD		  = \033[38;5;214m
TEAL	      = \033[38;5;30m
BOLD_GRAY     = \033[1;90m
RESET 		  = \033[0m

NAME = philo

SRC_DIR = ./src
OBJ_DIR = ./obj
INC_DIR = ./inc
MSG_SYS = \033[1;93m[${NAME}]\033[0m

INCLUDES = -I$(INC_DIR)

SOURCES = $(addprefix $(SRC_DIR)/, philo.c utils.c thread.c init.c dinner.c \
									dinner_routine.c dinner_utils.c sets_gets.c)
OBJECTS = $(addprefix $(OBJ_DIR)/, $(notdir $(SOURCES:.c=.o)))

CC = gcc
CFLAGS = -pthread -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "${MSG_SYS} Building the executable..."
	@$(CC) $(CFLAGS) ${INCLUDES} $(OBJECTS) -o $(NAME)
	@echo ""
	@echo "$(BOLD_GRAY)A concurrent programming solution"
	@echo "for the Dining"
	@echo "$(CYAN)               █▀█ █ █ █ █   █▀█ █▀▀ █▀█ █▀█ █ █ █▀▀ █▀█ █▀▀ "
	@echo "               █▀▀ █▀█ █ █   █ █ ▀▀█ █ █ █▀▀ █▀█ █▀▀ █▀▄ ▀▀█ "
	@echo "               ▀   ▀ ▀ ▀ ▀▀▀ ▀▀▀ ▀▀▀ ▀▀▀ ▀   ▀ ▀ ▀▀▀ ▀ ▀ ▀▀▀ $(BOLD_GRAY)problem.\n"
	@echo "$(GREEN)✓ Philosophers system is ready to simulate.\n"
	@echo "$(TEAL)Usage: ./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep]$(RESET)"
	@echo ""

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	@${CC} $(CFLAGS) ${INCLUDES} -c $< -o $@ 

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "${MSG_SYS} Cleaning up objects..."
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "${MSG_SYS} Removing $(NAME) and library..."
	@rm -f $(NAME)

re: fclean all
	@echo "${MSG_SYS} Rebuilding $(NAME)..."

race: fclean
	@make all --no-print-directory CFLAGS="$(CFLAGS) -fsanitize=thread -g"
	@printf "$(GOLD)✓ Recompiled with Thread Sanitizer (-fsanitize=thread)\n${RESET}"
	@echo ""

.PHONY: all clean fclean re

