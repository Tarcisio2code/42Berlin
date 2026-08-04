/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 09:04:41 by tsilva            #+#    #+#             */
/*   Updated: 2025/11/02 16:36:59 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../inc/parse_and_validation.h"

static	void	validate_textures(t_game *game);

static bool	has_full_color(int c[3])
{
	return ((c[0] >= 0 && c[0] <= 255)
		&& (c[1] >= 0 && c[1] <= 255)
		&& (c[2] >= 0 && c[2] <= 255));
}

void	validate_scene(t_game *game)
{
	if (game->textures.floor.path)
		validate_texture_file(game->textures.floor.path);
	if (game->textures.ceiling.path)
		validate_texture_file(game->textures.ceiling.path);
	if (!(has_full_color(game->floor_color)))
		exit_clean(ERR_RGB_COLOR, game);
	if (!(has_full_color(game->ceiling_color)))
		exit_clean(ERR_RGB_COLOR, game);
	validate_textures(game);
	validate_map(game);
}

static	void	validate_textures(t_game *game)
{
	if (!game->textures.north.path || !game->textures.south.path
		|| !game->textures.west.path || !game->textures.east.path)
		exit_clean(ERR_TEXTURE_PATH, game);
	if (!validate_texture_file(game->textures.north.path) // try to open the texture file and check if it is empty
		|| !validate_texture_file(game->textures.south.path) 
		|| !validate_texture_file(game->textures.west.path)
		|| !validate_texture_file(game->textures.east.path))
		exit_clean(ERR_TEXTURE_FILE, game);
}
