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

#include "libft.h"
static char	**del_tokens(char **str, int len);
static char	*get_token(char const *s, char c, int s_pos);
static int	count_token(char const *s, char c);

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

// Counts the number of tokens (substrings) in 's' separated by the character 'c'.
static int	count_token(char const *s, char c)
{
	size_t	count;  // Variable to store the number of tokens.
	int		pos;    // Position index for iterating through the string 's'.

	count = 0;
	pos = 0;

	// Iterate through the string 's'.
	while (s[pos])
	{
		// If current character is not 'c' and the next character is either 'c' or end of string, increment the token count.
		if (s[pos] != c && (s[pos + 1] == c || s[pos + 1] == '\0'))
			count++;
		pos++;  // Move to the next character.
	}

	// Return the total number of tokens found.
	return (count);
}

// Extracts a single token (substring) from 's', starting from position 's_pos', until it encounters the delimiter 'c'.
static char	*get_token(char const *s, char c, int s_pos)
{
	char	*str;   // Pointer to the new token (substring).
	size_t	size;   // Variable to store the length of the token.
	int		pos;    // Position index for scanning the token.

	size = 0;
	pos = s_pos;

	// Calculate the length of the token by iterating until a 'c' or the end of the string is found.
	while (s[pos] && s[pos++] != c)
		size++;

	// Allocate memory for the token, including space for the null terminator.
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (0);  // Return NULL if memory allocation fails.

	pos = 0;

	// Copy characters from 's' into the new string 'str', stopping at 'c' or end of the string.
	while (s[s_pos] && s[s_pos] != c)
		str[pos++] = s[s_pos++];

	// Null-terminate the string.
	str[pos] = '\0';

	// Return the token.
	return (str);
}

// Frees the memory of all tokens stored in the array 'str' up to 'len' tokens.
static char	**del_tokens(char **str, int len)
{
	int	pos;  // Position index for iterating through the array of tokens.

	pos = 0;

	// Free each token up to 'len' tokens.
	while (pos <= len)
		free(str[pos++]);

	// Free the array itself.
	free(str);

	// Return NULL as a signal that the array has been freed.
	return (0);
}

