/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:18:04 by fdunkel           #+#    #+#             */
/*   Updated: 2023/12/02 21:18:04 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	string_size(int n)
{
	size_t	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static void	helper(char *string, int n, size_t start, size_t size)
{
	while (size > start)
	{
		string[size - 1] = (n % 10) + '0';
		size--;
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*string;
	size_t	start;
	size_t	size;

	start = 0;
	size = string_size(n);
	string = (char *) malloc(size + 1);
	if (!string)
		return (NULL);
	if (n == INT_MIN)
	{
		ft_memcpy(string, "-2147483648", 12);
		return (string);
	}
	if (n < 0)
	{
		string[start++] = '-';
		n *= -1;
	}
	helper(string, n, start, size);
	string[size] = '\0';
	return (string);
}
