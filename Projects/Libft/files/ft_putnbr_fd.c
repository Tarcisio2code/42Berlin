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

/*
 * n: The integer to be written.
 * fd: The file descriptor where the integer will be written.
 *
 * This function handles negative numbers and uses recursion to handle multiple digits.
*/
void ft_putnbr_fd(int n, int fd)
{
    // Declare a variable `nbl` of type long to handle edge cases like INT_MIN.
    long nbl;

    // Assign the value of `n` to `nbl`.
    nbl = n;

    // If `nbl` is negative, write a '-' to the file descriptor and make `nbl` positive.
    if (nbl < 0)
    {
        ft_putchar_fd('-', fd);
        nbl = -nbl;
    }

    // If `nbl` has more than one digit, call `ft_putnbr_fd` recursively for the higher-order digits.
    if (nbl > 9)
        ft_putnbr_fd(nbl / 10, fd);

    // Write the least significant digit of `nbl` to the file descriptor.
    ft_putchar_fd(48 + nbl % 10, fd);
}
