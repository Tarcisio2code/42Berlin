# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/20 19:52:54 by fdunkel           #+#    #+#              #
#    Updated: 2024/11/06 11:34:18 by fdunkel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
RM = rm -f
CFLAGS = -g -Wall -Wextra -Werror
AR = ar rcs
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
    ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
    ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
    ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
    ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
    ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
    ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
    ft_lstadd_back.c ft_lstadd_front.c ft_lstnew.c ft_list_del_first.c \
    ft_lstclear.c ft_lstdelone.c

OBJS =  $(SRC:.c=.o)

all: $(NAME)

.o:.c
	$(CC) $(CFLAGS)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
