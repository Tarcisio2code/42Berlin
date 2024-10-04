/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:34:23 by tsilva            #+#    #+#             */
/*   Updated: 2023/12/10 11:55:35 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_trimspaces(char *str)
{
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	return (str);
}

static int	get_numbers(char *src, int is_even)
{
	int	n;

	n = 0;
	while (*src >= 48 && *src <= 57)
	{
		n = n * 10 + (*src - 48);
		src++;
	}
	if (is_even)
		return (-n);
	return (n);
}

int	ft_atoi(const char *str)
{
	char	*src;
	int		is_even;
	int		result;

	src = ft_trimspaces((char *)str);
	is_even = 0;
	result = 0;
	if ((*src == '+' || *src == '-') && *src++ == '-')
		is_even++;
	if (*src && ft_isdigit(*src))
		result = get_numbers(src, is_even);
	return (result);
}
