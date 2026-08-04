/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_core.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 19:00:30 by tsilva            #+#    #+#             */
/*   Updated: 2025/11/01 12:40:36 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CORE_H
# define GAME_CORE_H

# include "../inc/cub3d.h"
# include <math.h>
# include "../inc/structs.h"

# define WIN_TITLE "Welcome to CUB3D"
# define ERR_MLX "Failed to initialize the MLX library."
# define ERR_MLX_WIN "Window creation failed."
# define ERR_MLX_IMG_PTR "Image allocation failed."
# define ERR_MAP_DATA "No map data found."
# define ERR_LOAD_TEXTURE "Failed to load texture from file."
# define WIN_WIDTH 1200
# define WIN_HEIGHT 720
# define TILE_SIZE 64
# define PLAYER_RADIUS 2.0
# define MOVE_SPEED 8.0
# define ROTATE_SPEED 0.1
# define PI	3.14159265359
# define NUM_RAYS 60
# define MINI_TILE_SIZE 10
# define MINI_PLAYER_SIZE 4
# define MOUSE_SENS 0.006

# define GREEN 0xFF25D366
# define BLUE 0xFF355685
# define RED 0xFF0000
# define YELLOW 0xFFAA00
# define GRAY 0xFFCCCCCC
# define BLACK 0xFF000000
# define WHITE 0xFFFFFFFF
# define DARK_GREEN 0xFF09391B
# define DARK_BLUE 0xFF00060B
# define DARK_GRAY 0x5A5A5A
# define DARK_RED 0x5A0000

// FOV limits and step (degrees) for zoom
# define FOV_MIN 30.0
# define FOV_MAX 100.0
# define FOV_STEP 5.0
# define BTN_WHEEL_UP 4
# define BTN_WHEEL_DOWN 5

int		close_game(t_game *game);
void	init_core(t_game *game);
void	set_img_data(t_image *image);
void	start_game(t_game *game);
bool	wall_collision(t_map *map, double x, double y);
int		key_press(int key, t_game *game);
void	set_player(t_game *game);
void	move_player(t_game *game, t_directions dir);
void	load_textures(t_game *game);
void	set_texture_img(t_game *game, t_image *texture);
void	init_door(t_game *game);
void	change_door_state(t_game *game);
void	animate_door(t_game *game);
void	rotate_player(t_player *p, double r_speed);
int		mouse_move(int x, int y, t_game *game);
void	set_fov(t_game *game, double fov_deg);
void	init_sprites(t_game *game);
void	animate_sprites(t_game *game);

#endif