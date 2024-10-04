/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:00:36 by tsilva            #+#    #+#             */
/*   Updated: 2023/12/10 11:47:07 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	pos;

	if (!dest && !src)
		return (0);
	pos = 0;
	while (pos < n)
	{
		((unsigned char *)dest)[pos] = ((unsigned char *)src)[pos];
		pos++;
	}
	return (dest);
}
