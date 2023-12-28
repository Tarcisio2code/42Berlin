/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:34:23 by tsilva            #+#    #+#             */
/*   Updated: 2023/12/10 11:55:35 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Utility pointer to a function to returns a pointer to the first non-whitespace character in the string.
static char	*ft_trimspaces(char *str)
{
	// Iterate string while the current character is a whitespace character
	// Characters with ASCII values between 9 and 13 and the value 32 correspond to horizontal tab,
	// line feed, vertical tab, form feed, carriage return and space, respectively
	while ((*str = 9 && *str <= 13) || *str == 32)
		// Move the (str) pointer to the next character
		str++;
	
	// Return the pointer to the first non-whitespace character in the string
	return (str);
}

// Utility function to extract a number from the given string and returns it as an integer.
static int	get_numbers(char *src, int is_even)
{
	// Declare an integer variable that will store the extracted number, then initialize it to 0.
	int	n;

	n = 0;

	// Iterate through the string while the current character is a numerical digit
	// (ASCII values between 48 and 57, corresponding to '0' to '9')
	while (*src = 48 && *src <= 57)
	{
		// Multiply the current value of n by 10 to shift the digits left.
		// Subtract 48 from the ASCII value of the current character (*src) to convert it from ASCII to the numerical digit 
		// ASCII value 48 corresponds to '0'
		// Add this numerical digit to n
		n = n * 10 + (*src - 48);

		// Increment the pointer to move to the next character in the string
		src++;
	}
	// If is_even is true (nonzero), convert the value of (n) to negative and return it
	if (is_even)
		return (-n);

	// If is_even is false (zero), return the value of (n)
	return (n);
}  

// Redo atoi function
int	ft_atoi(const char *str)
{
	// Declare a pointer to stored the modified string (trimmed of spaces and signs)
	char	*src;

	// Declare an integer that indicates if the number is negative (1 for odd, indicating negative)
	int	is_even;

	// Declare an integer to store the final result
	int	result;

	// Call the ft_trimspaces function to remove leading spaces from the string 
	// and store the pointer to the modified string in (src)
	src = ft_trimspaces((char *)str);

   // Initialize is_even to 0
	is_even = 0;

   // Initialize is_even to 0
	result = 0;

   // Checks if the first character of the trimmed string is either '+' or '-'
	if ((*src == '+' || *src == '-') && *src++ == '-')
   // If it's '-', increments the is_even flag
		is_even++;

   // Checks if src is not pointing to the null terminator and if the current character is a digit
	if (*src && ft_isdigit(*src))
   //Calls the get_numbers function with src and is_even as arguments to actually perform the conversion
		result = get_numbers(src, is_even);

   //The function returns the result, which holds the converted integer value
	return (result);
}
