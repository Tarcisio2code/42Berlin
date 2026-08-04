/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:33:30 by tsilva            #+#    #+#             */
/*   Updated: 2024/06/02 14:10:41 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*clean_line(char **full_line, char **buffer, int bytes_read)
{
	char	*tmp_line;

	if (buffer)
		free(*buffer);
	if (bytes_read < 0)
	{
		free(*full_line);
		*full_line = NULL;
		return (NULL);
	}
	if (!*full_line)
		return (NULL);
	tmp_line = "";
	tmp_line = ft_strjoin(tmp_line, *full_line);
	free(*full_line);
	*full_line = NULL;
	return (tmp_line);
}

static char	*extract_next(char **full_line, int size)
{
	char	*next;
	char	*tmp_line;

	if (!*full_line)
		return (NULL);
	if (size < 0)
		size = find_next(*full_line);
	next = (char *)malloc((size + 2) * sizeof(char));
	if (!next)
		return (clean_line(&(*full_line), NULL, -1));
	ft_memcpy(next, *full_line, size + 1);
	next[size + 1] = '\0';
	if ((*full_line)[size + 1])
	{
		tmp_line = ft_strjoin("", *full_line + (size + 1));
		free(*full_line);
		*full_line = tmp_line;
	}
	else
		clean_line(&(*full_line), NULL, -1);
	return (next);
}

static char	*feth_line(char **line, char *buffer)
{
	char	*result;

	if (!(*line))
		result = "";
	else
		result = *line;
	result = ft_strjoin(result, buffer);
	free(*line);
	return (result);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	int			next_pos;
	int			bytes_read;
	static char	*full_line = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (clean_line(&full_line, NULL, -1));
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (clean_line(&full_line, NULL, -1));
	next_pos = find_next(full_line);
	while (next_pos == -1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (clean_line(&full_line, &buffer, bytes_read));
		buffer[bytes_read] = '\0';
		full_line = feth_line(&full_line, buffer);
		if (!(find_next(buffer) < 0))
			next_pos = -2;
	}
	free(buffer);
	return (extract_next(&full_line, next_pos));
}
