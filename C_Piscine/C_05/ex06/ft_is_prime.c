/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:43:09 by tsilva            #+#    #+#             */
/*   Updated: 2023/08/10 16:17:31 by tsilva           ###   ########.fr       */
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

#include <stdio.h>
void main()
{
	int number = 0;
	int result;
	while (number <= 12)
	{
		result = ft_is_prime(number);
		printf("%d is %s (%d)\n", number, (result == 1) ? "prime" : "not prime", result);
		number++;
	}
}