/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 09:11:09 by tsilva            #+#    #+#             */
/*   Updated: 2023/12/04 15:13:07 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * s: The source string to be mapped.
 * f: The function to apply to each character of the source string.
 *     The function takes two arguments: the index of the character and the character itself.
 *
 * Returns a pointer to the newly allocated string created by applying the function.
 * If memory allocation fails, returns NULL.
*/
char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    // Declare a variable to keep track of the current index.
    unsigned int index;

    // Declare a pointer to hold the newly allocated string.
    char *str;

    // Allocate memory for the new string, including space for the null terminator.
    str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));

    // Check if malloc failed to allocate memory.
    if (!str)
        return (0);

    // Initialize the index to 0.
    index = 0;

    // Iterate through each character of the source string.
    while (s[index])
    {
        // Apply the function to the current character and store the result in the new string.
        str[index] = f(index, s[index]);
        // Move to the next character.
        index++;
    }

    // Add the null terminator to the end of the new string.
    str[index] = '\0';

    // Return the pointer to the newly created string.
    return (str);
}
