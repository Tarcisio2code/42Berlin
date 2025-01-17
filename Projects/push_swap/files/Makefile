# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 18:14:31 by tsilva            #+#    #+#              #
#    Updated: 2024/05/04 22:51:20 by tsilva           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT_NAME = libft.a

SOURCE_DIR = ./src
OBJECT_DIR = ./obj
LIBFT_DIR = ./libft
INC_DIR	= ./include
MSG_SYS = \033[1;93m[${NAME}]\033[0m

SOURCES= $(addprefix $(SOURCE_DIR)/, push_swap.c push_swap_utils.c free_mem.c \
									ft_atoi_long.c stack.c stack_utils.c swap.c \
									rotate.c rotate_reverse.c push.c \
									super_sort.c super_sort_utils.c)

OBJECTS = $(addprefix $(OBJECT_DIR)/, $(notdir $(SOURCES:.c=.o)))

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT_DIR)/$(LIBFT_NAME) $(OBJECTS) ${INC_DIR}
	@echo "${MSG_SYS} Building the $(NAME) executable..."
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_DIR)/$(LIBFT_NAME) -o $@

$(OBJECT_DIR)/%.o : $(SOURCE_DIR)/%.c | $(OBJECT_DIR)
	@${CC} ${CFLAGS} -c $< -o $@

$(OBJECT_DIR):
	@mkdir -p $(OBJECT_DIR)

$(LIBFT_DIR)/$(LIBFT_NAME):
	@make -s -C $(LIBFT_DIR) bonus

clean:
	@make -s -C $(LIBFT_DIR) clean
	@echo "${MSG_SYS} Cleaning up objects..."
	@rm -rf $(OBJECT_DIR)

fclean: clean
	@echo "${MSG_SYS} Removing $(NAME) and library..."
	@rm -f $(NAME)
	@rm -f $(LIBFT_DIR)/$(LIBFT_NAME)

re: fclean all
	@echo "${MSG_SYS} Rebuilding $(NAME)..."

.PHONY: all clean fclean re
