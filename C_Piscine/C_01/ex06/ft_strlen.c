/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:33:47 by tsilva            #+#    #+#             */
/*   Updated: 2023/07/27 17:34:13 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
/* 
#include <stdio.h>

int main(void)
{
    char *a;
    int total;
    a = "42Berlin is a great good place to learn :)";
    total = ft_strlen(a);
    printf("Number of characters: %d\n", total);
} 
*/
