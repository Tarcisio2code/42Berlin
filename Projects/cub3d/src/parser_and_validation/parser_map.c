/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:15:55 by tsilva            #+#    #+#             */
/*   Updated: 2025/11/04 12:06:26 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../inc/parse_and_validation.h"

static void	parse_map_line(t_game *game, int line_size);

void	parse_map(t_game *game)
{
	if (!game->map->line)
		exit_clean(ERR_MAP_ABSENT, game);
	game->map->line = trim_newline(game->map->line);
	while (game->map->line && is_map_line(game->map->line))
	{
		parse_map_line(game, ft_strlen(game->map->line));
		free(game->map->line);
		game->map->line = trim_newline(get_next_line(game->scene_file));
	}
	while (game->map->line)
	{
		if (!is_empty_line(game->map->line))
			exit_clean(ERR_MAP_LAST, game);
		free(game->map->line);
		game->map->line = trim_newline(get_next_line(game->scene_file));
	}
}

static void	parse_map_line(t_game *game, int line_size)
{
	char	**new_map;
	int		i;

	new_map = (char **)malloc(sizeof(char *) * (game->map->height + 2));
	if (!new_map)
		exit_clean(ERR_MALLOC, game);
	i = 0;
	while (i < game->map->height)
	{
		new_map[i] = game->map->data[i];
		i++;
	}
	new_map[i++] = ft_strdup(game->map->line);
	if (!new_map[i - 1])
		exit_clean(ERR_MALLOC, game);
	new_map[i] = NULL;
	if (game->map->data)
		free(game->map->data);
	game->map->data = new_map;
	game->map->height++;
	if (line_size > game->map->width)
		game->map->width = line_size;
}
