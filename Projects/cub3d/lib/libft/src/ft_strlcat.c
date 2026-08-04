/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:18:54 by tsilva            #+#    #+#             */
/*   Updated: 2023/12/05 16:12:17 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	count;
	size_t	dst_size;
	size_t	src_size;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (size <= 0)
		return (src_size);
	count = 0;
	while (dst_size + count < size - 1 && src[count])
	{
		dst[dst_size + count] = src[count];
		count++;
	}
	dst[dst_size + count] = '\0';
	if (size > dst_size)
		return (dst_size + src_size);
	else
		return (src_size + size);
}
