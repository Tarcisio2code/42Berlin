/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:46:48 by tsilva            #+#    #+#             */
/*   Updated: 2023/11/28 15:06:45 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
// dst: Pointer to the destination string.
// src: Pointer to the source string.
// size: Maximum number of characters to copy, including the null terminator
{
  // Variable to keep track of the number of characters in the source string
  // size_t is used to represent sizes and lengths, it can represent the size of the largest
  // object that can be allocated in memory
	size_t	count;
  
  // Initializing count to zero
	count = 0;
  
  // Counting the number of characters in the source string until reaching the null terminator
	while (src[count])
	{
		count++;
	}

  // If the length of the source string plus one (for the null terminator) is less than the size provided,
  // copy the entire source string including the null terminator to the destination.
	if (count + 1 < size)
	{
		ft_memcpy(dst, src, count + 1);
	}
  // If the size provided is not zero and the length of the source string is equal to or greater than the size,
  // copy only size - 1 characters from the source to the destination and ensure the destination is null-terminated.
	else if (size != 0)
	{
    // Copy size - 1 characters from the source
		ft_memcpy(dst, src, size - 1);
    
     // Null-terminate the destination string
		dst[size - 1] = '\0';
	}
  
  // Return the length of the source string
	return (count);
}
