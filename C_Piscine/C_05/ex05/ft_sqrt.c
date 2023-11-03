/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:35:11 by tsilva            #+#    #+#             */
/*   Updated: 2023/08/10 15:07:25 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	result;

	result = 0;
	while (result <= nb)
	{
		if (result * result == nb)
			return (result);
		result++;
	}
	return (0);
}
/*
#include <stdio.h>
void main()
{
	int number = 1764;
	printf("square root of %d is %d\n", number, ft_sqrt(number));

	number = 2;
	printf("square root of %d is %d\n", number, ft_sqrt(number));
}
*/