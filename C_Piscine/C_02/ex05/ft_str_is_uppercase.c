/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:51:45 by tsilva            #+#    #+#             */
/*   Updated: 2023/07/29 11:51:49 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;
	int	upper;

	i = 0;
	upper = 1;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 65 && str[i] <= 90))
		{
			upper = 0;
			break ;
		}
		i++;
	}
	return (upper);
}
/* 
#include <stdio.h>
int main(void)
{
    char upper[] = "BERLIN";
	char not_upper[] = ".berlin";
    char empty[] = "";

    printf("%d\n", ft_str_is_uppercase(upper));

    printf("%d\n", ft_str_is_uppercase(not_upper));

    printf("%d\n", ft_str_is_uppercase(empty));
} 
*/