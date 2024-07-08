/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:35:11 by tsilva            #+#    #+#             */
/*   Updated: 2023/12/14 15:11:30 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * ft_substr - Creates a substring from a given string.
 * s: The source string from which the substring is created.
 * start: The starting index of the substring in the source string.
 * len: The length of the substring to be created.
 *
 * Returns a pointer to the newly allocated substring.
 * If memory allocation fails, returns NULL.
*/
char *ft_substr(char const *s, unsigned int start, size_t len)
{
    // Declare a pointer to hold the allocated substring.
    char *sub;

    // Declare variables to keep track of the current position in the source string and substring.
    size_t src_pos;
    size_t sub_pos;

    // Declare a variable to store the length of the source string.
    size_t s_len;

    // Get the length of the source string using ft_strlen function.
    s_len = ft_strlen(s);

    // If the start index is greater than or equal to the length of the source string,
    // set the length of the substring to 0 since it's out of bounds.
    if (start >= s_len)
        len = 0;
    // If the start index + length exceeds the source string length,
    // or if len is negative (after being cast to int), adjust the length.
    else if (start + len > s_len || (int)len < 0)
        len = s_len - start;

    // Allocate memory for the substring, including space for the null terminator.
    sub = (char *)malloc((len + 1) * sizeof(char));

    // Check if malloc failed to allocate memory.
    if (!sub)
        // If malloc failed, return NULL (0).
        return (0);

    // Initialize source position to start and substring position to 0.
    src_pos = start;
    sub_pos = 0;

    // Copy characters from the source string to the substring.
    // Loop until the substring length is reached.
    while (sub_pos < len)
        // Copy the current character from the source string to the substring.
        sub[sub_pos++] = s[src_pos++];

    // Add the null terminator to the end of the substring.
    sub[sub_pos] = '\0';

    // Return the pointer to the newly created substring.
    return (sub);
}
