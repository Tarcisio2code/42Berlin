/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:00:36 by tsilva            #+#    #+#             */
/*   Updated: 2023/12/10 11:47:07 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
// 'dest': Represents a pointer to the destination memory block
// 'src': Represents a pointer to the source memory block
// 'n': Represents the number of bytes to be copied from the source to the destination memory block
{
  // Declare a variable 'pos' to keep track of the current position in the memory block
	size_t	pos;

  // Check if either 'dest' or 'src' pointers are null
	if (!dest && !src)
		return (0);
 
  // Initialize 'pos' to 0
	pos = 0;
  
  // iterates 'pos' times, where 'pos' is less than 'n'
	while (pos < n)
	{
    // Copy the byte at the 'pos' position in the 'src' memory to the 'pos' position in the 'dest' memory
		((unsigned char *)dest)[pos] = ((unsigned char *)src)[pos];
    
    // Increment 'pos' to process the next byte
		pos++;
	}
  
  // Return the pointer to the destination memory after copying
	return (dest);
}
