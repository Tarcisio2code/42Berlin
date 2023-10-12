/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:13:49 by tsilva            #+#    #+#             */
/*   Updated: 2023/08/07 12:25:15 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*temp;

	temp = dest;
	while (*temp)
		temp++;
	while (*src && nb--)
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
    printf("ft_strncat: %s\n", ft_strncat(dest, src, 3));

    char src1[] = "Berlin";
    char dest1[] = "42 ";
    printf("strncat: %s\n", strncat(dest1, src1, 3));
} 
*/
