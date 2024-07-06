/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:09:58 by tsilva            #+#    #+#             */
/*   Updated: 2023/11/18 18:06:04 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * src: The source string to be duplicated.
 *
 * Returns a pointer to the newly allocated string, which is a duplicate of the source string.
 * If memory allocation fails, returns NULL.
*/
char *ft_strdup(char *src)
{
    // Declare a pointer to hold the duplicated string.
    char *dup_src;

    // Declare a variable to store the size of the source string.
    int size;

    // Declare a variable to keep track of the current position while copying the string.
    int pos;

    // Initialize size to 0.
    size = 0;

    // Calculate the length of the source string.
    while (src[size])
        size++;

    // Allocate memory for the duplicate string including space for the null terminator.
    dup_src = (char *)malloc((size + 1) * sizeof(char));

    // Check if malloc failed to allocate memory.
    if (!dup_src)
        // If malloc failed, return NULL.
        return (NULL);

    // Initialize pos to 0.
    pos = 0;

    // Copy each character from the source string to the duplicate string.
    // Include the null terminator by copying up to size (inclusive).
    while (pos <= size)
    {
        dup_src[pos] = src[pos];
        pos++;
    }

    // Return the pointer to the duplicated string.
    return (dup_src);
}
