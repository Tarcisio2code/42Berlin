/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:07:33 by tsilva            #+#    #+#             */
/*   Updated: 2024/02/26 17:05:03 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Header guard to prevent multiple inclusions of this header file.
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// If BUFFER_SIZE is not already defined, set it to 42.
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// Standard library includes:
# include <unistd.h>   // For system calls like read(), write(), close(), etc.
# include <stdlib.h>   // For memory management functions (e.g., malloc, free).
# include <fcntl.h>    // For file control options (e.g., open, close).

// Function prototypes:
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
int		find_next(char *line);
char	*get_next_line(int fd);

#endif
