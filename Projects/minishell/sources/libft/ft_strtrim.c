/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:36:26 by fdunkel           #+#    #+#             */
/*   Updated: 2023/12/10 17:31:50 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	strtrim_front(const char *s1, const char *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	return (i);
}

static size_t	strtrim_back(const char *s1, const char *set)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*copy;
	size_t	start;
	size_t	end;

	if (!*s1)
		return (ft_strdup(""));
	if (!*set)
		return (ft_strdup(s1));
	start = strtrim_front(s1, set);
	end = strtrim_back(s1, set);
	copy = ft_substr(s1, start, end - start + 1);
	return (copy);
}
