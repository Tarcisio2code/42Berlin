/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:09:58 by tsilva            #+#    #+#             */
/*   Updated: 2023/11/18 18:06:04 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*dup_src;
	int		size;
	int		pos;

	size = 0;
	while (src[size])
		size++;
	dup_src = (char *)malloc(size + 1 * sizeof(char));
	if (!dup_src)
		return (NULL);
	pos = 0;
	while (pos <= size)
	{
		dup_src[pos] = src[pos];
		pos++;
	}
	return (dup_src);
}
