/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:52:51 by tsilva            #+#    #+#             */
/*   Updated: 2023/12/27 11:14:09 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H // If FT_PRINTF_H is not defined
# define FT_PRINTF_H // Define FT_PRINTF_H to prevent multiple inclusions of this header file

# include <stdarg.h> // Include the standard header file for handling variable arguments
# include "./libft/libft.h" // Include the custom libft library header file

// Declare the functions used in ft_printf and its helper functions

// Function to mimic printf functionality
int	ft_printf(const char *str, ...);

// Function to print a single character
int	ft_print_c(int c);

// Function to print a string
int	ft_print_s(char *s);

// Function to print a decimal integer
int	ft_print_d(int n);

// Function to print a pointer in hexadecimal format
int	ft_print_p(unsigned long long p, unsigned long long base);

// Function to print a number in a specified base (supports hexadecimal)
int	ft_print_h(unsigned long long n, unsigned long long base, char c);

#endif // End of the FT_PRINTF_H definition

