/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:05:59 by tsilva            #+#    #+#             */
/*   Updated: 2025/09/25 13:32:26 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/game_core.h"

bool	wall_collision(t_map *map, double x, double y)
{
	int	pos_x;
	int	pos_y;

	pos_x = (int)floor(x / TILE_SIZE);
	pos_y = (int)floor(y / TILE_SIZE);
	if (pos_x < 0 || pos_y < 0)
		return (True);
	return (map->data[pos_y][pos_x] == '1'
			|| map->data[pos_y][pos_x] == ' '
			|| map->data[pos_y][pos_x] == 'D' 
			|| map->data[pos_y][pos_x] == 'X');
}

int	close_game(t_game *game)
{
	game->is_running = false;
	return (0);
}

void	load_textures(t_game *game)
{
	set_texture_img(game, &game->textures.north);
	set_texture_img(game, &game->textures.south);
	set_texture_img(game, &game->textures.east);
	set_texture_img(game, &game->textures.west);
	set_texture_img(game, &game->textures.game_over);
	set_texture_img(game, &game->textures.help_screen);
	if (game->textures.floor.path)
		set_texture_img(game, &game->textures.floor);
	if (game->textures.ceiling.path)
		set_texture_img(game, &game->textures.ceiling);
}

void	set_texture_img(t_game *game, t_image *texture)
{
	char	*path;
	int		width;
	int		height;

	path = texture->path;
	texture->img_ptr = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	if (!texture->img_ptr)
		exit_clean(ERR_LOAD_TEXTURE, game);
	texture->width = width;
	texture->height = height;
	set_img_data(texture);
	free(texture->path);
	texture->path = NULL;
}

void	set_img_data(t_image *image)
{
	int		*bpp;
	int		*size_line;
	int		*endian;
	void	*img_ptr;

	img_ptr = image->img_ptr;
	bpp = &image->bpp;
	size_line = &image->size_line;
	endian = &image->endian;
	image->data = mlx_get_data_addr(img_ptr, bpp, size_line, endian);
}
