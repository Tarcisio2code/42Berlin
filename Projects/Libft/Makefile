# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 10:08:14 by tsilva            #+#    #+#              #
#    Updated: 2023/12/12 14:37:05 by tsilva           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### Variables ###

#Defines the name of the library
NAME = libft.a 

#Defines mandatory source functions
MAND_SOURCES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
			ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
			ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
			ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \

#Defines bonus source functions
BONUS_SOURCES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c

#Defines that object files have the same function name
#The '$' symbol is used for variable assignment
MAND_OBJECTS = $(MAND_SOURCES:.c=.o)

BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

#Defines the compiler and the flags to be used 
CC = gcc

CFLAGS = -Wall -Wextra -Werror

#Pattern rule for generating .o files from corresponding .c files
%.o : %.c
   #'-c' This flag tells the compiler to generate object files
   #'$<' This flag refers to the source file from which the target (.o file) should be built
   #'-o' is the flag used to specify the output file
   #'$@' ensures that the output file has the same same name as the source file
	${CC} ${CFLAGS} -c $< -o $@

### Targets ###

#The default target that gets built when you run make without specifying a target
all: $(NAME) 

#Builds the library using mandatory objects
$(NAME): $(MAND_OBJECTS)
   #The '@' symbol at the beginning prevents echoing the command itself to the console.
	@echo "Generating library with Mandatory functions..."
   #Creates the library using the ar command with options rcs
   #'r' Inserts or replaces the specified files into the library archive
   #'c' Create the archive if it doesn't exist
   #'s' Write an index into the archive, or update an existing index
	ar rcs $(NAME) $(MAND_OBJECTS)
   #Generate an index in the library file
	ranlib $(NAME) 

#Performs a similar operation as $(NAME) but includes bonus functions as well
bonus: $(MAND_OBJECTS) $(BONUS_OBJECTS) libft.h
	@echo "Generating library with Mandatory and Bonus functions..."
	ar rcs $(NAME) $(MAND_OBJECTS) $(BONUS_OBJECTS)
	ranlib $(NAME)

#Removes the object files using rm command with options rcs -f
clean:
	@echo "Cleaning up objects..."
	rm -f $(MAND_OBJECTS) $(BONUS_OBJECTS) 

#Removes the library file and invokes clean to remove object files
fclean: clean
	@echo "Removing library..."
   #'-f' flag ensures it doesn't prompt for confirmation and forcefully removes the files.
	rm -f $(NAME)

#Rebuilds the library by cleaning (fclean) and then rebuilding ($(NAME))
re: fclean $(NAME)
	@echo "Rebuilt library"

#This target prevents implicit rules from trying to build an executable with these names
.PHONY: all bonus clean fclean re 
 
