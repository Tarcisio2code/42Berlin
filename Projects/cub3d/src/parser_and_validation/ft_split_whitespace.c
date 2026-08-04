/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:49:42 by tsilva            #+#    #+#             */
/*   Updated: 2025/07/25 21:05:44 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../inc/parse_and_validation.h"

static int	count_token(char const *s)
{
	size_t	count;
	int		pos;

	count = 0;
	pos = 0;
	while (s[pos])
	{
		if (!is_whitespace(s[pos]) && (is_whitespace(s[pos + 1]) 
				|| s[pos + 1] == '\0'))
			count++;
		pos++;
	}
	return (count);
}

static char	*get_token(char const *s, int s_pos)
{
	char	*str;
	size_t	size;
	int		pos;

	size = 0;
	pos = s_pos;
	while (s[pos] && !is_whitespace(s[pos++]))
		size++;
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (0);
	pos = 0;
	while (s[s_pos] && !is_whitespace(s[s_pos]))
		str[pos++] = s[s_pos++];
	str[pos] = '\0';
	return (str);
}

static char	**del_tokens(char **str, int len)
{
	int	pos;

	pos = 0;
	while (pos <= len)
		free(str[pos++]);
	free(str);
	return (0);
}

char	**ft_split_whitespace(char const *s)
{
	char	**result;
	int		s_pos;
	int		r_pos;

	if (!s)
		return (0);
	result = (char **)malloc((count_token(s) + 1) * sizeof(char *));
	if (!result)
		return (0);
	s_pos = 0;
	r_pos = 0;
	while (s[s_pos] != '\0')
	{
		if (!is_whitespace(s[s_pos]))
		{
			result[r_pos] = get_token(s, s_pos);
			if (!result[r_pos])
				return (del_tokens(result, r_pos));
			s_pos = s_pos + (ft_strlen(result[r_pos]) - 1);
			r_pos++;
		}
		s_pos++;
	}
	result[r_pos] = 0;
	return (result);
}
