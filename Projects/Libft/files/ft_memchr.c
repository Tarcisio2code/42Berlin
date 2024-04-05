/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:00:14 by tsilva            #+#    #+#             */
/*   Updated: 2023/12/08 15:17:40 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
// *s: Represents a pointer to the memory block in which the function searches for the byte (c)
// c: Represents the byte (character) that the function is searching for within the memory block pointed to by (s)
// n: Specifies the limit for the search operation
{
    // Declare a variable to keep track of the position within the memory block
    size_t pos;
    
    // Declare a pointer to a character
    char *str;

    // Initialize the pos variable to 0 to start iterating over the memory block
    pos = 0;

    // Cast the input pointer to a character pointer and assign it to the local variable (str)
    str = (char *)s;
    
    // Start a loop that iterates through the memory block until pos reaches the limit (n)
    while (pos < n)
    {
        // Check if the byte at the current position in the memory block is equal to the byte represented by (c)
        if ((unsigned char)str[pos] == (unsigned char)c)
            // Return a pointer to the location in memory where it was found
            return ((char *)s + pos);
        
        // Increment the position counter to move to the next byte in the memory block
        pos++;
    }
    
    // If the byte c is not found in the memory block, return a null pointer
    return (0);
}
