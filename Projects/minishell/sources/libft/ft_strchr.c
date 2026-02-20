/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:59:20 by fdunkel           #+#    #+#             */
/*   Updated: 2023/12/02 20:59:20 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned int	i;
	unsigned char	search;

	search = (unsigned char) c;
	i = 0;
	while (str[i])
	{
		if (str[i] == search)
			return ((char *) &str[i]);
		i++;
	}
	if (search == '\0')
		return ((char *)&str[i]);
	return (NULL);
}
