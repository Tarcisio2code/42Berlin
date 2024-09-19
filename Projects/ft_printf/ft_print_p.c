/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:38:51 by tsilva            #+#    #+#             */
/*   Updated: 2024/01/11 12:41:49 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Function to print a pointer in hexadecimal format
// Parameters:
//   p - the pointer value to be printed (as an unsigned long long)
//   base - the base to convert the pointer value to (e.g., 16 for hexadecimal)
int	ft_print_p(unsigned long long p, unsigned long long base)
{
	int	count; // Declare an integer to hold the number of characters printed

	// If the pointer is NULL (0)
	if (!p)
		return (ft_print_s("(null)")); // Print "(nil)" and return the number of characters printed
	else
		count = ft_print_s("0x"); // Print "0x" as the prefix for a hexadecimal value and store the count

	// Print the pointer value in hexadecimal format and add the count of printed characters
	count += ft_print_h(p, base, 'p');

	// Return the total number of characters printed
	return (count);
}

