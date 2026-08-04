/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:21:15 by tsilva            #+#    #+#             */
/*   Updated: 2023/12/05 13:28:09 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	const char	*start;

	start = str;
	str = str + ft_strlen(str);
	while (str >= start)
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str--;
	}
	return (0);
}
