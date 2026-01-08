# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/07 23:39:14 by tsilva            #+#    #+#              #
#    Updated: 2024/07/03 20:42:35 by tsilva           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable name
NAME = so_long

# Libraries
LIBFT_NAME = libft.a
MLX_NAME = libmlx_Linux.a

# Directories
SRC_DIR = ./src
OBJ_DIR = ./obj
INC_DIR = ./inc
LIB_DIR = ./lib/libft
MLX_DIR = ./lib/mlx
GNL_DIR = ./gnl

# Message for system output
MSG_SYS = \033[1;93m[${NAME}]\033[0m

# Include directories and optimization flags
INCLUDES = -I/usr/include -O3 -I.. -I$(INC_DIR)

# Source files and object files
SOURCES = $(addprefix $(SRC_DIR)/, so_long.c game_init.c map.c map_test.c\
			so_long_utils.c game_start.c key_control.c game_utils.c)
GNL_SRC = $(addprefix $(GNL_DIR)/, get_next_line.c get_next_line_utils.c)
OBJECTS = $(addprefix $(OBJ_DIR)/, $(notdir $(SOURCES:.c=.o) $(GNL_SRC:.c=.o)))

# Compiler and flags
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
MLX_FLAGS = -L ./lib/mlx -lmlx -lXext -lX11

# Default target
all: $(NAME)

# Build the final executable
$(NAME): $(LIB_DIR)/$(LIBFT_NAME) $(MLX_DIR)/$(MLX_NAME) $(OBJECTS)
	@echo "${MSG_SYS} Building the $(NAME) executable..."
	@$(CC) $(CFLAGS) ${INCLUDES} $(OBJECTS) $(LIB_DIR)/$(LIBFT_NAME) -o $(NAME) $(MLX_FLAGS) 

# Compile source files into object files
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	@${CC} $(CFLAGS) ${INCLUDES} -c -o $@ $<

# Compile GNL source files into object files
$(OBJ_DIR)/%.o : $(GNL_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

# Create the object directory if it doesn't exist
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Build the libft library
$(LIB_DIR)/$(LIBFT_NAME):
	@make -s -C $(LIB_DIR) bonus

# Build the MLX library
$(MLX_DIR)/$(MLX_NAME):
	@make -s -C $(MLX_DIR)

# Clean up object files
clean:
	@echo "${MSG_SYS} Cleaning up objects..."
	@make -s -C $(LIB_DIR) clean
	@rm -rf $(OBJ_DIR)
	@make -s -C $(MLX_DIR) clean

# Clean up object files and the final executable
fclean: clean
	@echo "${MSG_SYS} Removing $(NAME) and library..."
	@rm -f $(NAME)
	@rm -f $(LIB_DIR)/$(LIBFT_NAME)

# Rebuild the project
re: fclean all
	@echo "${MSG_SYS} Rebuilding $(NAME)..."

# Declare phony targets
.PHONY: all clean fclean re