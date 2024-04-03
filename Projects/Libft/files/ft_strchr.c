/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:16:26 by tsilva            #+#    #+#             */
/*   Updated: 2023/12/05 15:13:51 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
// *s: represents a pointer to a constant character
// c: represents the character that the function is searching for within the string (s)
{
  // Declare a local variable as a pointer to a character
	char	*str;

  // Declare a local variable to keep track of the position within the string
	int		pos;

  // Declare a local variable to store the size of the string
	int		size;

  // Cast the input string (s) to a character pointer and assign it to the local variable (str)
	str = (char *)s;

  // Call the ft_strlen function to get the size of the string and assign it to the (size) variable
	size = ft_strlen(str);
 
  // Initialize the pos variable to 0 to start iterating over the string
	pos = 0;

  // Start a loop that iterates through the string and terminates when the position (pos) exceeds the size of the string
	while (pos <= size)
	{
    // Check if the character at the current position in the string is equal to the character (c)
		if (str[pos] == (unsigned char)c)
      // If the character is found, return a pointer to the location in the string where it was found
			return (&str[pos]);
    // Increment the position counter to move to the next character in the string
		pos++;
	}
  // If the character (c) is not found in the string, return a null pointer
	return (0);
}
