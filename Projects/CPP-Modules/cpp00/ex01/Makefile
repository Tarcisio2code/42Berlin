# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 13:39:14 by tsilva            #+#    #+#              #
#    Updated: 2025/03/11 17:58:58 by tsilva           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = awesome_phonebook

SRC_DIR = .
OBJ_DIR = ./obj

MSG_SYS = \033[1;93m[${NAME}]\033[0m

SOURCES = $(addprefix $(SRC_DIR)/, main.cpp PhoneBook.cpp)
OBJECTS = $(addprefix $(OBJ_DIR)/, $(notdir $(SOURCES:.cpp=.o)))

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "${MSG_SYS} Building the executable..."
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp PhoneBook.hpp | $(OBJ_DIR)
	@${CC} $(CFLAGS) -c -o $@ $<

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "${MSG_SYS} Cleaning up objects..."
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "${MSG_SYS} Removing $(NAME)..."
	@rm -f $(NAME)

re: fclean all
	@echo "${MSG_SYS} Rebuilding $(NAME)..."

.PHONY: all clean fclean re
