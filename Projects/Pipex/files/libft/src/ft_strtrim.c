/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:19:56 by tsilva            #+#    #+#             */
/*   Updated: 2023/12/04 15:06:49 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, const char *set)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		start;
	int		end;
	int		pos;

	if (!s1 || !set)
		return (0);
	start = 0;
	while (s1[start] && check_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && check_set(s1[end - 1], set))
		end--;
	result = (char *)malloc(((end - start) + 1) * sizeof(char));
	if (!result)
		return (0);
	pos = 0;
	while (start < end)
		result[pos++] = s1[start++];
	result[pos] = '\0';
	return (result);
}
