/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 10:54:39 by tsilva            #+#    #+#             */
/*   Updated: 2023/07/29 15:22:02 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_numeric(char *str)
{
	int	i;
	int	digit;

	i = 0;
	digit = 1;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 48 && str[i] <= 57))
		{
			digit = 0;
			break ;
		}
		i++;
	}
	return (digit);
}
/* 
#include <stdio.h>
int main(void)
{
    char digits[] = "42";
	char not_digits[] = "berlin";
    char empty[] = "";

    printf("%d\n", ft_str_is_numeric(digits));

    printf("%d\n", ft_str_is_numeric(not_digits));

    printf("%d\n", ft_str_is_numeric(empty));
} 
*/