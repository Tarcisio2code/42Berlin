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

static int	count_token(char const *s, char c)
{
	size_t	count;
	int		pos;

	count = 0;
	pos = 0;
	while (s[pos])
	{
		if (s[pos] != c && (s[pos + 1] == c || s[pos + 1] == '\0'))
			count++;
		pos++;
	}
	return (count);
}

static char	*get_token(char const *s, char c, int s_pos)
{
	char	*str;
	size_t	size;
	int		pos;

	size = 0;
	pos = s_pos;
	while (s[pos] && s[pos++] != c)
		size++;
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (0);
	pos = 0;
	while (s[s_pos] && s[s_pos] != c)
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

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		s_pos;
	int		r_pos;

	if (!s)
		return (0);
	result = (char **)malloc((count_token(s, c) + 1) * sizeof(char *));
	if (!result)
		return (0);
	s_pos = 0;
	r_pos = 0;
	while (s[s_pos] != '\0')
	{
		if (s[s_pos] != c)
		{
			result[r_pos] = get_token(s, c, s_pos);
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
