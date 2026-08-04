/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   banner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:40:18 by tsilva            #+#    #+#             */
/*   Updated: 2025/11/03 17:57:45 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"

static bool	draw_banner_box(t_game *game, t_image *tex, int x, int y);

void	render_help_screen(t_game *game)
{
	int		y;
	int		x;
	t_image	*tex;

	tex = &game->textures.help_screen;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			draw_banner_box(game, tex, x, y);
			x++;
		}
		y++;
	}
}

void	render_game_over_screen(t_game *game)
{
	int		y;
	int		x;
	t_image	*tex;

	tex = &game->textures.game_over;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (!draw_banner_box(game, tex, x, y))
				draw_transparent_background(game, x, y, RED);
			x++;
		}
		y++;
	}
}

static bool	draw_banner_box(t_game *game, t_image *tex, int x, int y)
{
	int		tex_x;
	int		tex_y;
	int		color;
	int		start_x;
	int		start_y;

	start_x = (WIN_WIDTH - tex->width) / 2;
	start_y = (WIN_HEIGHT - tex->height) / 2;
	if (x >= start_x && x < start_x + tex->width
		&& y >= start_y && y < start_y + tex->height)
	{
		tex_x = x - start_x;
		tex_y = y - start_y;
		color = get_texture_color(tex, tex_x, tex_y);
		put_pixel(&game->win_img, x, y, color);
	}
	else
		return (false);
	return (true);
}
