/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:30:25 by tsilva            #+#    #+#             */
/*   Updated: 2023/11/28 15:05:23 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
