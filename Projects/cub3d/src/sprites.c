/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:31:01 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/11/04 12:10:33 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/parse_and_validation.h"
#include "../inc/game_core.h"

// 2 for collectibles
int	count_sprites(t_map *map)
{
	int	r;
	int	c;
	int	count;

	count = 0;
	r = 0;
	while (map->data[r])
	{
		c = 0;
		while (map->data[r][c])
		{
			if (map->data[r][c] == '2')
				count++;
			c++;
		}
		r++;
	}
	return (count);
}

void	place_sprite(t_game *game, int r, int c, int *k)
{
	game->sprites[*k].x = c * TILE_SIZE + TILE_SIZE / 2.0;
	game->sprites[*k].y = r * TILE_SIZE + TILE_SIZE / 2.0;
	game->sprites[*k].alive = true;
	game->sprites[*k].curr_frame = 0;
	game->sprites[*k].frame_time = 0.12;
	game->sprites[*k].last_time = get_time();
	game->map->data[r][c] = '0';
	(*k)++;
}

void	scan_and_place_sprites(t_game *game)
{
	int	r;
	int	c;
	int	k;

	k = 0;
	r = 0;
	while (game->map->data[r])
	{
		c = 0;
		while (game->map->data[r][c])
		{
			if (game->map->data[r][c] == '2')
				place_sprite(game, r, c, &k);
			c++;
		}
		r++;
	}
}

void	find_sprites(t_game *game)
{
	int	count;

	count = count_sprites(game->map);
	game->sprite_count = count;
	if (game->sprite_count == 0)
		return ;
	game->sprites = ft_calloc(game->sprite_count, sizeof(t_sprite));
	if (!game->sprites)
		exit_clean(ERR_MALLOC, game);
	scan_and_place_sprites(game);
}

void	load_sprite_frames(t_game *game, t_sprite *sp, char **paths, int n)
{
	int	i;

	sp->frames = malloc(sizeof(t_image *) * n);
	if (!sp->frames)
		exit_clean (ERR_MALLOC, game);
	sp->frame_count = 0;
	i = 0;
	while (i < n)
	{
		if (!check_file((char *)paths[i]))
			exit_clean(ERR_LOAD_TEXTURE, game);
		sp->frames[i] = malloc(sizeof(t_image));
		ft_memset(sp->frames[i], 0, sizeof(t_image));
		sp->frames[i]->path = ft_strdup(paths[i]);
		if (!sp->frames[i]->path)
			exit_clean(ERR_LOAD_TEXTURE, game);
		set_texture_img(game, sp->frames[i]);
		sp->frame_count++;
		i++;
	}
}
