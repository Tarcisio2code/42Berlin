/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:43:09 by tsilva            #+#    #+#             */
/*   Updated: 2023/08/10 14:07:03 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		return (ft_recursive_power(nb, power - 1) * nb);
}
/*
#include <stdio.h>
int	main(void)
{
	int nb = 10;
	int power = 3;
	printf("%d ^ %d = %d\n", nb, power, ft_recursive_power(nb, power));

	nb = 2;
	power = -1;
	printf("%d ^ %d = %d\n", nb, power, ft_recursive_power(nb, power));

	nb = 0;
	power = 0;
	printf("%d ^ %d = %d\n", nb, power, ft_recursive_power(nb, power));
}
*/