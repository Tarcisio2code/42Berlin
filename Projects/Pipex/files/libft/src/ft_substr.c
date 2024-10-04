/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:35:11 by tsilva            #+#    #+#             */
/*   Updated: 2023/12/14 15:11:30 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	src_pos;
	size_t	sub_pos;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (start + len > s_len || (int)len < 0)
		len = s_len - start;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (0);
	src_pos = start;
	sub_pos = 0;
	while (sub_pos < len)
		sub[sub_pos++] = s[src_pos++];
	sub[sub_pos] = '\0';
	return (sub);
}
