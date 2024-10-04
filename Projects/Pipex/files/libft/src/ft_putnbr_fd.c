/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:15:07 by tsilva            #+#    #+#             */
/*   Updated: 2023/12/04 15:37:25 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbl;

	nbl = n;
	if (nbl < 0)
	{
		ft_putchar_fd('-', fd);
		nbl = -nbl;
	}
	if (nbl > 9)
		ft_putnbr_fd(nbl / 10, fd);
	ft_putchar_fd(48 + nbl % 10, fd);
}
