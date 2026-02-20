/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:46:37 by fdunkel           #+#    #+#             */
/*   Updated: 2023/12/10 16:52:43 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *) big);
	if (!len)
		return (NULL);
	while (big[i] && i < len)
	{
		j = 0;
		while ((big[i + j] == little[j]) && (big[i + j] != '\0')
			&& (i + j < len))
			j++;
		if (!little[j])
			return ((char *) &big[i]);
		i++;
	}
	return (NULL);
}
