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

#ifndef PARSE_AND_VALIDATION_H
# define PARSE_AND_VALIDATION_H

# include "../inc/cub3d.h"

# define ERR_EMPTY_FILE		"The file is empty."
# define ERR_SCENE_MAP		"Invalid map data in scene file."
# define ERR_SCENE_DUP		"Invalid or duplicate identifiers in scene file."
# define ERR_MAP_LAST		"Empty line or extra content after the map."
# define ERR_MAP_ABSENT 	"Missing map section in scene file."
# define ERR_MAP_SIZE		"Invalid map size."
# define ERR_MAP_SPAWN  	"Invalid player starting position number."
# define ERR_MAP_NOPLAYER  	"Player starting position not found."
# define ERR_MAP_CHAR		"Map contains invalid characters."
# define ERR_MAP_WALL		"Map is not closed by walls."
# define ERR_MAP_WALK		"No walkable tiles found on the map."
# define ERR_RGB_COLOR      "Invalid or missing RGB color value"
# define ERR_TEXTURE_PATH   "Wrong or missing path for texture."
# define ERR_TEXTURE_FILE   "Wall texture file cannot be opened or is empty."
# define ERR_DOOR           "Invalid door placement in map."
# define MAX_MAP_WIDTH  	1000
# define MAX_MAP_HEIGHT 	1900

char	**ft_split_whitespace(char const *s);
void	parse_scene(t_game *game);
void	parse_map(t_game *game);
char	*trim_newline(char *line);
bool	is_map_line(char *line);
bool	is_empty_line(char *line);
bool	is_whitespace(char c);
int		get_color(const char *str);
void	validate_scene(t_game *game);
void	validate_map(t_game *game);
bool	dfs_fill(char **map_data, int row, int col, t_map *map);
bool	validate_map_wall(t_game *game);
void	validate_doors(t_game *game, char c, int row, int col);
void	find_sprites(t_game *game);
void	load_sprite_frames(t_game *game, t_sprite *sp, char **paths, int n);

#endif