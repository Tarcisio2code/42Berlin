/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:51:00 by tsilva            #+#    #+#             */
/*   Updated: 2025/09/29 18:09:51 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/game_core.h"

static void	load_door_frames(t_game *game, char **paths);
static bool	door_near_player(t_player *player, t_door *door);

void	init_door(t_game *game)
{
	char	*paths[9];

	if (!game->has_doors)
		return ;
	game->door.frames = (t_image **)malloc(sizeof(t_image *) * 9);
	if (!game->door.frames)
		exit_clean(ERR_MALLOC, game);
	paths[0] = "textures/door_explosion_0.xpm";
	paths[1] = "textures/door_explosion_1.xpm";
	paths[2] = "textures/door_explosion_2.xpm";
	paths[3] = "textures/door_explosion_3.xpm";
	paths[4] = "textures/door_explosion_4.xpm";
	paths[5] = "textures/door_explosion_5.xpm";
	paths[6] = "textures/door_explosion_6.xpm";
	paths[7] = "textures/door_explosion_7.xpm";
	paths[8] = "textures/door_explosion_8.xpm";
	game->door.last_frame = -1;
	game->door.curr_frame = 0;
	game->door.x = 0;
	game->door.y = 0;
	game->door.wait_time = 1.0;
	game->door.last_time = get_time();
	game->door.current_time = game->door.last_time;
	load_door_frames(game, paths);
}

static void	load_door_frames(t_game *game, char **paths)
{
	int		i;

	i = 0;
	while (i < 9)
	{
		if (!check_file(paths[i]))
			exit_clean(ERR_LOAD_TEXTURE, game);
		game->door.frames[i] = (t_image *)malloc(sizeof(t_image));
		if (!game->door.frames[i])
			exit_clean(ERR_MALLOC, game);
		game->door.last_frame = i;
		ft_memset(game->door.frames[i], 0, sizeof(t_image)); // Initialize the new t_image structure memory to zero.
															 // Clears the garbage data by setting every single byte in the allocated block to 0.
		game->door.frames[i]->path = ft_strdup(paths[i]);
		if (!game->door.frames[i]->path)
			exit_clean(ERR_MALLOC, game);
		set_texture_img(game, game->door.frames[i]); // Load the actual image data into memory
		i++;
	}
}

void	change_door_state(t_game *game)
{
	double	look_x;
	double	look_y;
	int		map_x;
	int		map_y;

	if (game->door.exploding)
		return ;
	look_x = game->player.x + cos(game->player.angle) * 50;
	look_y = game->player.y + sin(game->player.angle) * 50;
	map_x = (int)(look_x / TILE_SIZE);
	map_y = (int)(look_y / TILE_SIZE);
	if (map_x < 0 || map_y < 0 || map_y >= game->map->height 
		|| map_x >= game->map->width)
		return ;
	if (game->map->data[map_y][map_x] == 'D')
	{
		game->map->data[map_y][map_x] = 'X';
		game->door.x = map_x;
		game->door.y = map_y;
		game->door.curr_frame++;
		game->door.exploding = True;
		game->refresh_screen = True;
	}
}

void	animate_door(t_game *game)
{
	if (!game->door.exploding)
		return ;
	game->door.current_time = get_time();
	if (game->door.curr_frame > 3 && game->door.wait_time == 1.0)
		game->door.wait_time = 0.08;
	if (game->door.current_time - game->door.last_time >= game->door.wait_time)
	{
		game->door.last_time = game->door.current_time;
		game->door.curr_frame++;
		if (game->door.curr_frame > game->door.last_frame)
		{
			game->door.wait_time = 1.0;
			game->door.curr_frame = 0;
			game->door.last_time = get_time();
			game->door.exploding = false;
			game->map->data[game->door.y][game->door.x] = '0';
			game->game_over = door_near_player(&game->player, &game->door);
		}
		game->refresh_screen = true;
	}
}

static bool	door_near_player(t_player *player, t_door *door)
{
	double	door_px;
	double	door_py;
	double	dx;
	double	dy;
	double	distance;

	door_px = door->x * TILE_SIZE + TILE_SIZE / 2.0;
	door_py = door->y * TILE_SIZE + TILE_SIZE / 2.0;
	dx = player->x - door_px;
	dy = player->y - door_py;
	distance = sqrt(dx * dx + dy * dy);
	return (distance <= 90);
}
