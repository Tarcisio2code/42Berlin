# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 16:00:28 by tsilva            #+#    #+#              #
#    Updated: 2024/01/17 08:52:18 by tsilva           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#librarys name
NAME = libftprintf.a
LIBFT_NAME = libft.a

#Directories
OBJECT_DIR = ./obj
LIBFT_DIR = ./libft

#Mandatory source functions
MAND_SOURCES= ft_printf.c ft_print_c.c ft_print_d.c ft_print_h.c ft_print_p.c ft_print_s.c

#Defines that object files have the same function name
MAND_OBJECTS = $(addprefix $(OBJECT_DIR)/, $(notdir $(MAND_SOURCES:.c=.o)))

## Variables for the compiler and archiver ##
CC = gcc
AR = ar rcs

# Compiler flags to enable all warnings and treat them as errors
CFLAGS = -Wall -Wextra -Werror

# Rule to compile C source files into object files
$(OBJECT_DIR)/%.o : %.c
   	#'-c' This flag tells the compiler to generate object files
   	#'$<' This flag refers to the source file from which the target (.o file) should be built
   	#'-o' is the flag used to specify the output file
   	#'$@' ensures that the output file has the same same name as the source file
	@${CC} ${CFLAGS} -c $< -o $@

## Targets ##
all: $(OBJECT_DIR) $(NAME)

createlibft:
	# Change directory to LIBFT_DIR and run make
	@make -C $(LIBFT_DIR)
	# Copy the created Libft library to the current directory
	@cp $(LIBFT_DIR)/$(LIBFT_NAME) .
	# Rename the copied Libft library to the name specified by NAME
	@mv $(LIBFT_NAME) $(NAME)

# Target to create the main library
$(NAME): createlibft $(OBJECT_DIR) $(MAND_OBJECTS)
	@echo "Generating library with Mandatory functions..."
	$(AR) $(NAME) $(MAND_OBJECTS)

# Target to create the object directory if it does not exist
$(OBJECT_DIR):
	@mkdir -p $(OBJECT_DIR)

clean:
	@echo "Cleaning up objects..."
	# Remove the object directory and its contents
	@rm -rf $(OBJECT_DIR)
	# Run make clean in the Libft directory
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@echo "Removing library..."
	# Remove the main library file
	@rm -f $(NAME)
	# Run make fclean in the Libft directory
	@make -C $(LIBFT_DIR) fclean

# Target to forcefully rebuild everything
re: fclean all
	@echo "Rebuilt library"

# Declares targets that do not correspond to file names
.PHONY: all clean fclean re
