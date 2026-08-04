/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 19:21:53 by tsilva            #+#    #+#             */
/*   Updated: 2025/11/04 12:05:05 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdbool.h>

typedef struct s_map
{
	char	**data;
	char	*line;
	int		height;
	int		width;
	int		mini_x;
	int		mini_y;
	bool	walkable;
}				t_map;

typedef struct s_image
{
	char	*path;	
	void	*img_ptr;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}				t_image;

typedef struct s_textures
{
	t_image	north;
	t_image	south;
	t_image	east;
	t_image	west;
	t_image	door;
	t_image	game_over;
	t_image	help_screen;
	t_image	floor;
	t_image	ceiling;
}				t_textures;

typedef struct s_player
{
	char	spawn;
	int		row;
	int		col;
	double	x;
	double	y;
	double	angle;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	fov_deg;
}				t_player;

typedef struct s_ray
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	dt_dist_x;
	double	dt_dist_y;
	double	sd_dist_x;
	double	sd_dist_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_x;
	int		tex_y;
	double	tex_pos;
}				t_ray;

typedef struct s_door
{
	t_image	**frames;
	int		curr_frame;
	int		last_frame;
	int		x;
	int		y;
	double	wait_time;
	double	last_time;
	double	current_time;
	bool	exploding;

}				t_door;

// scale 1.0 normal, >1 bigger
typedef struct s_sprite
{
	double	x;
	double	y;
	t_image	**frames;
	int		frame_count;
	int		curr_frame;
	double	frame_time;
	double	last_time;
	bool	alive;
	double	scale;
	double	invd;
}			t_sprite;

typedef struct s_sprite_proj
{
	double	t_y;
	int		screen_x;
	int		size;
	int		start_x;
	int		end_x;
	int		start_y;
	int		end_y;
}			t_sprite_proj;

typedef struct s_game
{
	int			scene_file;
	int			floor_color[3];
	int			ceiling_color[3];
	void		*mlx;
	void		*win;
	bool		show_mini_map;
	bool		show_help_screen;
	bool		refresh_screen;
	bool		is_running;
	bool		has_doors;
	bool		game_over;
	int			last_mouse_x;
	bool		mouse_initted;
	t_map		*map;
	t_image		win_img;
	t_player	player;
	t_textures	textures;
	t_ray		ray;
	t_door		door;
	t_sprite	*sprites;
	int			sprite_count;
	double		*zbuf;
	int			score;
}				t_game;

typedef enum e_directions
{
	MOVE_FORWARD,
	MOVE_BACKWARD,
	STRAFE_LEFT,
	STRAFE_RIGHT,
	TURN_LEFT,
	TURN_RIGHT,
}				t_directions;

typedef enum e_banner
{
	HELP_SCREEN,
	GAME_OVER,
}			t_banner;

#endif