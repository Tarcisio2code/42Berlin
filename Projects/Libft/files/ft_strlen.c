/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:00:52 by tsilva            #+#    #+#             */
/*   Updated: 2023/11/28 15:25:24 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
// Receives *str which is a pointer to the string whose length should be returned.
{
  // Declare and initialize a variable 'count' to store the string length.
	size_t	count;

	count = 0;
  // Iterates the string until the null terminator '\0' is found
	while (str[count])
    // Increment the 'count' variable for each character in the string
		count++;
  // Return the final count, representing the length of the string
	return (count);
}
