/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 09:37:05 by tsilva            #+#    #+#             */
/*   Updated: 2023/08/10 10:06:29 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	if (nb < 0)
		return (0);
	result = 1;
	while (nb > 1)
	{
		result *= nb;
		--nb;
	}
	return (result);
}
/*
#include <stdio.h>
int	main(void)
{
	int nb = 0;

	printf("Factorial %d! -> %d\n", nb, ft_iterative_factorial(nb));

	nb = 1;
	printf("Factorial %d! -> %d\n", nb, ft_iterative_factorial(nb));

	nb = 5;
	printf("Factorial %d! -> %d\n", nb, ft_iterative_factorial(nb));
	
	nb = -1;
	printf("Factorial %d! -> %d\n", nb, ft_iterative_factorial(nb));
}
*/