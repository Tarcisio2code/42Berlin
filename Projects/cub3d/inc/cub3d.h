/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 23:11:36 by tsilva            #+#    #+#             */
/*   Updated: 2025/06/23 17:48:56 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <sys/types.h>
# include <sys/time.h>
# include <fcntl.h>
# include <errno.h>
# include "../inc/structs.h"
# include "../lib/libft/src/libft.h"
# include "../lib/mlx/mlx.h"
# include "../lib/mlx/mlx_int.h"
# include "../src/gnl/get_next_line.h"

# define ERR_SCENE_FILE		"Invalid scene file name or extension."
# define ERR_FILE_NOT_OPEN	"Could not open the scene file."
# define ERR_ARG			"Invalid argument."
# define ERR_MALLOC			"Malloc failed."

void	check_entry(char *map_name, int argc);
void	exit_clean(char *error_msg, t_game *game);
void	init_game_vars(char *filename, t_game *game);
bool	check_file(char *filepath);
bool	is_file_empty(int fd);
bool	validate_texture_file(char *filepath);
void	free_vars(t_game *game);
void	free_wall_textures(t_game *game);
void	free_ui_textures(t_game *game);
void	free_floor_ceiling(t_game *game);
void	free_sprite_frames(t_game *game, t_sprite *sprite);
void	free_str_array(char **str_array);
double	get_time(void);

#endif