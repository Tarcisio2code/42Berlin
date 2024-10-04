/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:16:26 by tsilva            #+#    #+#             */
/*   Updated: 2023/12/05 15:13:51 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		pos;
	int		size;

	str = (char *)s;
	size = ft_strlen(str);
	pos = 0;
	while (pos <= size)
	{
		if (str[pos] == (unsigned char)c)
			return (&str[pos]);
		pos++;
	}
	return (0);
}
