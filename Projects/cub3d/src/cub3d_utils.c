/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 08:49:52 by tsilva            #+#    #+#             */
/*   Updated: 2025/11/01 12:13:23 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	exit_clean(char *error_msg, t_game *game)
{
	int	exit_status;

	if (error_msg)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(error_msg, 2);
		ft_putstr_fd("\n", 2);
		exit_status = EXIT_FAILURE;
	}
	else
		exit_status = EXIT_SUCCESS;
	if (game)
	{
		free_vars(game);
		if (game->scene_file >= 0)
			close(game->scene_file);
	}
	exit(exit_status);
}

void	check_entry(char *scene_name, int argc)
{
	size_t	name_len;

	if (argc != 2)
		exit_clean(ERR_ARG, 0);
	name_len = ft_strlen(scene_name);
	if (name_len < 5 || scene_name[name_len - 5] == '/' 
		|| scene_name[name_len - 5] == ' ' 
		|| ft_strncmp(scene_name + name_len - 4, ".cub", 4))
		exit_clean(ERR_SCENE_FILE, 0);
}

bool	check_file(char *filepath)
{
	int	fd;

	fd = open(filepath, O_RDONLY);
	if (fd < 0 || is_file_empty(fd))
		return (false);
	return (fd);
}

bool	is_file_empty(int fd)
{
	char	*buffer;
	char	*space;
	int		i;

	space = " \b\t\n\v\r";
	buffer = get_next_line(fd);
	while (buffer)
	{
		if (!buffer)
			return (true);
		i = -1;
		while (buffer[++i])
		{
			if (!ft_strchr(space, buffer[i]))
			{
				free(buffer);
				return (false);
			}
		}
		free(buffer);
		buffer = get_next_line(fd);
	}
	return (true);
}

double	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	
	// Converts the time into a single 'double' value representing total seconds.
	// It combines seconds (tv.tv_sec) with microseconds (tv.tv_usec) converted to a fractional part of a second.
	return (tv.tv_sec + tv.tv_usec / 1000000.0);
}
