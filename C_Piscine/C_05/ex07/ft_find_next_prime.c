/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:39:01 by tsilva            #+#    #+#             */
/*   Updated: 2023/08/10 17:05:16 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (0);
	i = 2;
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (!(ft_is_prime(nb)))
		nb++;
	return (nb);
}
/*
#include <stdio.h>
void main()
{
	int number = 8;
	printf("The next prime number of %d is %d\n", number, ft_find_next_prime(number));

	number = 5;
	printf("The next prime number of %d is %d\n", number, ft_find_next_prime(number));

	number = 0;
	printf("The next prime number of %d is %d\n", number, ft_find_next_prime(number));
}
*/