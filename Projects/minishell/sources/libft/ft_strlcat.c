/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 20:18:12 by fdunkel           #+#    #+#             */
/*   Updated: 2023/12/06 20:35:49 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	strleny(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	dest_len;
	unsigned int	j;
	unsigned int	stop;
	unsigned int	srclength;

	dest_len = strleny(dest);
	srclength = strleny((char *) src);
	stop = size - dest_len - 1;
	if (size == 0 || size <= dest_len)
		return (size + srclength);
	j = 0;
	while ((src[j] != '\0') && (j < stop))
	{
		dest[dest_len + j] = src[j];
		j++;
	}
	dest[dest_len + j] = '\0';
	return (dest_len + srclength);
}
