/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:01:14 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/08 16:57:47 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// Function prototypes for static functions
static void		check_line(int new_size, t_vars *game);
static int		add_new(char **map, t_vars *game);
static void		set_map_items(char **map, t_vars *game, int x, int y);
static char		**load_map(t_vars *game);

/**
 * open_map - Open and read the map file.
 * @argv: Command line arguments.
 * @game: Pointer to the game variables structure.
 *
 * This function opens the map file, reads each line, and processes it to
 * build the map data structure. It also performs various checks on the map.
 */
void	open_map(char **argv, t_vars *game)
{
    game->map_file = open(argv[1], O_RDONLY);
    if (game->map_file < 0)
        exit(print_error(ERR_MAP_FILE, 0));
    while (True)
    {
        game->map_line = get_next_line(game->map_file);
        if (!game->map_line)
            break ;
        check_line(ft_strlen(game->map_line), game);
        game->map_h++;
        game->map_data = load_map(game);
        free(game->map_line);
        game->map_line = NULL;
        if (!(game->map_data))
            break ;
    }
    close(game->map_file);
}

/**
 * check_line - Check the validity of a map line.
 * @new_size: The size of the new line.
 * @game: Pointer to the game variables structure.
 *
 * This function checks if the new line is valid. It ensures the line is not
 * empty, adjusts the size if it ends with a newline character, and checks if
 * the line length matches the expected map width.
 */
static void	check_line(int new_size, t_vars *game)
{
    if (game->map_line[0] == '\n')
        exit(print_error(ERR_MAP_TYPE, game));
    else if (game->map_line[new_size - 1] == '\n')
        // Adjust size if the line ends with a newline character
        new_size--;
    if (game->map_w > 0 && new_size != game->map_w)
        exit(print_error(ERR_MAP_FORM, game));
    else
        game->map_w = new_size;
}

/**
 * add_new - Add new lines to the map data.
 * @map: Pointer to the map data array.
 * @game: Pointer to the game variables structure.
 *
 * This function adds new lines to the map data array. It copies existing lines
 * from the old map data to the new map data array.
 *
 * @return: The index of the next line to be added.
 */
static int	add_new(char **map, t_vars *game)
{
    int	x;

    x = 0;
    if (game->map_data)
    {
        while (x < game->map_h - 1)
        {
            map[x] = game->map_data[x];
            game->map_data[x] = NULL;
            x++;
        }
        free(game->map_data);
        game->map_data = NULL;
    }
    // Return the index of the next line to be added
    return (x);
}

/**
 * set_map_items - Set the items on the map.
 * @map: Pointer to the map data array.
 * @game: Pointer to the game variables structure.
 * @x: The x position of the item.
 * @y: The y position of the item.
 *
 * This function sets the items on the map based on the characters in the map
 * line. It handles the player, exit, collectibles, empty spaces, and walls.
 * It also performs checks for duplicate items and invalid characters.
 */
static void	set_map_items(char **map, t_vars *game, int x, int y)
{
    if (game->map_line[y] == 'P' && !(set_player(game, x, y)))
    {
        free_map(map, game->map_h);
        exit(print_error(ERR_DUPLCATE, game));
    }
    else if (game->map_line[y] == 'E')
    {
        if (game->has_exit)
        {
            free_map(map, game->map_h);
            exit(print_error(ERR_DUPLCATE, game));
        }
        game->has_exit++;
        game->exit_x = x;
        game->exit_y = y;
    }
    else if (game->map_line[y] == 'C')
        game->collect++;
    else if (game->map_line[y] == '0')
        game->spaces++;
    else if (game->map_line[y] != '1' && game->map_line[y] != 'P')
    {
        free_map(map, game->map_h);
        exit(print_error(ERR_MAP_CHAR, game));
    }
}

/**
 * load_map - Load the map data.
 * @game: Pointer to the game variables structure.
 *
 * This function loads the map data from the map lines. It allocates memory for
 * the map data array, adds new lines, and sets the items on the map.
 *
 * @return: Pointer to the loaded map data array.
 */
static char	**load_map(t_vars *game)
{
    char	**map;
    int		x;
    int		y;

    map = malloc(game->map_h * sizeof(char *));
    if (!map)
        exit(print_error(ERR_MEM, game));
    x = add_new(map, game);
    while (x < game->map_h)
    {
        map[x] = malloc(game->map_w + 1 * sizeof(char));
        if (!map[x])
        {
            free_map(map, game->map_h);
            exit(print_error(ERR_MEM, 0));
        }
        y = 0;
        while (game->map_line[y] && y < game->map_w)
        {
            map[x][y] = game->map_line[y];
            set_map_items(map, game, x, y++);
        }
        // Null-terminate the line
        map[x++][y] = 0;
    }
    return (map);