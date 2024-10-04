# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 16:00:28 by tsilva            #+#    #+#              #
#    Updated: 2024/04/03 10:53:44 by tsilva           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#librarys name
NAME = pipex
LIBFT_NAME = libft.a

#Directories
OBJECT_DIR = ./obj
LIBFT_DIR = ./libft

#Mandatory source functions
MAND_SOURCES= pipex.c utils.c

#Defines that object files have the same function name
MAND_OBJECTS = $(addprefix $(OBJECT_DIR)/, $(notdir $(MAND_SOURCES:.c=.o)))

## Variables ##
CC = gcc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror

$(OBJECT_DIR)/%.o : %.c
	@${CC} ${CFLAGS} -c $< -o $@

## Targets ##
all: $(OBJECT_DIR) $(NAME)

createlibft:
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT_NAME) .
	@mv $(LIBFT_NAME) $(NAME)

$(NAME): createlibft $(MAND_OBJECTS)
	@echo "Generating library with Mandatory functions..."
	$(CC) $(CFLAGS) $(MAND_OBJECTS) $(LIBFT_DIR)/$(LIBFT_NAME) -o $@

$(OBJECT_DIR):
	@mkdir -p $(OBJECT_DIR)

clean:
	@echo "Cleaning up objects..."
	@rm -rf $(OBJECT_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@echo "Removing library..."
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all
	@echo "Rebuilt library"

.PHONY: all clean fclean re