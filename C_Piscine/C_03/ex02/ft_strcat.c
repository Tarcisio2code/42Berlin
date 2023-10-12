/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:13:38 by tsilva            #+#    #+#             */
/*   Updated: 2023/08/07 12:23:06 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*temp;

	temp = dest;
	while (*temp)
		temp++;
	while (*src)
	{
		*temp = *src;
		src++;
		temp++;
	}
	*temp = '\0';
	return (dest);
}
/* 
#include <stdio.h>
#include <string.h>

int main(void)
{
    char src[] = "Berlin";
    char dest[] = "42 ";
    printf("ft_strcat: %s\n", ft_strcat(dest, src));

    char src1[] = "Berlin";
    char dest1[] = "42 ";
    printf("strcat: %s\n", strcat(dest1, src1));

}
*/
