/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:49:42 by tsilva            #+#    #+#             */
/*   Updated: 2023/12/15 13:02:17 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * s: The source string to be split.
 * c: The delimiter character.
 *
 * Returns a pointer to an array of token strings.
 * If memory allocation fails or the input string is NULL, returns NULL.
*/
char **ft_split(char const *s, char c)
{
    // Declare a pointer to hold the array of token strings.
    char **result;

    // Declare variables to keep track of the current position in the source string and result array.
    int s_pos;
    int r_pos;

    // Check for NULL input string and return NULL if invalid.
    if (!s)
        return (0);

    // Allocate memory for the array of token strings.
    result = (char **)malloc((count_token(s, c) + 1) * sizeof(char *));

    // Check if malloc failed to allocate memory.
    if (!result)
        return (0);

    // Initialize the position counters for the source string and result array.
    s_pos = 0;
    r_pos = 0;

    // Iterate through the source string.
    while (s[s_pos] != '\0')
    {
        // If the current character is not the delimiter, extract the token.
        if (s[s_pos] != c)
        {
            // Get the token starting from the current position.
            result[r_pos] = get_token(s, c, s_pos);

            // If memory allocation for the token failed, free the already allocated tokens and return NULL.
            if (!result[r_pos])
                return (del_tokens(result, r_pos));

            // Move the source position to the end of the current token.
            s_pos = s_pos + (ft_strlen(result[r_pos]) - 1);

            // Move to the next position in the result array.
            r_pos++;
        }

        // Move to the next character in the source string.
        s_pos++;
    }

    // Add a NULL pointer to the end of the result array to indicate the end of tokens.
    result[r_pos] = 0;

    // Return the pointer to the array of token strings.
    return (result);
}
