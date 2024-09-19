/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:31:34 by tsilva            #+#    #+#             */
/*   Updated: 2024/01/11 12:43:43 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Static function to print different types of arguments based on the format specifier
// Parameters:
//   c - the format specifier character
//   ap - the list of arguments
// Returns the number of characters printed or -1 if an invalid format specifier is provided
static int	print_args(char c, va_list ap)
{
	int	count; // Declare an integer to hold the number of characters printed

	count = 0; // Initialize count to 0

	// Check the format specifier and call the corresponding print function
	if (c == 'c')
		count += ft_print_c(va_arg(ap, int)); // Print a character
	else if (c == 's')
		count += ft_print_s(va_arg(ap, char *)); // Print a string
	else if (c == 'd' || c == 'i')
		count += ft_print_d(va_arg(ap, int)); // Print an integer (decimal or integer format)
	else if (ft_tolower(c) == 'x')
		count += ft_print_h(va_arg(ap, unsigned int), 16, c); // Print a hexadecimal number (lowercase or uppercase)
	else if (c == 'p')
		count += ft_print_p(va_arg(ap, unsigned long long), 16); // Print a pointer in hexadecimal format
	else if (c == 'u')
		count += ft_print_h(va_arg(ap, unsigned int), 10, c); // Print an unsigned integer in decimal format
	else if (c == '%')
		count += ft_print_c('%'); // Print a percent sign
	else
		return (-1); // Return -1 for an invalid format specifier

	return (count); // Return the total number of characters printed
}

// Function to mimic the behavior of printf
// Parameters:
//   list_args - the format string containing the list of format specifiers
// Returns the total number of characters printed
int	ft_printf(const char *list_args, ...)
{
	int		n; // Declare an integer to hold the total number of characters printed
	va_list	ap; // Declare a variable to hold the list of arguments

	va_start(ap, list_args); // Initialize the list of arguments
	n = 0; // Initialize the total number of characters printed to 0

	// Iterate through the format string
	while (*list_args)
	{
		// If the current character is a percent sign, handle the format specifier
		if (*list_args == '%')
		{
			n += print_args(*(++list_args), ap); // Call print_args to print the argument and update the count
		}
		else
			n += write(1, list_args, 1); // Otherwise, print the character as it is and update the count
		list_args++; // Move to the next character in the format string
	}

	va_end(ap); // Clean up the list of arguments
	return (n); // Return the total number of characters printed
}
