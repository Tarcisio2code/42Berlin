/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:03:43 by tsilva            #+#    #+#             */
/*   Updated: 2025/11/03 17:56:55 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"

void	init_ray(t_game *game, t_ray *ray, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)WIN_WIDTH - 1; // Convert screen x(column) to camera plane x (-1 to 1)

	// Ray starts at player position
	ray->pos_x = game->player.x;
	ray->pos_y = game->player.y;

	// Calculate ray direction
	ray->dir_x = game->player.dir_x + game->player.plane_x * camera_x;
	ray->dir_y = game->player.dir_y + game->player.plane_y * camera_x;
}

/*
** Digital Differential Analysis (DDA) initialization:
** This tells us how far the ray travels to hit the first gridline (x or y) and in what direction.
** This function prepares the ray for DDA by:
** 1. Calculating delta distances (distance between x or y intersections)
** 2. Getting initial map position (which grid cell the ray is in)
** 3. Determining step direction (which way to move in grid: -1 or +1)
** 4. Computing initial side distances (distance to first x and y intersections)
** This setup enables efficient ray traversal through the grid-based map
*/
void	calc_step_and_side_dist(t_ray *r)
{
	r->dt_dist_x = fabs(1 / r->dir_x);
	r->dt_dist_y = fabs(1 / r->dir_y);
	r->map_x = (int)(r->pos_x / TILE_SIZE);
	r->map_y = (int)(r->pos_y / TILE_SIZE);
	if (r->dir_x < 0)
	{
		r->step_x = -1;
		r->sd_dist_x = (r->pos_x / TILE_SIZE - r->map_x) * r->dt_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->sd_dist_x = (r->map_x + 1.0 - r->pos_x / TILE_SIZE) * r->dt_dist_x;
	}
	if (r->dir_y < 0)
	{
		r->step_y = -1;
		r->sd_dist_y = (r->pos_y / TILE_SIZE - r->map_y) * r->dt_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->sd_dist_y = (r->map_y + 1.0 - r->pos_y / TILE_SIZE) * r->dt_dist_y;
	}
}

/*
** Digital Differential Analysis (DDA) Implementation
** This loop "walks" through the grid until it hits a wall.
** This function performs the actual ray traversal through the map grid by:
** 1. Checking whether to move in x or y direction (shortest distance)
** 2. Updating the ray's position in the grid
** 3. Recording which wall side was hit (N/S or E/W)
** 4. Checking for collisions with walls or map boundaries
**
** The DDA algorithm ensures we only check grid cells the ray actually passes through,
** making it much more efficient than checking every pixel along the ray's path.
*/
void	perform_dda(t_game *game, t_ray *ray)
{
	while (true)
	{
		// Compare distances to next vertical (sd_dist_x) and horizontal (sd_dist_y) grid lines
		if (ray->sd_dist_x < ray->sd_dist_y)
		{
			ray->sd_dist_x += ray->dt_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sd_dist_y += ray->dt_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}

		// Check if ray has gone outside map boundaries
		if (ray->map_y < 0 || ray->map_x < 0 || 
			ray->map_y >= game->map->height || 
			ray->map_x >= game->map->width)
			break ;

		// Check if ray hit a wall ('1'), door ('D'), or partially open door ('X')
		if (game->map->data[ray->map_y][ray->map_x] == '1'
			|| game->map->data[ray->map_y][ray->map_x] == 'D'
			|| game->map->data[ray->map_y][ray->map_x] == 'X')
			break ;
	}
}

/*
** Wall Height Calculator
** This function calculates the height and screen position of wall slices by:
** 1. Computing perpendicular wall distance to avoid fisheye effect:
**    - For vertical walls (side=0): Uses x-coordinate differences
**    - For horizontal walls (side=1): Uses y-coordinate differences
** 2. Calculating wall height inversely proportional to distance
** 3. Computing start and end points for drawing the wall slice on screen
**    - Centers the wall vertically on screen
**    - Taller walls when closer, shorter walls when further away
*/
void	calc_wall_height(t_ray *ray)
{
	if (ray->side == 0) // the ray hits the vertical wall
		ray->perp_wall_dist = ((ray->map_x * TILE_SIZE - ray->pos_x) 
				+ ((1 - ray->step_x) * TILE_SIZE / 2)) / ray->dir_x;
	else				// the ray hits the horizontal wall
		ray->perp_wall_dist = ((ray->map_y * TILE_SIZE - ray->pos_y)
				+ ((1 - ray->step_y) * TILE_SIZE / 2)) / ray->dir_y;
	ray->line_height = (int)(WIN_HEIGHT / (ray->perp_wall_dist / TILE_SIZE));
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
}

/*
** Texture X-Coordinate Calculator
** This function determines where on the wall texture to sample for each vertical strip:
** 1. Calculate exact hit point on the wall (wall_x):
**    - For vertical walls: Use y-coordinate of hit point
**    - For horizontal walls: Use x-coordinate of hit point
** 2. Convert wall_x to a fraction (0-1) by:
**    - Dividing by TILE_SIZE to normalize
**    - Subtracting floor to get fractional part
** 3. Convert fraction to texture coordinate:
**    - Multiply by texture width to get pixel position
** 4. Mirror texture if needed based on wall orientation:
**    - For west-facing walls (dir_x < 0)
**    - For north-facing walls (dir_y > 0)
*/
void	calc_texture_x(t_ray *ray, t_image *tex)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = ray->pos_y + ray->perp_wall_dist * ray->dir_y;
	else
		wall_x = ray->pos_x + ray->perp_wall_dist * ray->dir_x;
	wall_x /= TILE_SIZE;
	wall_x -= floor(wall_x);
	ray->tex_x = (int)(wall_x * tex->width);
	if ((ray->side == 0 && ray->dir_x < 0) 
		|| (ray->side == 1 && ray->dir_y > 0))
		ray->tex_x = tex->width - ray->tex_x - 1;
}
