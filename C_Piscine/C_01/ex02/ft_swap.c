/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:57:00 by tsilva            #+#    #+#             */
/*   Updated: 2023/07/27 14:59:27 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	i;

	i = *a;
	*a = *b;
	*b = i;
}
/* 
#include <stdio.h>

int 	main(void)
{
	int a = 2;
	int b = 4; 

	printf("Before: a = %d, b = %d\n", a,b);
	ft_swap(&a, &b);
	printf("After: a = %d, b = %d\n", a,b);
} */
