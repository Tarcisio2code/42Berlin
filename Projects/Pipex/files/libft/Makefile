# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 10:08:14 by tsilva            #+#    #+#              #
#    Updated: 2024/04/06 19:18:41 by tsilva           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#library name
NAME = libft.a

#Directories
SOURCE_DIR = ./src
OBJECT_DIR = ./obj
B_OBJ_DIR = ./b_obj

#Mandatory source functions
SOURCES= $(addprefix $(SOURCE_DIR)/, ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
			ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
			ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
			ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c \
			ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c)

B_SRC = $(addprefix $(SOURCE_DIR)/, ft_lstiter.c ft_lstmap.c)

#Defines that object files have the same function name
# '$'		: symbol used for variable assignment
# .c=.o		: Substitutes the .c extension of each source file with .o, creating a list of corresponding object file names.
# notdir	: Extracts the base file names from the list of object file names.
# addprefix : Adds the $(OBJECT_DIR)/ prefix to each object file name.
OBJECTS = $(addprefix $(OBJECT_DIR)/, $(notdir $(SOURCES:.c=.o)))

b_OBJ = $(addprefix $(B_OBJ_DIR)/, $(notdir $(B_SRC:.c=.o)))

#Compiler and compiler flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

#Rule to compile each source file into an object file
# %.o : %.c : Specifies a pattern rule where each %.c file is compiled into a corresponding %.o file in the $(OBJECT_DIR) directory
# | 		: ensures that $(OBJECT_DIR) is created before attempting to compile any .o files
# @ 		: Suppresses the command from being echoed to the terminal
# -c 		: Indicates compilation without linking
# $<		: Is the input file (source file)
# -o $@ 	: Specifies the output file (object file)
$(OBJECT_DIR)/%.o : $(SOURCE_DIR)/%.c | $(OBJECT_DIR)
	@${CC} ${CFLAGS} -c $< -o $@

$(B_OBJ_DIR)/%.o : $(SOURCE_DIR)/%.c | $(B_OBJ_DIR)
	@${CC} ${CFLAGS} -c $< -o $@

## Targets ##
#Default target: build the executable
all: $(NAME)

#Target to build the library
# ar rcs	: Creates the static library $(NAME) by archiving the object files listed in $(OBJECTS)
$(NAME): $(OBJECTS)
	@echo "Generating library $(NAME)..."
	@ar rcs $(NAME) $(OBJECTS)

#Target to create the object directory
# -p		: Creates the directory
$(OBJECT_DIR):
	@mkdir -p $(OBJECT_DIR)

$(B_OBJ_DIR):
	@mkdir -p $(B_OBJ_DIR)

bonus: $(NAME) $(b_OBJ) | $(B_OBJ_DIR)
	@ar rcs $(NAME) $(b_OBJ)

#Target to clean up object files
# -rf		: Removes the directory and all its contents recursively, forcefully
clean:
	@echo "Cleaning up library objects..."
	@rm -rf $(OBJECT_DIR)
	@rm -rf $(B_OBJ_DIR)
	

#Target to clean up object files and the library
# -f		: Removes the file forcefully
fclean: clean
	@echo "Removing library $(NAME)..."
	@rm -f $(NAME)

#Target to clean and rebuild the library
re: fclean all
	@echo "Rebuilding $(NAME)..."

# Declares these targets as phony targets to ensure they are always executed
.PHONY: all bonus clean fclean re
