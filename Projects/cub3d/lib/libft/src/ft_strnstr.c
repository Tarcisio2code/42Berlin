/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:05:28 by tsilva            #+#    #+#             */
/*   Updated: 2023/12/10 11:46:33 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_strnstr(char const *big, char const *little, size_t len)
{
	size_t	count;

	if (!big && !len)
		return (0);
	if (!*little)
		return ((char *)big);
	while (*big && len--)
	{
		count = 0;
		while (*(big + count) == *(little + count)
			&& *(little + count) && count <= len)
		{
			if (!*(little + count + 1))
				return ((char *)big);
			count++;
		}
		big++;
	}
	return (0);
}
