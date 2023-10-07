/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:40:03 by tsilva            #+#    #+#             */
/*   Updated: 2023/07/29 11:42:26 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;
	int	lower;

	i = 0;
	lower = 1;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 97 && str[i] <= 122))
		{
			lower = 0;
			break ;
		}
		i++;
	}
	return (lower);
}
/*  
#include <stdio.h>
int main(void)
{
    char lower[] = "berlin";
	char not_lower[] = "Berlin.";
    char empty[] = "";

    printf("%d\n", ft_str_is_lowercase(lower));

    printf("%d\n", ft_str_is_lowercase(not_lower));

    printf("%d\n", ft_str_is_lowercase(empty));
} 
*/