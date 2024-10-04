/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:04:25 by tsilva            #+#    #+#             */
/*   Updated: 2023/12/05 13:09:58 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	size_t			pos;
	unsigned char	*str1;
	unsigned char	*str2;

	if (n == 0)
		return (n);
	pos = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((str1[pos] == str2[pos]) && pos < (n - 1) && str1[pos])
		pos++;
	return (str1[pos] - str2[pos]);
}
