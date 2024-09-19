/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 10:39:36 by tsilva            #+#    #+#             */
/*   Updated: 2024/01/11 12:38:12 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Takes an integer 'c' which represents the character to be printed
int	ft_print_c(int c)
{
	// Call the function 'ft_putchar_fd' to print the character 'c' to the standard output
	ft_putchar_fd(c, 1);

	// Return 1 to indicate that one character has been printed
	return (1);
}
