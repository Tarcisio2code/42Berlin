/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:13:22 by tsilva            #+#    #+#             */
/*   Updated: 2023/08/07 13:54:55 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	if (n == 0)
		return (n);
	n--;
	while (*s1 && (*s1 == *s2) && n--)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
/* 
#include <stdio.h>
#include <string.h>
int main(void)
{
    
    char *s1;
    char *s2;
    int size = 3;

    printf("--- ft_strcmp ---\n");
    s1 = "Berlin";
    s2 = "Ber lin";
    printf("s1 and s2 are equal     (%d)\n", ft_strncmp(s1, s2, size));

    s1 = "abcd";
    s2 = "abdd";
    printf("s1 is less than s2      (%d)\n", ft_strncmp(s1, s2, size));

    s1 = "abdd";
    s2 = "abcd";
    printf("s1 is greater than s2   (%d)\n", ft_strncmp(s1, s2, size));

    printf("\n--- strcmp ---\n");
    s1 = "Berlin";
    s2 = "Ber lin";
    printf("s1 and s2 are equal     (%d)\n", strncmp(s1, s2, size));

    s1 = "abcd";
    s2 = "abdd";
    printf("s1 is less than s2      (%d)\n", strncmp(s1, s2, size));

    s1 = "abdd";
    s2 = "abcd";
    printf("s1 is greater than s2   (%d)\n", strncmp(s1, s2, size));
} 
*/
