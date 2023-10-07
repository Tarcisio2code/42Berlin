/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 14:25:57 by tsilva            #+#    #+#             */
/*   Updated: 2023/07/29 14:26:00 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			c = str[i] + 32;
			str[i] = c;
		}
		i++;
	}
	return (str);
}
/* 
#include <stdio.h>
int main(void)
{
    char c[] = "42 BerLiN.";

    printf("%s\n", ft_strlowcase(c));
}
*/