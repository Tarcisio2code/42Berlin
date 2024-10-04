/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:29:18 by tsilva            #+#    #+#             */
/*   Updated: 2023/12/04 14:55:25 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			pos;
	unsigned char	*str1;
	unsigned char	*str2;

	pos = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (pos < n)
	{
		if (!(str1[pos] == str2[pos]))
			return (str1[pos] - str2[pos]);
		pos++;
	}
	return (0);
}
