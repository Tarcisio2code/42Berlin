/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:51:34 by fdunkel           #+#    #+#             */
/*   Updated: 2023/12/07 14:54:28 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*srcnew;
	unsigned char		*destnew;
	size_t				i;

	if (!dest && !src)
		return (dest);
	i = 0;
	destnew = (unsigned char *)dest;
	srcnew = (unsigned char *)src;
	while (n--)
	{
		destnew[i] = srcnew[i];
		i++;
	}
	return (destnew);
}
