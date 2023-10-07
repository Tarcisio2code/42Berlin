/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 13:57:29 by tsilva            #+#    #+#             */
/*   Updated: 2023/07/29 14:14:10 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
			c = str[i] - 32;
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
    char c[] = "42 bErliN.";

    printf("%s\n", ft_strupcase(c));
}
*/