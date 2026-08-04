/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:01:43 by tsilva            #+#    #+#             */
/*   Updated: 2025/11/04 12:07:01 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../inc/parse_and_validation.h"

static void	validate_map_line(t_game *game, char *map_data, int row);
static void	normalize_map_line(t_game *game, char *map_line, int row);

void	validate_map(t_game *game)
{
	int	len;
	int	row;

	if (game->map->width > MAX_MAP_WIDTH || game->map->height > MAX_MAP_HEIGHT)
		exit_clean(ERR_MAP_SIZE, game);
	row = 0;
	while (game->map->data[row])
	{
		len = ft_strlen(game->map->data[row]);
		if (len < 3)
			exit_clean(ERR_MAP_SIZE, game);
		validate_map_line(game, game->map->data[row], row);
		normalize_map_line(game, game->map->data[row], row);
		row++;
	}
	if (row < 3)
		exit_clean(ERR_MAP_SIZE, game);
	if (!game->player.spawn)
		exit_clean(ERR_MAP_NOPLAYER, game);
	if (!validate_map_wall(game))
		exit_clean(ERR_MAP_WALL, game);
}

static void	validate_map_line(t_game *game, char *map_line, int row)
{
	int		col;
	char	*valid_char;

	col = 0;
	valid_char = " 012DNSWE";
	while (map_line[col])
	{
		if (!ft_strchr(valid_char, map_line[col]))
			exit_clean(ERR_MAP_CHAR, game);
		else if (ft_strchr(valid_char + 5, map_line[col]))
		{
			if (game->player.spawn)
				exit_clean(ERR_MAP_SPAWN, game);
			game->player.spawn = map_line[col];
			game->player.row = row;
			game->player.col = col;
		}
		if (row < game->map->height - 1 && map_line[col] == '0' 
			&& !game->map->walkable)
			game->map->walkable = true;
		if (row == game->map->height - 1 && !game->map->walkable)
			exit_clean(ERR_MAP_WALK, game);
		validate_doors(game, map_line[col], row, col);
		col++;
	}
}

static void	normalize_map_line(t_game *game, char *map_data, int row)
{
	int		len;
	char	*new_map_data;

	len = ft_strlen(map_data);
	if (len < game->map->width)
	{
		new_map_data = (char *)malloc(sizeof(char) * (game->map->width + 1));
		if (!new_map_data)
			exit_clean(ERR_MALLOC, game);
		ft_memcpy(new_map_data, game->map->data[row], len);
		ft_memset(new_map_data + len, ' ', game->map->width - len);
		new_map_data[game->map->width] = '\0';
		free(game->map->data[row]);
		game->map->data[row] = new_map_data;
	}
}
