/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:01:43 by tsilva            #+#    #+#             */
/*   Updated: 2025/11/02 14:47:54 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../inc/parse_and_validation.h"

bool	validate_map_wall(t_game *game)
{
	char	**map_copy;
	int		row;

	map_copy = malloc(sizeof(char *) * (game->map->height + 1));
	if (!map_copy)
		return (false);
	row = -1;
	while (++row < game->map->height)
	{
		map_copy[row] = ft_strdup(game->map->data[row]);
		if (!map_copy[row])
			return (free_str_array(map_copy), false);
	}
	map_copy[row] = NULL;
	if (!dfs_fill(map_copy, game->player.row, game->player.col, game->map))
		return (free_str_array(map_copy), false);
	return (free_str_array(map_copy), true);
}

bool	dfs_fill(char **map_data, int row, int col, t_map *map)
{
	char	c;
	char	*valid_char;

	if (!(row >= 0 && row < map->height && col >= 0 && col < map->width))
		return (false);
	if (map_data[row][col] == ' ')
		return (false);
	valid_char = "02NSEWD";
	c = map_data[row][col];
	if (!ft_strchr(valid_char, c))
		return (true);
	map_data[row][col] = 'V';
	if (!dfs_fill(map_data, row + 1, col, map))
		return (false);
	if (!dfs_fill(map_data, row - 1, col, map))
		return (false);
	if (!dfs_fill(map_data, row, col + 1, map))
		return (false);
	if (!dfs_fill(map_data, row, col - 1, map))
		return (false);
	return (true);
}

bool	validate_texture_file(char *filepath)
{
	int	fd;

	fd = check_file(filepath);
	if (!fd)
		return (false);
	close(fd);
	return (true);
}

void	validate_doors(t_game *game, char c, int row, int col)
{
	t_map	*map;

	if (c != 'D')
		return ;
	map = game->map;
	if (row <= 0 || col <= 0 || row >= map->height - 1 
		|| col >= map->width - 1)
		exit_clean(ERR_DOOR, game);
	if (map->data[row][col - 1] == 'D' || map->data[row][col + 1] == 'D' ||
		map->data[row - 1][col] == 'D' || map->data[row + 1][col] == 'D')
		exit_clean(ERR_DOOR, game);
	if (!(map->data[row][col - 1] == '1' && map->data[row][col + 1] == '1')
		&& !(map->data[row - 1][col] == '1' && map->data[row + 1][col] == '1'))
		exit_clean(ERR_DOOR, game);
	if (!game->has_doors)
		game->has_doors = true;
}
