/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:12:48 by tsilva            #+#    #+#             */
/*   Updated: 2023/08/10 14:25:01 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	else
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
/*
#include <stdio.h>
int	main(void)
{
	int index = 10;
	printf("%d\n", ft_fibonacci(index));

	index = -1;
	printf("%d\n", ft_fibonacci(index));

	index = 0;
	printf("%d\n", ft_fibonacci(index));

	index = 1;
	printf("%d\n", ft_fibonacci(index));
}
*/