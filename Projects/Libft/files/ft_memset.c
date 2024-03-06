/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:41:02 by tsilva            #+#    #+#             */
/*   Updated: 2023/11/14 15:13:18 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int x, size_t n)
// 'ptr': Represents a pointer to the memory block that needs to be filled
// 'x': Represents the value that will be used to fill the memory block
// 'n': Represents the number of bytes to be filled
{
  // Declare a variable 'count' to keep track of the number of bytes processed
	size_t			count; 
  // Declare a pointer 'src' that will by used to convert 'ptr' to an unsigned char
	unsigned char	*src;

  // Initialize the 'count' variable to 0
	count = 0;
  // Cast the 'ptr' pointer to an unsigned char pointer and assign it to 'src'
	src = (unsigned char *)ptr;

  // Iterate through the memory block as long as 'count' is less than 'n'
	while (count < n)
	{
    // Assign the value of 'x' casted to unsigned char to the memory location pointed by 'src[count]'
		src[count] = (unsigned char)x;
    // Increment the 'count' variable to process the next byte.
		count++;
	}
  // Return the original pointer 'ptr' after modifying the memory block.
	return (ptr);
}
