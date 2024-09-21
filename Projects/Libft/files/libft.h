/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:39:51 by tsilva            #+#    #+#             */
/*   Updated: 2023/12/12 15:55:33 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//The  #ifndef and #endif Header Guards ensure that the file's content
//is only included once
#ifndef LIBFT_H

//Use the #define preprocessor directive  to create a macro named LIBFT_H.
# define LIBFT_H

//Use include Statements to provide functionality from multiple standard C libraries
#include <unistd.h>   // For system-level I/O functions (e.g., write, read) used in file descriptor functions.
#include <stdlib.h>   // For memory management functions (e.g., malloc, free) and utilities like atoi.
#include <stddef.h>   // For defining types like size_t and NULL used in pointer and memory handling.

//Defines a custom data structure that represents a basic linked list node
typedef struct s_list
{
	//Declares a pointer for content
	void			*content;

	//Declares a pointer to the next node of the list.
	struct s_list	*next;
}	t_list;

//Declares prototypes for functions

//String Manipulation:
int	ft_atoi(const char *str);
char *ft_itoa(int n);
char **ft_split(char const *s, char c);
char *ft_strchr(const char *s, int c);
char *ft_strdup(char *src);
void ft_striteri(char *s, void (*f)(unsigned int, char*));
char *ft_strjoin(char const *s1, char const *s2);
size_t ft_strlcat(char *dst, const char *src, size_t size);
size_t ft_strlcpy(char *dst, const char *src, size_t size);
size_t ft_strlen(const char *str);
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
int ft_strncmp(char *s1, char *s2, unsigned int n);
void *ft_strnstr(const char *big, const char *little, size_t len);
char *ft_strrchr(char *str, int c);
char *ft_strtrim(char const *s1, char const *set);
char *ft_substr(char const *s, unsigned int start, size_t len);

//Memory Manipulation:
void ft_bzero(void *s, size_t n);
void *ft_calloc(size_t nmemb, size_t size);
void *ft_memchr(const void *s, int c, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);
void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_memmove(void *dest, const void *src, size_t n);
void *ft_memset(void *ptr, int x, size_t n);

//Character Handling:
int ft_isalnum(int c);
int ft_isalpha(int c);
int ft_isascii(int c);
int ft_isdigit(int c);
int ft_isprint(int c);
int ft_toupper(int ch);
int ft_tolower(int ch);

//File Descriptor Output:
void ft_putchar_fd(char c, int fd);
void ft_putendl_fd(char *s, int fd);
void ft_putnbr_fd(int n, int fd);
void ft_putstr_fd(char *s, int fd);

//Linked List Manipulation (Bonus part):
t_list *ft_lstnew(void *content);
void ft_lstadd_front(t_list **lst, t_list *new);
int ft_lstsize(t_list *lst);
t_list *ft_lstlast(t_list *lst);
void ft_lstadd_back(t_list **lst, t_list *new);
void ft_lstdelone(t_list *lst, void (*del)(void*));
void ft_lstclear(t_list **lst, void (*del)(void*));
void ft_lstiter(t_list *lst, void (*f)(void *));
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
