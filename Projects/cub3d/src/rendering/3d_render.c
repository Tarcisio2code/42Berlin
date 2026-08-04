/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:29:45 by tsilva            #+#    #+#             */
/*   Updated: 2025/11/04 12:08:01 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"

void	render_wall(t_game *game, int x, int top, int bottom);

void	render_3d_scene(t_game *game)
{
	int		x;
	t_ray	*ray;
	int		top;
	int		bot;

	x = 0;
	ray = &game->ray;
	while (x < WIN_WIDTH)
	{
		init_ray(game, ray, x);
		calc_step_and_side_dist(ray); 	// Calculates step direction and initial distance to next grid line
		perform_dda(game, ray);			// Digital Differential Analysis - finds where ray hits a wall
		calc_wall_height(ray);			// Determines height of wall slice based on distance to hit point
		top = ray->draw_start;
		if (top < 0)
			top = 0;
		bot = ray->draw_end;
		if (bot > WIN_HEIGHT)
			bot = WIN_HEIGHT;
		game->zbuf[x] = ray->perp_wall_dist;
		render_wall(game, x, top, bot);
		render_floor_ceil_column(game, x, top, bot);
		x++;
	}
}

void	render_wall(t_game *game, int x, int top, int bottom)
{
	t_image	*tex;
	t_ray	*ray;
	int		y;
	int		color;
	double	step;

	ray = &game->ray;
	tex = get_wall_texture(game, ray);   // Get the appropriate wall texture based on which wall was hit
	calc_texture_x(&game->ray, tex);     // Calculate the x-coordinate on the texture (where the ray hit the wall)
	step = 1.0 * tex->height / ray->line_height;  // Calculate how much to step through texture for each screen pixel
	ray->tex_pos = (top - WIN_HEIGHT / 2 + ray->line_height / 2) * step;  // Initial texture position with vertical offset

	y = top;                             // Start from the top of the wall slice
	while (y < bottom)                   // Loop through each vertical pixel of the wall slice
	{
		if (y >= 0 && y < WIN_HEIGHT)    // Only render if pixel is within screen bounds
		{
			ray->tex_y = (int)ray->tex_pos & (tex->height - 1);  // Calculate y-coordinate on texture (with wrap-around)
			color = get_texture_color(tex, ray->tex_x, ray->tex_y);  // Get the color from the texture at (tex_x, tex_y)
			put_pixel(&game->win_img, x, y, color);  // Draw the pixel to the screen
		}
		ray->tex_pos += step;            // Move to next vertical texture position
		y++;                             // Move to next screen row
	}
}

