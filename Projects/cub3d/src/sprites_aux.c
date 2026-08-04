/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 18:11:17 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/11/03 16:19:58 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/parse_and_validation.h"
#include "../inc/game_core.h"

static void	init_coin_paths(char **paths)
{
	paths[0] = "textures/coin0.xpm";
	paths[1] = "textures/coin1.xpm";
	paths[2] = "textures/coin2.xpm";
	paths[3] = "textures/coin3.xpm";
	paths[4] = "textures/coin4.xpm";
	paths[5] = "textures/coin5.xpm";
}

void	init_sprites(t_game *game)
{
	int			i;
	t_sprite	*s;
	char		*coin_paths[6];

	init_coin_paths(coin_paths);
	if (game->sprite_count == 0 || !game->sprites)
		return ;
	i = 0;
	while (i < game->sprite_count)
	{
		s = &game->sprites[i];
		s->alive = true;
		s->scale = 40.0;
		load_sprite_frames(game, s, coin_paths, 6);
		s->curr_frame = 0;
		s->frame_count = 6;
		s->frame_time = 0.08;
		s->last_time = get_time();
		i++;
	}
}

void	animate_sprites(t_game *game)
{
	double		now;
	int			i;
	t_sprite	*s;

	i = 0;
	now = get_time();
	while (i < game->sprite_count)
	{
		s = &game->sprites[i];
		if (!s->alive || s->frame_count <= 1)
		{
			i++;
			continue ;
		}
		if (now - s->last_time >= s->frame_time)
		{
			s->last_time = now;
			s->curr_frame = (s->curr_frame + 1) % s->frame_count;
			game->refresh_screen = true;
		}
		i++;
	}
}
