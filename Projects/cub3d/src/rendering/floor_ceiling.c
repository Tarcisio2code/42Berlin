/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:34:13 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/11/03 18:24:32 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/floor_ceiling.h"

/* --- Floor and Ceiling Rendering Engine ---

This module handles the floor/ceiling projection using affine

texture mapping and trigonometry-based coordinate mapping.
*/

// Renders solid color columns for floor and ceiling when no textures are provided.
void	render_floor_ceil_color_column(t_game *game, int x, int top, int bot)
{
	int	y;

	// Draw ceiling segment.
	y = 0;
	while (y < top)
	{
		put_pixel(&game->win_img, x, y, argb_color(game->ceiling_color));
		y++;
	}

	// Draw floor segment.
	y = bot;
	while (y < WIN_HEIGHT)
	{
		put_pixel(&game->win_img, x, y, argb_color(game->floor_color));
		y++;
	}
}

// Fallback method for rendering flat ceiling colors if texture sampling is disabled.
static void	render_untextured_ceiling(t_game *game, int x, int top)
{
	int	y;

	y = 0;
	while (y < top)
	{
		put_pixel(&game->win_img, x, y, argb_color(game->ceiling_color));
		y++;
	}
}

// Maps floor-relative coordinates to ceiling counterparts to mirror texture sampling.
static void	draw_floor_ceil_rows(t_game *game, t_floor_params *p,
	int top, bool use_ceiling)
{
	int	y2;

	p->textured = use_ceiling;
	// Calculate mirror row coordinate for ceiling texture.
	y2 = WIN_HEIGHT - 1 - p->y;
	if (y2 >= 0 && y2 < top)
	{
		p->y = y2;
		draw_ceiling_row(game, p);
	}
}

// Vertical column rendering for textured floor and ceiling surfaces.
void	render_floor_ceil_textured_column(t_game *game, int x, int top,
	int bot)
{
	t_floor_params	p;
	bool			use_floor;
	bool			use_ceiling;
	int				y;

	use_floor = game->textures.floor.img_ptr != NULL;
	use_ceiling = game->textures.ceiling.img_ptr != NULL;
	p = floor_row_params(game, &game->ray);
	p.x = x;
	y = bot;
	while (y < WIN_HEIGHT)
	{
		p.y = y;
		p.textured = use_floor;
		draw_floor_row(game, &p);
		draw_floor_ceil_rows(game, &p, top, use_ceiling);
		y++;
	}
	// Handle missing ceiling texture.
	if (!use_ceiling)
		render_untextured_ceiling(game, x, top);
}

// Gateway function to choose between solid color or textured rendering pipelines.
void	render_floor_ceil_column(t_game *game, int x, int top, int bot)
{
	if (!game->textures.floor.img_ptr && !game->textures.ceiling.img_ptr)
	{
		render_floor_ceil_color_column(game, x, top, bot);
		return ;
	}
	render_floor_ceil_textured_column(game, x, top, bot);
}
