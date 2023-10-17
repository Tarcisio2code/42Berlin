/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:38:04 by tsilva            #+#    #+#             */
/*   Updated: 2023/08/10 11:12:47 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	nbl = nb;
	
	if (nbl < 0)
	{
		ft_putchar('-');
		nbl = -nbl;
	}
	if (nbl > 9)
		ft_putnbr(nbl / 10);
	ft_putchar(48 + nbl % 10);
}
/* 
int main (void)
{
	int nb;

	nb  = 0;
	ft_putnbr(nb);
	write(1, "\n", 1);
	
	nb  = 42;
	ft_putnbr(nb);
	write(1, "\n", 1);

	nb  = -42;
	ft_putnbr(nb);
	write(1, "\n", 1);

	nb  = 2147483647;
	ft_putnbr(nb);
	write(1, "\n", 1);
	
	nb  = -2147483648;
	ft_putnbr(nb);
	write(1, "\n", 1);
}
*/
