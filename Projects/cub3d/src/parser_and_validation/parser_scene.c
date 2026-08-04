/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:09:43 by tsilva            #+#    #+#             */
/*   Updated: 2025/11/02 19:36:31 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../inc/parse_and_validation.h"

static void	parse_identifier(t_game *game);
static void	parse_textures(t_game *game, char **tokens);
static void	parse_colors(t_game *game, char **tokens);
static void	assign_texture(t_game *game, char *token, char **path);

void	parse_scene(t_game *game)
{
	game->map->line = trim_newline(get_next_line(game->scene_file)); // retrieves the line without the newline character
	if (!game->map->line)
		exit_clean(ERR_EMPTY_FILE, game);
	parse_identifier(game);
	parse_map(game);
	close(game->scene_file);
	game->scene_file = -1; // defines that the scene file is closed
}

static void	parse_identifier(t_game *game)
{
	char	**tokens;

	while (game->map->line && !is_map_line(game->map->line)) // checks if the current line is null or contains a map character (e.g. 0,1,N, etc)
	{
		if (!is_empty_line(game->map->line))
		{
			tokens = ft_split_whitespace(game->map->line);
			if (!tokens)
				exit_clean(ERR_MALLOC, game);
			if (tokens[0])
			{
				if (ft_strncmp(tokens[0], "F", 2) == 0 
					|| ft_strncmp(tokens[0], "C", 2) == 0)
					parse_colors(game, tokens);
				else
					parse_textures(game, tokens);
			}
			free_str_array(tokens);
		}
		free(game->map->line);
		game->map->line = trim_newline(get_next_line(game->scene_file));
	}
}

static void	parse_textures(t_game *game, char **tokens)
{
	t_textures	*texture;

	texture = &game->textures;
	if (ft_strncmp(tokens[0], "NO", 3) == 0 && tokens[1]
		&& !texture->north.path)
		assign_texture(game, tokens[1], &texture->north.path);
	else if (ft_strncmp(tokens[0], "SO", 3) == 0 && tokens[1] 
		&& !texture->south.path)
		assign_texture(game, tokens[1], &texture->south.path);
	else if (ft_strncmp(tokens[0], "EA", 3) == 0 && tokens[1] 
		&& !texture->east.path)
		assign_texture(game, tokens[1], &texture->east.path);
	else if (ft_strncmp(tokens[0], "WE", 3) == 0 && tokens[1] 
		&& !texture->west.path)
		assign_texture(game, tokens[1], &texture->west.path);
	else if (ft_strncmp(tokens[0], "TF", 3) == 0 && tokens[1] 
		&& !texture->floor.path)
		assign_texture(game, tokens[1], &texture->floor.path);
	else if (ft_strncmp(tokens[0], "TC", 3) == 0 && tokens[1] 
		&& !texture->ceiling.path)
		assign_texture(game, tokens[1], &texture->ceiling.path);
	else
		return (free_str_array(tokens), exit_clean(ERR_SCENE_DUP, game));
}

static void	parse_colors(t_game *game, char **tokens)
{
	char	**colors;
	int		rgb[3]; 
	int		i;

	colors = ft_split(tokens[1], ',');
	if (!colors || !colors[0] || !colors[1] || !colors[2])
	{
		free_str_array(colors);
		return (free_str_array(tokens), exit_clean(ERR_SCENE_DUP, game));
	}
	rgb[0] = get_color(colors[0]);
	rgb[1] = get_color(colors[1]);
	rgb[2] = get_color(colors[2]);
	free_str_array(colors);
	i = -1;
	while (++i < 3)
	{
		if (**tokens == 'F' && game->floor_color[i] < 0)
			game->floor_color[i] = rgb[i];
		else if (**tokens == 'C' && game->ceiling_color[i] < 0)
			game->ceiling_color[i] = rgb[i];
		else
			return (free_str_array(tokens), exit_clean(ERR_SCENE_DUP, game));
	}
}

static void	assign_texture(t_game *game, char *token, char **path)
{
	*path = ft_strdup(token);
	if (!(*path))
		exit_clean(ERR_MALLOC, game);
}
