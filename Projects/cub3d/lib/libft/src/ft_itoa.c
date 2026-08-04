/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:40:48 by tsilva            #+#    #+#             */
/*   Updated: 2023/11/28 14:59:10 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	abs_num(long long n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

static int	len_num(int n)
{
	size_t	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	value;
	size_t	size;

	size = len_num(n);
	result = (char *)malloc((size + 1));
	if (!result)
		return (0);
	value = abs_num(n);
	result = result + size;
	*result = '\0';
	while (value)
	{
		*(--result) = 48 + (value % 10);
		value /= 10;
	}
	if (n < 0)
		*(--result) = '-';
	else if (n == 0)
		*(--result) = '0';
	return (result);
}
