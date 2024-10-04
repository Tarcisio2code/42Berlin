/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:41:02 by tsilva            #+#    #+#             */
/*   Updated: 2023/11/14 15:13:18 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int x, size_t n)
{
	size_t			count;
	unsigned char	*src;

	count = 0;
	src = (unsigned char *)ptr;
	while (count < n)
	{
		src[count] = (unsigned char)x;
		count++;
	}
	return (ptr);
}
