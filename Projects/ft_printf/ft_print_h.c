/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_h.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:51:15 by tsilva            #+#    #+#             */
/*   Updated: 2024/01/11 12:40:53 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Function to print a number in a specified base, supporting hexadecimal formatting
// Parameters:
//   n - the number to be printed
//   base - the base to convert the number to (e.g., 16 for hexadecimal)
//   c - a character indicating the format ('X' for uppercase, anything else for lowercase)
int	ft_print_h(unsigned long long n, unsigned long long base, char c)
{
	int	count; // Declare an integer to hold the number of characters printed

	count = 0; // Initialize the count to 0

	// If the number is less than the base, it's a single digit in the target base
	if (n < base)
	{
		// If the number is less than 10, it's a decimal digit
		if (n < 10)
			ft_putchar_fd(n + '0', 1); // Print the digit as a character
		else // Otherwise, it's a letter (A-F or a-f) in hexadecimal
		{
			if (c == 'X')
				ft_putchar_fd(n + 'A' - 10, 1); // Print as uppercase letter
			else
				ft_putchar_fd(n + 'a' - 10, 1); // Print as lowercase letter
		}
		return (1); // Return 1 since one character was printed
	}
	else // If the number has more than one digit in the target base
	{
		// Recursively print the higher digits
		count = ft_print_h(n / base, base, c);
		// Recursively print the lower digits and add to the count
		return (count + ft_print_h(n % base, base, c));
	}
}
