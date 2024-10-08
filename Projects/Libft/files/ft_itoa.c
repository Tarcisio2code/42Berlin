/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:40:48 by tsilva            #+#    #+#             */
/*   Updated: 2023/11/28 14:59:10 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long abs_num(long long n);
static int len_num(int n);

/*
 * n: The integer to be converted to a string.
 *
 * Returns a pointer to the newly allocated string representing the integer.
 * If memory allocation fails, returns NULL.
*/
char *ft_itoa(int n)
{
    // Declare a pointer to hold the resulting string.
    char *result;

    // Declare a variable to hold the absolute value of the input integer.
    long value;

    // Declare a variable to hold the size of the resulting string.
    size_t size;

    // Calculate the number of digits in the input integer.
    size = len_num(n);

    // Allocate memory for the resulting string, including space for the null terminator.
    result = (char *)malloc((size + 1));

    // Check if malloc failed to allocate memory.
    if (!result)
        return (0);

    // Get the absolute value of the input integer.
    value = abs_num(n);

    // Move the result pointer to the end of the allocated memory.
    result = result + size;

    // Add the null terminator to the end of the string.
    *result = '\0';

    // Convert the absolute value to a string by iterating through its digits.
    while (value)
    {
        // Add the last digit of the value to the result string.
        *(--result) = 48 + (value % 10);
        // Remove the last digit from the value.
        value /= 10;
    }

    // If the input integer was negative, add the negative sign to the result string.
    if (n < 0)
        *(--result) = '-';
    // If the input integer was 0, add '0' to the result string.
    else if (n == 0)
        *(--result) = '0';

    // Return the pointer to the newly created string.
    return (result);
}

// Returns the absolute value of the number 'n'.
static long	abs_num(long long n)
{
	// If 'n' is negative, convert it to its positive equivalent.
	if (n < 0)
		n *= -1;

	// Return the absolute value of 'n'.
	return (n);
}

// Calculates and returns the number of digits in the integer 'n', including the sign if negative.
static int	len_num(int n)
{
	size_t	count;  // Variable to store the number of digits.

	count = 0;

	// If 'n' is 0 or negative, increment count to account for the sign or 0 digit.
	if (n <= 0)
		count++;

	// Loop to count digits by dividing 'n' by 10 repeatedly.
	while (n)
	{
		n /= 10;  // Divide 'n' by 10 to move to the next digit.
		count++;  // Increment digit count.
	}

	// Return the total number of digits.
	return (count);
}

