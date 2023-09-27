/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:55:48 by tsilva            #+#    #+#             */
/*   Updated: 2023/07/31 13:35:12 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	if (*b != 0)
	{
		div = *a / *b;
		mod = *a % *b;
		*a = div;
		*b = mod;
	}
}
/*
#include <stdio.h>  

int main(void)
{
    int a = 211;
    int b = 5;

    ft_ultimate_div_mod(&a, &b);
    printf("division: %d, remainder: %d\n", a, b);

}
*/