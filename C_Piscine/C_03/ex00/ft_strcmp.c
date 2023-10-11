/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:12:44 by tsilva            #+#    #+#             */
/*   Updated: 2023/08/07 12:17:59 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
/* # include <stdio.h>
int main(void)
{
    
    char *s1;
    char *s2;

    s1 = "Berlin";
    s2 = "Berlin";
    printf("s1 and s2 are equal (%d)\n", ft_strcmp(s1, s2));

    s1 = "Berlin a";
    s2 = "Berlin b";
    printf("s1 is less than s2 (%d)\n", ft_strcmp(s1, s2));

    s1 = "Berlin b";
    s2 = "Berlin a";
    printf("s1 is greater than s2 (%d)\n", ft_strcmp(s1, s2));
} 
*/
