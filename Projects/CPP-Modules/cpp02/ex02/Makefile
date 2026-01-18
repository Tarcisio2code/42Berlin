# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 20:43:40 by tsilva            #+#    #+#              #
#    Updated: 2025/04/10 20:44:02 by tsilva           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

SRC_DIR = ./sources
INC_DIR = ./includes
OBJ_DIR = ./obj

MSG_SYS = \033[1;93m[${NAME}]\033[0m

SOURCES = $(addprefix $(SRC_DIR)/, main.cpp Fixed.cpp)
INCLUDES = -I$(INC_DIR)
OBJECTS = $(addprefix $(OBJ_DIR)/, $(notdir $(SOURCES:.cpp=.o)))

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "${MSG_SYS} Building the $(NAME) executable..."
	$(CC) $(CFLAGS) ${INCLUDES} $(OBJECTS) -o $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@${CC} $(CFLAGS) ${INCLUDES} -c -o $@ $<

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
