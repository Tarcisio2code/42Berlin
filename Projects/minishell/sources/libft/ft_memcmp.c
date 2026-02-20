/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:36:27 by fdunkel           #+#    #+#             */
/*   Updated: 2023/12/04 19:45:55 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1ptr;
	unsigned char	*s2ptr;

	s1ptr = (unsigned char *) s1;
	s2ptr = (unsigned char *) s2;
	while (n--)
	{
		if (*s1ptr++ != *s2ptr++)
			return (*--s1ptr - *--s2ptr);
	}
	return (0);
}
