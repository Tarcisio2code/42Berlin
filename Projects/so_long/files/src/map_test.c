/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 11:48:01 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/08 16:54:05 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// Function prototypes for static functions
static int	valid_wall(t_vars *game);
static void	test_path(int x, int y, t_vars *game);
static int	valid_path(t_vars *game);
static void	restore_map(t_vars *game);

/**
 * check_map - Validate the game map.
 * @game: Pointer to the game variables structure.
 *
 * This function performs various checks on the game map to ensure it is valid.
 * It checks the map size, wall boundaries, presence of collectibles, exit, 
 * player, and valid paths.
 *
 * @return: 1 if the map is valid, 0 otherwise.
 */
int	check_map(t_vars *game)
{
    if (game->map_h == 0)
        print_error(ERR_MAP_SIZE, 0);
    else if (game->map_h * IMG_SIZE > 1000 || game->map_w * IMG_SIZE > 1920)
        print_error(ERR_MAP_SIZE, 0);
    else if (game->map_h < 3 || game->map_w < 3 || game->map_h == game->map_w)
        print_error(ERR_MAP_TYPE, 0);
    else if (!valid_wall(game))
        print_error(ERR_MAP_WALL, 0);
    else if (!game->collect)
        print_error(ERR_COLLECT, 0);
    else if (!game->has_exit)
        print_error(ERR_NO_EXIT, 0);
    else if (!game->player)
        print_error(ERR_NO_PLAYER, 0);
    else if (!valid_path(game))
        print_error(ERR_MAP_PATH, 0);
    else
        return (1);
    return (0);
}

/**
 * valid_wall - Check if the map is surrounded by walls.
 * @game: Pointer to the game variables structure.
 *
 * This function checks if the map is surrounded by walls ('1') on all sides.
 *
 * @return: 1 if the map is surrounded by walls, 0 otherwise.
 */
static int	valid_wall(t_vars *game)
{
    int		x;
    int		y;
    char	**map;

    map = game->map_data;
    x = 0;
    while (x < game->map_h)
    {
        y = 0;
        while (y < game->map_w)
        {
            if ((x == 0 || x == game->map_h - 1 || y == 0 
                    || y == game->map_w - 1) && map[x][y] != '1')
                return (0);
            y++;
        }
        x++;
    }
    return (1);
}

/**
 * test_path - Recursively test the path from the player's position.
 * @x: The x position to start testing from.
 * @y: The y position to start testing from.
 * @game: Pointer to the game variables structure.
 *
 * This function recursively tests the path from the player's position to ensure
 * all collectibles and the exit are reachable. It marks visited positions and
 * updates the test_collect and test_exit counters.
 */
static void	test_path(int x, int y, t_vars *game)
{
    char	**map;

    // test out of bounds
    if (x < 0 || x >= game->map_h || y < 0 || y >= game->map_w)
        return ;
    map = game->map_data;
    if (map[x][y] == 'C')
        game->test_collect++;
    else if (map[x][y] == 'E')
    {
        game->test_exit++;
        map[x][y] = '1';  // Mark exit as visited
    }
    if (map[x][y] == '0' || map[x][y] == 'P')
        map[x][y] = 'o';  // Mark empty space or player start as visited
    else if (map[x][y] == 'C')
        map[x][y] = 'c';  // Mark collectible as visited
    else
        return ;
    test_path(x + 1, y, game);  // Test path to the right
    test_path(x - 1, y, game);  // Test path to the left
    test_path(x, y + 1, game);  // Test path downwards
    test_path(x, y - 1, game);  // Test path upwards
}

/**
 * valid_path - Check if there is a valid path to all collectibles and the exit.
 * @game: Pointer to the game variables structure.
 *
 * This function checks if there is a valid path from the player's start position
 * to all collectibles and the exit. It uses the test_path function to mark the
 * path and then restores the map to its original state.
 *
 * @return: 1 if a valid path exists, 0 otherwise.
 */
static int	valid_path(t_vars *game)
{
    test_path(game->player->x, game->player->y, game);
    if (game->test_collect != game->collect 
        || game->test_exit != game->has_exit)
        return (0);
    else
    {
        restore_map(game);
        return (1);
    }
}

/**
 * restore_map - Restore the map to its original state.
 * @game: Pointer to the game variables structure.
 *
 * This function restores the map to its original state after testing the path.
 * It changes visited markers back to their original values.
 */
static void	restore_map(t_vars *game)
{
    int		x;
    int		y;
    char	**map;

    x = 1;
    map = game->map_data;
    while (x < game->map_h)
    {
        y = 1;
        while (y < game->map_w)
        {
            if (map[x][y] == 'c')
                map[x][y] = 'C';
            else if (map[x][y] == 'o')
                map[x][y] = '0';
            y++;
        }
        x++;
    }
    map[game->exit_x][game->exit_y] = 'E';
    game->test_collect = 0;
    game->test_exit = 0;
}