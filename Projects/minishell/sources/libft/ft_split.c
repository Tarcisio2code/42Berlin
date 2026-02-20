/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:19:21 by fdunkel           #+#    #+#             */
/*   Updated: 2023/12/02 21:19:21 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_substrings(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static size_t	count_chars(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != c && *s)
	{
		count++;
		s++;
	}
	return (count);
}

static void	*free_array(char **strarray, size_t index)
{
	size_t	i;

	i = 0;
	while (i <= index)
		free(strarray[i++]);
	free(strarray);
	return (NULL);
}

static char	*populate_words(const char *s, size_t i, size_t count)
{
	char	*word;
	size_t	iter;

	word = (char *)malloc(count + 1);
	if (!word)
		return (NULL);
	iter = 0;
	while (iter < count)
	{
		word[iter] = s[i];
		iter++;
		i++;
	}
	word[iter] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**strarray;
	size_t	index;
	size_t	i;

	strarray = malloc(sizeof(char *) * (count_substrings(s, c) + 1));
	index = 0;
	i = 0;
	if (!strarray)
		return (NULL);
	while (s[i] && index < count_substrings(s, c))
	{
		if (s[i] == c)
			i++;
		else
		{
			strarray[index] = populate_words(s, i, count_chars(&s[i], c));
			if (!strarray[index])
				return (free_array(strarray, index));
			i += count_chars(&s[i], c);
			index++;
		}
	}
	strarray[index] = NULL;
	return (strarray);
}
