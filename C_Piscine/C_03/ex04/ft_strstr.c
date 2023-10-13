/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:14:04 by tsilva            #+#    #+#             */
/*   Updated: 2023/08/07 12:29:18 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	pos;

	if (!*to_find)
		return (str);
	pos = 0;
	while (*str)
	{
		if (*to_find == *str)
		{
			to_find++;
			if (*to_find == '\0')
				return (str - pos);
			if (*to_find != str[1])
			{
				to_find = to_find - pos;
				pos = 0;
			}
			pos++;
		}
		str++;
	}
	return (0);
}
/* 
#include <stdio.h>
#include <string.h>
int main(void)
{
    char *str = "42BeBerlin";
    char *to_find = "Ber";
    
    printf("test 01\n");
    printf("ft_strstr   : %s\n", ft_strstr(str, to_find));
    printf("strstr      : %s\n", strstr( str, to_find));

    printf("\ntest 02\n");
    to_find = "ber";
    printf("ft_strstr   : %s\n", ft_strstr(str, to_find));
    printf("strstr      : %s\n", strstr( str, to_find));

    printf("\ntest 03\n");
    to_find = "";
    printf("ft_strstr   : %s\n", ft_strstr(str, to_find));
    printf("strstr      : %s\n", strstr( str, to_find));

    printf("\ntest 04\n");
    to_find = " ";
    printf("ft_strstr   : %s\n", ft_strstr(str, to_find));
    printf("strstr      : %s\n", strstr( str, to_find));

    printf("\ntest 05\n");
    str = "";
    to_find = "";
    printf("ft_strstr   : %s\n", ft_strstr(str, to_find));
    printf("strstr      : %s\n", strstr( str, to_find));
}
*/
