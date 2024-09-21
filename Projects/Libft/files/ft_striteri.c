/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:28:02 by tsilva            #+#    #+#             */
/*   Updated: 2023/11/25 11:04:33 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * s: The source string to be iterated over.
 * f: The function to apply to each character of the source string.
 * The function takes two arguments: the index of the character and a pointer to the character.
 *
 * This function modifies the original string `s` in place.
*/
void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    // Declare a variable to keep track of the current index.
    unsigned int index;

    // If the input string is NULL or empty, return immediately.
    if (!*s)
        return;

    // Initialize the index to 0.
    index = 0;

    // Iterate through each character of the source string until the null terminator is reached.
    while (s[index])
    {
        // Apply the function to the current character, passing the index and a pointer to the character.
        f(index, s + index);

        // Move to the next character.
        index++;
    }
}
