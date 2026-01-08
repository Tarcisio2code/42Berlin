/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 08:49:52 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/08 17:02:29 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// Function prototypes
void		check_name(char *map_name, int argc);
int			print_error(char *msg, t_vars *game);
void		free_vars(t_vars *game);
void		free_map(char **map, int map_height);
static void	free_img(t_vars *game_vars);

/**
 * check_name - Check the validity of the map name.
 * @map_name: The name of the map file.
 * @argc: The number of command line arguments.
 *
 * This function checks if the map name is valid. It ensures that the map name
 * has the correct file extension (.ber) and that the correct number of arguments
 * is provided.
 */
void	check_name(char *map_name, int argc)
{
    char	*file_type;
    int		wrong_type;
    int		name_len;
    int		i;

    name_len = ft_strlen(map_name);
    if (argc != 2 || map_name[name_len - 5] == '/')
        exit(print_error(ERR_ARG, 0));
    file_type = ft_substr(map_name, name_len - 4, 4);
    i = -1;
    while (file_type[++i])
        file_type[i] = ft_tolower(file_type[i]);
    wrong_type = strcmp(".ber", file_type);
    free(file_type);
    if (wrong_type)
        exit(print_error(ERR_MAP_TYPE, 0));
}

/**
 * print_error - Print an error message and handle game cleanup.
 * @msg: The error message to be printed.
 * @game: Pointer to the game variables structure.
 *
 * This function prints an error message to the standard error output and
 * performs necessary cleanup of game resources.
 *
 * @return: Always returns 1.
 */
int	print_error(char *msg, t_vars *game)
{
    if (msg)
    {
        ft_putstr_fd("Error\n", 2);
        ft_putstr_fd(msg, 2);
        ft_putstr_fd("\n", 2);
    }
    if (game)
    {
        free_vars(game); 
        if (game->map_file)
            close(game->map_file); 
        if (game->map_line)
            free(game->map_line);
    }
    return (1);
}

/**
 * free_map - Free the memory allocated for the map.
 * @map: Pointer to the map data array.
 * @map_height: The height of the map.
 *
 * This function frees the memory allocated for the map data array.
 */
void	free_map(char **map, int map_height)
{
    int	i;

    i = 0;
    while (*map && i < map_height)
    {
        if (map[i])
            free(map[i++]);
    }
    free(map); 
}

/**
 * free_vars - Free the memory allocated for game variables.
 * @game: Pointer to the game variables structure.
 *
 * This function frees the memory allocated for various game variables,
 * including the map data, player, and MLX resources.
 */
void	free_vars(t_vars *game)
{
    if (game->map_data)
    {
        free_map(game->map_data, game->map_h);
        game->map_data = NULL;
    }
    if (game->player)
    {
        free(game->player);
        game->player = NULL;
    }
    if (game->mlx)
    {
        if (game->map_img)
            free;
        if (game->win)
            mlx_destroy_window(game->mlx, game->win);
        mlx_destroy_display(game->mlx);
        free(game->mlx);
    }
}

/**
 * free_img - Free the memory allocated for map images.
 * @game_vars: Pointer to the game variables structure.
 *
 * This function frees the memory allocated for the map images and destroys
 * the images using the MLX library.
 */
static void	free_img(t_vars *game_vars)
{
    if (game_vars->map_img)
    {
        if (game_vars->map_img->wall)
            mlx_destroy_image(game_vars->mlx, game_vars->map_img->wall);
        if (game_vars->map_img->empty)
            mlx_destroy_image(game_vars->mlx, game_vars->map_img->empty);
        if (game_vars->map_img->player)
            mlx_destroy_image(game_vars->mlx, game_vars->map_img->player);
        if (game_vars->map_img->collect)
            mlx_destroy_image(game_vars->mlx, game_vars->map_img->collect);
        if (game_vars->map_img->exit)
            mlx_destroy_image(game_vars->mlx, game_vars->map_img->exit);
        if (game_vars->map_img->winner)
            mlx_destroy_image(game_vars->mlx, game_vars->map_img->winner);
        free(game_vars->map_img);
        game_vars->map_img = NULL;
    }
}