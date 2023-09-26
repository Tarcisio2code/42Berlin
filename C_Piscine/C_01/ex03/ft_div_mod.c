/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:55:48 by tsilva            #+#    #+#             */
/*   Updated: 2023/07/31 11:52:08 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	int	r1;
	int	r2;

	if (b != 0)
	{
		r1 = a / b;
		r2 = a % b;
		*div = r1;
		*mod = r2;
	}
}
/* 
#include <stdio.h>

int main(void)
{
    int a = 211;
    int b = 5;
	int div = 0;
	int mod = 0;

    ft_div_mod(a, b, &div, &mod);
    printf("division = %d, remainder = %d\n", div, mod);
}
*/