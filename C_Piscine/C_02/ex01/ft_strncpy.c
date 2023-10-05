/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 14:42:49 by tsilva            #+#    #+#             */
/*   Updated: 2023/08/01 15:07:26 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
/* 
#include <stdio.h>
#include <string.h>
int main(void)
{
    char src[] = "42 Berlin";
    char dest[10];

    strncpy(dest, src, 4);
    printf("strncpy...: %s\n", dest);

    ft_strncpy(dest, src, 4);
    printf("ft_strncpy: %s\n", dest);
}
*/
