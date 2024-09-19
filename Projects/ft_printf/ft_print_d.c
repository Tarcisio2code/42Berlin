/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:02:08 by tsilva            #+#    #+#             */
/*   Updated: 2024/01/11 12:40:19 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Takes an integer 'n' which is the number to be printed
int	ft_print_d(int n)
{
	char	*str;  // Declare a pointer to a char, which will hold the string representation of the integer
	int	count; // Declare an integer to hold the number of characters printed

	// Convert the integer 'n' to a string using ft_itoa and store it in 'str'
	str = ft_itoa(n);
	
	// Print the string representation of the integer using ft_print_s and store the number of characters printed in 'count'
	count = ft_print_s(str);
	
	// Free the memory allocated for the string representation of the integer
	free(str);
	
	// Return the number of characters printed
	return (count);
}
