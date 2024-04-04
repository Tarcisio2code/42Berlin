/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:04:25 by tsilva            #+#    #+#             */
/*   Updated: 2023/12/05 13:09:58 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
// s1: Pointer to the first character of the first string
// s2: Pointer to the first character of the second string
// n: represents the maximum number of characters to compare between the two strings
{
  // Declare a variable that is used to keep track of the current position while iterating through the strings
	// Set the type as size_t, which is an unsigned integer type guaranteed to be able to represent the size of any object in memory
  size_t			pos;
  
  // Declare a pointer to an unsigned character (byte) in the first string
	unsigned char	*str1;

  // Declare a pointer to an unsigned character (byte) in the second string
  unsigned char	*str2;

  // If n is 0, no comparison needed, return 0
	if (n == 0)
		return (n);
	
  // Initialize the position variable to the first position (0)
  pos = 0;

  // Cast the input strings to unsigned char pointers
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
  
  // Iterate through the strings until a difference is found, or until the end of the string is reached, or until n - 1 characters have been compared.
	while ((str1[pos] == str2[pos]) && pos < (n - 1) && str1[pos])
		pos++;

  // Return the difference between the characters at the current position in the two strings
  // This will be 0 if the strings are equal up to the nth character, positive if str1 is greater, and negative if str2 is greater
	return (str1[pos] - str2[pos]);
}
