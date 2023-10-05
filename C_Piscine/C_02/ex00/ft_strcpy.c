/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:13:19 by tsilva            #+#    #+#             */
/*   Updated: 2023/07/29 14:42:09 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/* 
#include <stdio.h>
#include <string.h>
int main(void)
{
    char src[] = "42 Berlin";
    char dest[10];

 	ft_strcpy(dest, src);
    printf("ft_strcpy: %s\n", dest);

 	strcpy(dest, src);
    printf("strcpy...: %s\n", dest);
}
*/