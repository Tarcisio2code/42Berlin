/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:10:10 by tsilva            #+#    #+#             */
/*   Updated: 2025/11/03 17:57:51 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"

static void	draw_mini_box(t_game *game, int y, int x, int color);
static void	mini_ray_casting(t_game *game);
static void	draw_ray(t_game *game, int ray, double angle, double angle_step);
static void	draw_mini_player(t_game *game, int start_x, int start_y);

void	draw_mini_map(t_game *game)
{
	int	x;
	int	y;
	int	s_x;
	int	s_y;

	y = -1;
	while (++y < game->map->height)
	{
		x = -1;
		while (++x < game->map->width)
		{
			s_y = game->map->mini_y + y * MINI_TILE_SIZE;
			s_x = game->map->mini_x + x * MINI_TILE_SIZE;
			if (game->map->data[y][x] != '1' && game->map->data[y][x] != ' '
				&& game->map->data[y][x] != 'D' && game->map->data[y][x] != 'X')
				draw_transparent_box(game, s_x, s_y, DARK_GREEN);
			if (game->map->data[y][x] == '1')
				draw_mini_box(game, s_x, s_y, DARK_GRAY);
			if (game->map->data[y][x] == 'D')
				draw_mini_box(game, s_x, s_y, DARK_RED);
		}
	}
	mini_ray_casting(game);
	draw_mini_player(game, game->map->mini_x, game->map->mini_y);
}

static void	draw_mini_box(t_game *game, int x, int y, int color)
{
	int	px;
	int	py;

	py = 0;
	while (py < MINI_TILE_SIZE)
	{
		px = 0;
		while (px < MINI_TILE_SIZE)
		{
			put_pixel(&game->win_img, x + px, y + py, color);
			px++;
		}
		py++;
	}
}

static void	draw_mini_player(t_game *game, int start_x, int start_y)
{
	int			px;
	int			py;
	double		player_x;
	double		player_y;
	t_player	*player;

	py = 0;
	player = &game->player;
	// Convert player's world x,y-coordinate to minimap scale:
	// 1. Divide by TILE_SIZE to get position in map grid coordinates
	// 2. Multiply by MINI_TILE_SIZE to scale to minimap size
	// 3. Add start_x offset to position minimap in window
	player_x = start_x + (int)(player->x / TILE_SIZE * MINI_TILE_SIZE);
	player_y = start_y + (int)(player->y / TILE_SIZE * MINI_TILE_SIZE);

	// Center the player marker by subtracting half its size
	player_x -= MINI_PLAYER_SIZE / 2;
	player_y -= MINI_PLAYER_SIZE / 2;
	while (py < (MINI_PLAYER_SIZE))
	{
		px = 0;
		while (px < (MINI_PLAYER_SIZE))
		{
			put_pixel(&game->win_img, player_x + px, player_y + py, WHITE);
			px++;
		}
		py++;
	}
}

static void	mini_ray_casting(t_game *game)
{
	double	angle;
	double	angle_step;
	double	fov;
	int		ray;

	ray = 0;
	fov = PI / 3;                           // Set field of view to 60 degrees (π/3 radians)
	angle = game->player.angle - (fov / 2);  // Calculate starting angle (player angle minus half FOV)
	angle_step = fov / NUM_RAYS;            // Calculate angle increment between each ray

	while (ray < NUM_RAYS)
	{
		draw_ray(game, ray, angle, angle_step);
		ray++;
	}
}

static void	draw_ray(t_game *game, int ray, double angle, double angle_step)
{
	double	ray_angle;
	double	ray_x;
	double	ray_y;
	int		x;
	int		y;	

	ray_x = game->player.x;
	ray_y = game->player.y;
	ray_angle = angle + ray * angle_step; // Calculate actual angle for this ray based on starting angle and ray number
	while (true)
	{
		if (wall_collision(game->map, ray_x, ray_y))
			break ;

		// Convert world coordinates to minimap coordinates
		x = game->map->mini_x + (int)(ray_x / TILE_SIZE * MINI_TILE_SIZE);
		y = game->map->mini_y + (int)(ray_y / TILE_SIZE * MINI_TILE_SIZE);
		put_pixel(&game->win_img, x, y, BLUE);

		// Extend ray by one unit in its direction using trigonometry
		// If ray_angle is 0°, cos=1 and sin=0, so the ray moves only horizontally
		// If ray_angle is 90°, cos=0 and sin=1, so the ray moves only vertically
		ray_x += cos(ray_angle) * 1.0;
		ray_y += sin(ray_angle) * 1.0;
	}
}