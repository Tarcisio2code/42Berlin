/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:00:14 by tsilva            #+#    #+#             */
/*   Updated: 2023/12/08 15:17:40 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	pos;
	char	*str;

	pos = 0;
	str = (char *)s;
	while (pos < n)
	{
		if ((unsigned char)str[pos] == (unsigned char)c)
			return ((char *)s + pos);
		pos++;
	}
	return (0);
}
