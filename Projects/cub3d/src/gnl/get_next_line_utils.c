/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:07:33 by tsilva            #+#    #+#             */
/*   Updated: 2024/02/26 13:20:40 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	if (!str)
		return (0);
	count = 0;
	while (str[count])
		count++;
	return (count);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	pos;

	if (!dest && !src)
		return (0);
	pos = 0;
	while (pos++ < n)
		((unsigned char *)dest)[pos - 1] = ((unsigned char *)src)[pos - 1];
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_str = (char *)malloc((len1 + len2) + 1);
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, s1, len1);
	ft_memcpy(new_str + len1, s2, len2 + 1);
	return (new_str);
}

int	find_next(char *line)
{
	int	next_pos;

	if (!line)
		return (-1);
	next_pos = 0;
	while (line[next_pos])
		if (line[next_pos++] == '\n')
			return (next_pos - 1);
	return (-1);
}
