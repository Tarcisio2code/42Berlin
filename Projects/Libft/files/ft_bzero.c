/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:20:21 by tsilva            #+#    #+#             */
/*   Updated: 2023/11/15 11:30:25 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Redo bzero function
void	ft_bzero(void *s, size_t n)
// *s: A pointer to the memory area to be zeroed
// n: Represents the number of bytes to be zeroed starting from 
// the memory location pointed to by s
{
   //Using size_t to declare variables guarantees the ability to contain the size of the largest object the host system can handle
	size_t			count;

   //Declare a pointer as an (unsigned char *) so that each element the pointer points to is treated as an unsigned character (1 byte in size), allowing byte-level manipulation.
	unsigned char	*src;

   //Initialize the counter to 0
	count = 0;

   //Initialize the temporary pointer to the memory address passed by (s)
	src = (unsigned char *)s;

   //Iterates count from 0 up to n.
	while (count < n)
	{
       //sets the value at the memory location pointed by (src) + count to \0 (null character) 
       //to effectively zero out that byte
		src[count] = '\0';

       //Increment the counter to move to the next byte in the memory area
		count++;
	}
}
