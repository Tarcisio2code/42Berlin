/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:21:15 by tsilva            #+#    #+#             */
/*   Updated: 2023/12/05 13:28:09 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
// *str: represents a pointer to a character
// c: represents the character that the function is searching for within the string (str)
{
  // Declare a constant character pointer
	const char	*start;
  
  // Assign the address of the beginning of the string (str) to the start pointer
	start = str;
  
  // Move the (str) pointer to the end of the string by adding the length of the string to it
	str = str + ft_strlen(str);

  // Start a loop that iterates from the end of the string towards the beginning
	while (str >= start)
	{
    // Check if the character at the current position in the string (*str) is equal to the character (c)
		if (*str == (unsigned char)c)
      // If the character is found, return a pointer to the location in the string where it was found
			return ((char *)str);
    // Move the str pointer one position backward in the string
		str--;
	}
  // If the character c is not found in the string, return a null pointer
	return (0);
}
