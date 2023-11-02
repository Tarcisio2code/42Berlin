/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:05:09 by tsilva            #+#    #+#             */
/*   Updated: 2023/08/10 13:27:46 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;

	if (power < 0)
		return (0);
	result = 1;
	while (power > 0 && power--)
		result *= nb;
	return (result);
}
/*
#include <stdio.h>
int	main(void)
{
	int nb = 2;
	int power = 3;
	printf("%d ^ %d = %d\n", nb, power, ft_iterative_power(nb, power));

	nb = 2;
	power = -1;
	printf("%d ^ %d = %d\n", nb, power, ft_iterative_power(nb, power));

	nb = 0;
	power = 0;
	printf("%d ^ %d = %d\n", nb, power, ft_iterative_power(nb, power));
}
*/