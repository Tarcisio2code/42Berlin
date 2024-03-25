/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:18:54 by tsilva            #+#    #+#             */
/*   Updated: 2023/12/05 16:12:17 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
// dst: Pointer to the destination string.
// src: Pointer to the source string.
// size: Maximum number of characters that can be stored in the destination string, including the null terminator
{
  // Variables to store the lengths of the destination and source strings.
	size_t	count;
	size_t	dst_size;
	size_t	src_size;

  // Calculate the lengths of the destination and source strings.
	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);

  // If the provided size is zero or negative, return the length of the source string.
	if (size <= 0)
		return (src_size);
  
  // Initialize count to zero
	count = 0;

  // Append characters from the source to the destination until:
  // 1. The size limit is reached minus 1 (to reserve space for the null terminator) OR
  // 2. The end of the source string is reached.  
	while (dst_size + count < size - 1 && src[count])
	{
		dst[dst_size + count] = src[count];
		count++;
	}
  // Null-terminate the destination string.
	dst[dst_size + count] = '\0';
  
  // If the size limit is greater than the length of the destination string, return the 
  if (size > dst_size)
      // sum of the lengths of the destination and source strings
			return (dst_size + src_size);
  else
	    // Otherwise, return the sum of the lengths of the source string and the size limit
		  return (src_size + size);
}
