/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:19:56 by tsilva            #+#    #+#             */
/*   Updated: 2023/12/04 15:06:49 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, const char *set);
/*
 * s1: The source string to be trimmed.
 * set: The set of characters to trim from the source string.
 *
 * Returns a pointer to the newly allocated trimmed string.
 * If memory allocation fails or inputs are invalid, returns NULL.
*/
char *ft_strtrim(char const *s1, char const *set)
{
    // Declare a pointer to hold the resulting trimmed string.
    char *result;

    // Declare integers to keep track of the start and end indices for trimming.
    int start;
    int end;

    // Declare an integer to keep track of the current position in the result string.
    int pos;

    // Check for NULL inputs and return NULL if either input is invalid.
    if (!s1 || !set)
        return (0);

    // Initialize the start index to 0.
    start = 0;

    // Move the start index forward while characters in s1 match the set.
    while (s1[start] && check_set(s1[start], set))
        start++;

    // Get the length of the source string.
    end = ft_strlen(s1);

    // Move the end index backward while characters in s1 match the set.
    while (end > start && check_set(s1[end - 1], set))
        end--;

    // Allocate memory for the resulting trimmed string, including space for the null terminator.
    result = (char *)malloc(((end - start) + 1) * sizeof(char));

    // Check if malloc failed to allocate memory.
    if (!result)
        return (0);

    // Initialize the position counter for the result string.
    pos = 0;

    // Copy characters from the source string to the result string, within the trimmed range.
    while (start < end)
        result[pos++] = s1[start++];

    // Add the null terminator to the end of the result string.
    result[pos] = '\0';

    // Return the pointer to the newly created trimmed string.
    return (result);
}

static int	check_set(char c, const char *set)
{
	// Loop through each character in the 'set' string.
	while (*set)
		// If the current character in 'set' matches 'c', return 1 (true).
		if (*set++ == c)
			return (1);
	// If no match is found after checking all characters, return 0 (false).
	return (0);
}
