/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:01:46 by fdunkel           #+#    #+#             */
/*   Updated: 2023/12/02 21:01:46 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned char	search;
	unsigned int	i;
	char			*container;

	i = 0;
	search = c;
	container = NULL;
	while (str[i] != '\0')
	{
		if (str[i] == search)
			container = (char *)&str[i];
		i++;
	}
	if (search == '\0')
		return ((char *) &str[i]);
	return (container);
}
