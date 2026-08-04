/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling_aux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:34:13 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/11/03 18:24:30 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/floor_ceiling.h"

// Calculates the precise 2D world-space intersection point where the floor ray
// hits the wall. This is a critical prerequisite for perspective-correct mapping.
void	floor_wall_point(t_ray *ray, double *wx, double *wy)
{
	if (ray->side == 0)
	{
		if (ray->step_x < 0)
			*wx = (ray->map_x + 1) * TILE_SIZE;
		else
			*wx = ray->map_x * TILE_SIZE;
		*wy = ray->pos_y + ray->perp_wall_dist * ray->dir_y;
	}
	else
	{
		if (ray->step_y < 0)
			*wy = (ray->map_y + 1) * TILE_SIZE;
		else
			*wy = ray->map_y * TILE_SIZE;
		*wx = ray->pos_x + ray->perp_wall_dist * ray->dir_x;
	}
}

// Packages the geometric parameters required for floor rendering:
// Normalizes the player position and wall contact points into grid-relative units
// to simplify the linear interpolation calculations in subsequent passes.
t_floor_params	floor_row_params(t_game *game, t_ray *r)
{
	double			wx;
	double			wy;
	t_floor_params	p;

	floor_wall_point(r, &wx, &wy);
	p.px = game->player.x / TILE_SIZE;
	p.py = game->player.y / TILE_SIZE;
	p.bx = wx / TILE_SIZE;
	p.by = wy / TILE_SIZE;
	p.wall_dist_tiles = r->perp_wall_dist / TILE_SIZE;
	if (p.wall_dist_tiles <= 0.0)
		p.wall_dist_tiles = 1e-6;
	return (p);
}

// Implements the projection math to translate screen-space Y-rows into world-space (X, Y).
// Uses the wall distance ratio to perform linear interpolation across the screen span.
static void	calc_world_coords(t_floor_calc *fc, t_floor_params *p)
{
	fc->row_dist = (WIN_HEIGHT / 2.0) / fc->denom;
	fc->w = fc->row_dist / p->wall_dist_tiles;
	fc->world_x = (1.0 - fc->w) * p->px + fc->w * p->bx;
	fc->world_y = (1.0 - fc->w) * p->py + fc->w * p->by;
}

// Renders a horizontal floor scanline using texture coordinate sampling.
// Checks for texturing flags and applies color interpolation or direct pixel mapping.
void	draw_floor_row(t_game *game, t_floor_params *p)
{
	t_floor_calc	fc;

	fc.denom = p->y - WIN_HEIGHT / 2.0;
	if (fc.denom == 0.0)
		return ;
	calc_world_coords(&fc, p);
	if (p->textured)
	{
		fc.tx = (int)(fc.world_x * game->textures.floor.width);
		fc.ty = (int)(fc.world_y * game->textures.floor.height);
		fc.col = get_texture_color(&game->textures.floor, fc.tx, fc.ty);
		put_pixel(&game->win_img, p->x, p->y, fc.col);
	}
	else
		put_pixel(&game->win_img, p->x, p->y, argb_color(game->floor_color));
}

// Renders a horizontal ceiling scanline, mirroring floor logic with vertical inversion.
// Treats ceiling as a projection symmetric to the floor along the horizontal horizon line.
void	draw_ceiling_row(t_game *game, t_floor_params *p)
{
	t_floor_calc	fc;

	if (p->y < 0 || p->y >= WIN_HEIGHT)
		return ;
	fc.denom = ((WIN_HEIGHT - 1 - p->y) - WIN_HEIGHT / 2.0);
	if (fc.denom == 0.0)
		return ;
	calc_world_coords(&fc, p);
	if (p->textured)
	{
		fc.tx = (int)(fc.world_x * game->textures.ceiling.width);
		fc.ty = (int)(fc.world_y * game->textures.ceiling.height);
		fc.col = get_texture_color(&game->textures.ceiling, fc.tx, fc.ty);
		put_pixel(&game->win_img, p->x, p->y, fc.col);
	}
	else
		put_pixel(&game->win_img, p->x, p->y, argb_color(game->ceiling_color));
}
