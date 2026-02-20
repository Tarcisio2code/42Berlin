/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:09:29 by fdunkel           #+#    #+#             */
/*   Updated: 2023/12/06 20:36:13 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			length;
	char			*retstr;
	unsigned int	index;

	length = ft_strlen(s);
	retstr = (char *) malloc(length + 1);
	index = 0;
	if (!retstr)
		return (NULL);
	while (index < length)
	{
		retstr[index] = (*f)(index, s[index]);
		index++;
	}
	retstr[index] = '\0';
	return (retstr);
}
