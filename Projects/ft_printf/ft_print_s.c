/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 10:37:09 by tsilva            #+#    #+#             */
/*   Updated: 2024/01/11 12:39:20 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Function to print a string
// Parameter:
//   s - the string to be printed
int	ft_print_s(char *s)
{
	// If the string is NULL
	if (!s)
		// Recursively call ft_print_s with the string "(null)" and return the number of characters printed
		return (ft_print_s("(null)"));
	else
		// Otherwise, print the string to the standard output
		ft_putstr_fd(s, 1);

	// Return the length of the string
	return (ft_strlen((const char *)s));
}

