/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 15:50:34 by tsilva            #+#    #+#             */
/*   Updated: 2025/11/04 12:09:57 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	free_wall_textures(t_game *game)
{
	t_textures	*tex;

	tex = &game->textures;
	if (tex->north.path)
		free(tex->north.path);
	if (tex->south.path)
		free(tex->south.path);
	if (tex->east.path)
		free(tex->east.path);
	if (tex->west.path)
		free(tex->west.path);
	if (tex->north.img_ptr)
		mlx_destroy_image(game->mlx, tex->north.img_ptr);
	if (tex->south.img_ptr)
		mlx_destroy_image(game->mlx, tex->south.img_ptr);
	if (tex->east.img_ptr)
		mlx_destroy_image(game->mlx, tex->east.img_ptr);
	if (tex->west.img_ptr)
		mlx_destroy_image(game->mlx, tex->west.img_ptr);
}

void	free_ui_textures(t_game *game)
{
	t_textures	*tex;

	tex = &game->textures;
	if (tex->game_over.path)
		free(tex->game_over.path);
	if (tex->game_over.img_ptr)
		mlx_destroy_image(game->mlx, tex->game_over.img_ptr);
	if (tex->help_screen.path)
		free(tex->help_screen.path);
	if (tex->help_screen.img_ptr)
		mlx_destroy_image(game->mlx, tex->help_screen.img_ptr);
}

void	free_floor_ceiling(t_game *game)
{
	t_textures	*tex;

	tex = &game->textures;
	if (tex->floor.path)
		free(tex->floor.path);
	if (tex->floor.img_ptr)
		mlx_destroy_image(game->mlx, tex->floor.img_ptr);
	if (tex->ceiling.path)
		free(tex->ceiling.path);
	if (tex->ceiling.img_ptr)
		mlx_destroy_image(game->mlx, tex->ceiling.img_ptr);
}

void	free_str_array(char **str_array)
{
	int	i;

	if (!str_array)
		return ;
	i = 0;
	while (str_array[i])
		free(str_array[i++]);
	free(str_array);
	str_array = NULL;
}

void	free_sprite_frames(t_game *game, t_sprite *sprite)
{
	int	f;

	if (!sprite->frames)
		return ;
	f = 0;
	while (f < sprite->frame_count)
	{
		if (sprite->frames[f])
		{
			if (sprite->frames[f]->img_ptr)
				mlx_destroy_image(game->mlx, sprite->frames[f]->img_ptr);
			free(sprite->frames[f]);
		}
		f++;
	}
	free(sprite->frames);
	sprite->frames = NULL;
}
