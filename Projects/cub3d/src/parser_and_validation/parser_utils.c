/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:14:17 by tsilva            #+#    #+#             */
/*   Updated: 2025/11/01 13:52:57 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../inc/parse_and_validation.h"

char	*trim_newline(char *line)
{
	size_t	len;

	if (!line)
		return (NULL);
	len = ft_strlen(line);
	if (len > 0 && (line[len -1] == '\n' || line[len - 1] == '\r'))
		line[len - 1] = '\0';
	return (line);
}

bool	is_empty_line(char *line)
{
	int	i;

	if (!line)
		return (true);
	i = -1;
	while (line[++i])
	{
		if (!is_whitespace(line[i]) && line[i] != '\n')
			return (false);
	}
	return (true);
}

bool	is_map_line(char *line)
{
	int		i;
	char	*valid_char;

	if (!line)
		return (false);
	i = 0;
	valid_char = "012D";
	while (line[i])
	{
		if (is_whitespace(line[i]) || line[i] == '\n')
			i++;
		else if (ft_strchr(valid_char, line[i]))
			return (true);
		else
			break ;
	}
	return (false);
}

bool	is_whitespace(char c)
{
	char	*whitespace;

	whitespace = " \t\v\f\r";
	return (ft_strchr(whitespace, c));
}

int	get_color(const char *str)
{
	int	n;

	if (!str)
		return (-1);
	n = -1;
	while (str[++n])
		if (str[n] < 48 || str[n] > 57)
			return (-1);
	return (ft_atoi(str));
}
