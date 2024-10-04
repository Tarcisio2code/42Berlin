/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:30:25 by tsilva            #+#    #+#             */
/*   Updated: 2023/11/28 15:05:23 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		max_len;
	int		pos;

	max_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = (char *)malloc(max_len * sizeof(char));
	if (!new_str)
		return (0);
	pos = 0;
	while (*s1)
		new_str[pos++] = *s1++;
	while (*s2)
		new_str[pos++] = *s2++;
	new_str[pos++] = '\0';
	return (new_str);
}
