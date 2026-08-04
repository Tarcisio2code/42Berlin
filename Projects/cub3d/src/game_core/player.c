/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:27:14 by tsilva            #+#    #+#             */
/*   Updated: 2025/11/02 08:42:15 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../inc/game_core.h"
#include "../../inc/rendering.h"

static void	check_and_move(t_player *player, t_map *map, t_directions dir);
static bool	set_pos(double *x, double *y, t_player *player, t_directions dir);

void	set_player(t_game *game)
{
	t_player	*player;

	player = &game->player;

	// Convert grid-based map indices (row/col) to precise pixel-based world coordinates.
	// 1. Multiply by TILE_SIZE to reach the top-left corner of the specific map cell.
	// 2. Add TILE_SIZE / 2.0 to shift from the corner to the exact center of the tile,
	//    ensuring the player spawns precisely in the middle of their starting grid cell.	player->x = game->player.col * TILE_SIZE + TILE_SIZE / 2.0;
	player->x = game->player.col * TILE_SIZE + TILE_SIZE / 2.0;
	player->y = game->player.row * TILE_SIZE + TILE_SIZE / 2.0;

	// Set initial player rotation angle (in radians) based on the spawn orientation.
	// North is 270 degrees (3π/2), South is 90 degrees (π/2), West is 180 degrees (π),
	// and East is 0 degrees. These angles align the direction vector with the map orientation.
	if (player->spawn == 'N')
		player->angle = 3 * PI / 2;
	else if (player->spawn == 'S')
		player->angle = PI / 2;
	else if (player->spawn == 'W')
		player->angle = PI;
	else if (player->spawn == 'E')
		player->angle = 0;

	// Calculate initial unit direction vector (look vector) using trigonometry.
	player->dir_x = cos(player->angle);
	player->dir_y = sin(player->angle);

	// Configure camera plane and field of view for raycasting projections.
	player->fov_deg = 66.0;
	set_fov(game, player->fov_deg);
}

void	move_player(t_game *game, t_directions dir)
{
	t_player	*player;

	player = &game->player;
	if (dir == MOVE_FORWARD)
		check_and_move(player, game->map, dir);
	else if (dir == MOVE_BACKWARD)
		check_and_move(player, game->map, dir);
	else if (dir == STRAFE_LEFT)
		check_and_move(player, game->map, dir);
	else if (dir == STRAFE_RIGHT)
		check_and_move(player, game->map, dir);
	else if (dir == TURN_LEFT)
		rotate_player(player, -ROTATE_SPEED);
	else if (dir == TURN_RIGHT)
		rotate_player(player, ROTATE_SPEED);
	else
		return ;
	game->refresh_screen = true;
}

static void	check_and_move(t_player *player, t_map *map, t_directions dir)
{
	double	new_x;
	double	new_y;

	// Calculate target position based on movement direction.
	if (!set_pos(&new_x, &new_y, player, dir))
		return ;

	// Collision detection: check both X and Y axes independently to allow 'sliding' along walls.
	// We check a small radius around the player to ensure they don't clip into wall boundaries.
	if (!wall_collision(map, new_x + PLAYER_RADIUS, player->y) 
		&& !wall_collision(map, new_x - PLAYER_RADIUS, player->y))
		player->x = new_x;
	if (!wall_collision(map, player->x, new_y + PLAYER_RADIUS) 
		&& !wall_collision(map, player->x, new_y - PLAYER_RADIUS))
		player->y = new_y;
}

static bool	set_pos(double *x, double *y, t_player *player, t_directions dir)
{
	// Calculate new coordinates using trigonometric movement vectors (Direction vs Strafe).
	if (dir == MOVE_FORWARD)
	{
		*x = player->x + cos(player->angle) * MOVE_SPEED;
		*y = player->y + sin(player->angle) * MOVE_SPEED;
	}
	else if (dir == MOVE_BACKWARD)
	{
		*x = player->x - cos(player->angle) * MOVE_SPEED;
		*y = player->y - sin(player->angle) * MOVE_SPEED;
	}
	else if (dir == STRAFE_LEFT)
	{
		*x = player->x + sin(player->angle) * MOVE_SPEED;
		*y = player->y - cos(player->angle) * MOVE_SPEED;
	}
	else if (dir == STRAFE_RIGHT)
	{
		*x = player->x - sin(player->angle) * MOVE_SPEED;
		*y = player->y + cos(player->angle) * MOVE_SPEED;
	}
	else
		return (false);
	return (true);
}

void	rotate_player(t_player *p, double r_speed)
{
	double	old_x;
	double	old_y;

	// Apply 2D Rotation Matrix to update direction and camera plane vectors.
	// This ensures smooth rotation of the camera view in 3D space.
	old_x = p->dir_x;
	p->dir_x = p->dir_x * cos(r_speed) - p->dir_y * sin(r_speed);
	p->dir_y = old_x * sin(r_speed) + p->dir_y * cos(r_speed);
	old_y = p->plane_x;
	p->plane_x = p->plane_x * cos(r_speed) - p->plane_y * sin(r_speed);
	p->plane_y = old_y * sin(r_speed) + p->plane_y * cos(r_speed);

	// Update and normalize angle within the [0, 2π] range for state consistency.
	p->angle += r_speed;
	if (p->angle < 0)
		p->angle += 2 * PI;
	if (p->angle >= 2 * PI)
		p->angle -= 2.0 * PI;
}
