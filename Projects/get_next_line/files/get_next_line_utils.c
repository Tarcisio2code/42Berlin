/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:07:33 by tsilva            #+#    #+#             */
/*   Updated: 2024/02/26 13:20:40 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

/*
 * s1: The first string to be concatenated.
 * s2: The second string to be concatenated.
 *
 * Returns a pointer to the newly allocated string containing the concatenated result.
 * If memory allocation fails, returns NULL.
*/
char *ft_strjoin(char const *s1, char const *s2)
{
    // Declare a pointer to hold the newly allocated concatenated string.
    char *new_str;

    // Declare an integer to store the maximum length of the new string, including the null terminator.
    int max_len;

    // Declare an integer to keep track of the current position while building the new string.
    int pos;

    // Calculate the total length of the new string by adding the lengths of s1 and s2, plus one for the null terminator.
    max_len = ft_strlen(s1) + ft_strlen(s2) + 1;

    // Allocate memory for the new string.
    new_str = (char *)malloc(max_len * sizeof(char));

    // Check if malloc failed to allocate memory.
    if (!new_str)
        // If malloc failed, return NULL (0).
        return (0);

    // Initialize the position counter to 0.
    pos = 0;

    // Copy characters from the first string (s1) to the new string.
    while (*s1)
        // Copy the current character from s1 to the new string and increment the position.
        new_str[pos++] = *s1++;

    // Copy characters from the second string (s2) to the new string.
    while (*s2)
        // Copy the current character from s2 to the new string and increment the position.
        new_str[pos++] = *s2++;

    // Add the null terminator to the end of the new string.
    new_str[pos++] = '\0';

    // Return the pointer to the newly created concatenated string.
    return (new_str);
}

/*
	The function find_next searches for the next newline character (\n) in the string line.
	It returns the position of the newline if found, or -1 if no newline exists or if line is NULL.
*/
int	find_next(char *line)
{
	int	next_pos;  // Variable to track the current position in the string.

	// If the input 'line' is NULL, return -1 indicating no newline found.
	if (!line)
		return (-1);

	next_pos = 0;  // Initialize position to the start of the string.

	// Loop through the string until the end ('\0') is reached.
	while (line[next_pos])
		// If a newline character ('\n') is found, return its position.
		if (line[next_pos++] == '\n')
			return (next_pos - 1);  // Return the position of the newline.

	// If no newline is found, return -1.
	return (-1);
}

