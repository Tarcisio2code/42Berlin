/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:29:18 by tsilva            #+#    #+#             */
/*   Updated: 2023/12/04 14:55:25 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
// *s1: Represents a pointer to the first memory block to be compared
// *s2: Represents a pointer to the second memory block to be compared
//  n: Represents the number of bytes to be compared in the memory blocks
{
    // Declare a variable pos to keep track of the position within the memory block
    size_t pos;
    
    // Declare pointers to unsigned characters
    unsigned char *str1;
    unsigned char *str2;

    // Initialize the pos variable to 0 to start iterating over the memory blocks
    pos = 0;
    // Cast the input pointers to pointers to unsigned characters and assign them to the local variables
    str1 = (unsigned char *)s1;
    str2 = (unsigned char *)s2;
    
    // Start a loop that iterates through the memory blocks until pos reaches the limit (n)
    while (pos < n)
    {
        // Check if the bytes at the current position in the memory blocks are equal
        if (!(str1[pos] == str2[pos]))
            // Return the difference between the characters
            return (str1[pos] - str2[pos]);
        
        // Increment the position counter to move to the next byte in the memory blocks.
        pos++;
    }
    
    // If all bytes are equal in the memory blocks, return 0 to indicate equality
    return (0);
}
