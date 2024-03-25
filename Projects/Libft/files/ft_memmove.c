/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:47:25 by tsilva            #+#    #+#             */
/*   Updated: 2023/12/10 11:54:04 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
// 'dest': Represents a pointer to the destination memory block
// 'src': Represents a pointer to the source memory block
// 'n': Represents the number of bytes to be moved from the source to the destination memory block
{
  // Declare pointers to unsigned characters to ensures that each byte of data is correctly copied
  // from the source to the destination
  // Using unsigned char allows for precise and reliable manipulation of memory at the byte level
	unsigned char	*s;
	unsigned char	*d;

  // Casting the source and destination pointers to unsigned characters
	s = (unsigned char *)src;
	d = (unsigned char *)dest;

  // Checking if the source memory block overlaps with the destination memory block
  // Source:        |-----------------|
  //                | Overlapping Part|
  //                |-----------------|
  // Destination:   |----------------------|
  //                | Overlapping Part     |
  //                |----------------------|

	if (s < d)
	{
    // Copy data from end to start to avoid overwriting data before it's read
    // Iterate from the end of the memory block towards the start
		while (0 < n--)
      // Copy data byte by byte.
			d[n] = s[n];
	}
	else
	{
    // Use memcpy to copy data from source to destination
		ft_memcpy(d, s, n);
	}
  // Return a pointer to the destination memory block.
	return (d);
}
