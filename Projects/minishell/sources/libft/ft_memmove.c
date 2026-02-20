/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:20:20 by fdunkel           #+#    #+#             */
/*   Updated: 2023/12/04 20:03:32 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*new_dest;
	const unsigned char	*new_src;

	new_dest = dest;
	new_src = src;
	if (new_dest == new_src || n == 0)
		return (new_dest);
	if (dest < src)
	{
		while (n--)
			*new_dest++ = *new_src++;
	}
	else
	{
		while (n--)
			new_dest[n] = new_src[n];
	}
	return (dest);
}
