/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:13:41 by fdunkel           #+#    #+#             */
/*   Updated: 2023/11/15 13:13:41 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int ch, size_t count )
{
	size_t			i;
	unsigned char	*newdest;

	newdest = (unsigned char *)dest;
	i = -1;
	while (++i < count)
		newdest[i] = ch;
	return (newdest);
}
