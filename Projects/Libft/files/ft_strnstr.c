/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:05:28 by tsilva            #+#    #+#             */
/*   Updated: 2023/12/10 11:46:33 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_strnstr(char const *big, char const *little, size_t len)
// *big: Represents a pointer to the string in which the function searches for the substring (little)
// *little: Represents a pointer to the substring that the function searches for within the string (big)
{
    // Declare a variable count to keep track of the number of characters compared
    size_t count;

    // If (big) is null and (len) is 0, return a null pointer.
    if (!big && !len)
        return (0);
    
    // If (little) is an empty string, return (big) indicating that the substring is found at the start.
    if (!*little)
        return ((char *)big);
    
    // Start iterating over (big) until either the end of (big) is reached or (len) becomes 0.
    while (*big && len--)
    {
        // Initialize count to 0 for each iteration
        count = 0;
        
        // Compare characters of (big) and (little) as long as they are equal and within the length limit (len)
        while (*(big + count) == *(little + count) && *(little + count) && count <= len)
        {
            // If the characters match and the end of the substring (little) is reached, return a 
            // pointer to the current position in the string (big)
            if (!*(little + count + 1))
                return ((char *)big);
            // Increment the counter to move to the next character in the substring (little)
            count++;
        }
        
        // Move to the next character in (big)
        big++;
    }
    
    // If the substring is not found, return a null pointer
    return (0);
}
