/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:55:05 by tsilva            #+#    #+#             */
/*   Updated: 2023/08/10 11:26:29 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	else if (nb == 0 || nb == 1)
		return (1);
	else
		return (ft_recursive_factorial(nb - 1) * nb);
}
/*
#include <stdio.h>
int	main(void)
{
	int nb = 0;

	printf("Factorial %d! -> %d\n", nb, ft_recursive_factorial(nb));

	nb = 1;
	printf("Factorial %d! -> %d\n", nb, ft_recursive_factorial(nb));

	nb = 5;
	printf("Factorial %d! -> %d\n", nb, ft_recursive_factorial(nb));
	
	nb = -1;
	printf("Factorial %d! -> %d\n", nb, ft_recursive_factorial(nb));
}
*/