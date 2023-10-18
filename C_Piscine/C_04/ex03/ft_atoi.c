/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:52:46 by tsilva            #+#    #+#             */
/*   Updated: 2023/08/09 13:09:55 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_trimspaces(char *str)
{
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	return (str);
}

int	ft_countminus(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == '-')
			count++;
		str++;
	}
	return (count % 2);
}

char	*ft_trimsigns(char *str)
{
	while (*str == '-' || *str == '+')
		str++;
	return (str);
}

int	ft_getnumbers(char *src, int is_even)
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

int	ft_atoi(char *str)
{
	char	*src;
	int		is_even;
	int		result;

	src = ft_trimspaces(str);
	is_even = ft_countminus(src);
	src = ft_trimsigns(src);
	result = ft_getnumbers(src, is_even);
	return (result);
}
/*
#include <stdio.h>
int main(void)
{
    char *str;
    str = " ---+--+1234ab567";
    printf("%d\n", ft_atoi(str));

    str = "     ---+-+1234ab567";
    printf("%d", ft_atoi(str));
}
*/
/* spaces...
9    '\t' (horizontal tab)
10   '\n' (new line)      
11   '\v' (vertical tab)  
12   '\f' (form feed)     
13   '\r' (carriage ret) 
32   SPACE 
*/
