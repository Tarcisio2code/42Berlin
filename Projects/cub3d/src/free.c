/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 18:07:01 by tsilva            #+#    #+#             */
/*   Updated: 2025/11/04 12:10:08 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	free_textures(t_game *game);
static void	free_doors(t_game *game);
static void	free_sprites(t_game *game);
static void	free_window(t_game *game);

void	free_vars(t_game *game)
{
	if (game->map)
	{
		if (game->map->data)
			free_str_array(game->map->data);
		if (game->map->line)
			free(game->map->line);
		free(game->map);
		game->map = NULL;
	}
	free_textures(game);
	free_doors(game);
	free_sprites(game);
	free_window(game);
	if (game->zbuf)
	{
		free(game->zbuf);
		game->zbuf = NULL;
	}
}

static void	free_textures(t_game *game)
{
	free_wall_textures(game);
	free_ui_textures(game);
	free_floor_ceiling(game);
}

static void	free_doors(t_game *game)
{
	int	i;

	if (!game->door.frames)
		return ;
	i = 0;
	while (i <= game->door.last_frame)
	{
		if (game->door.frames[i])
		{
			if (game->door.frames[i]->path)
				free(game->door.frames[i]->path);
			if (game->door.frames[i]->img_ptr)
				mlx_destroy_image(game->mlx, game->door.frames[i]->img_ptr);
			free(game->door.frames[i]);
		}
		i++;
	}
	free(game->door.frames);
}

static void	free_sprites(t_game *game)
{
	int			i;
	t_sprite	*s;

	if (!game || !game->sprites || game->sprite_count <= 0)
		return ;
	i = 0;
	while (i < game->sprite_count)
	{
		s = &game->sprites[i];
		free_sprite_frames(game, s);
		i++;
	}
	free(game->sprites);
	game->sprites = NULL;
	game->sprite_count = 0;
}

static void	free_window(t_game *game)
{
	if (!game->mlx)
		return ;
	if (game->win)
	{
		if (game->win_img.img_ptr)
			mlx_destroy_image(game->mlx, game->win_img.img_ptr);
		mlx_destroy_window(game->mlx, game->win);
	}
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}
