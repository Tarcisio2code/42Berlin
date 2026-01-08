/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:17:57 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/08 15:59:08 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/**
 * init_game_vars - Initialize all game variables to their default values.
 * @game: Pointer to the game variables structure.
 *
 * This function sets all the fields in the game variables structure to their
 * initial values, preparing the game for setup and execution.
 */
void	init_game_vars(t_vars *game)
{
    game->mlx = NULL;           // Initialize MLX instance pointer to NULL
    game->win = NULL;           // Initialize window instance pointer to NULL
    game->map_data = NULL;      // Initialize map data pointer to NULL
    game->map_line = NULL;      // Initialize current map line pointer to NULL
    game->player = NULL;        // Initialize player pointer to NULL
    game->map_h = 0;            // Initialize map height to 0
    game->map_w = 0;            // Initialize map width to 0
    game->map_file = -1;        // Initialize map file descriptor to -1 (invalid)
    game->map_updated = 1;      // Initialize map updated flag to 1 (true)
    game->spaces = 0;           // Initialize number of empty spaces to 0
    game->collect = 0;          // Initialize number of collectibles to 0
    game->has_exit = 0;         // Initialize exit flag to 0 (false)
    game->exit_x = 0;           // Initialize x position of the exit to 0
    game->exit_y = 0;           // Initialize y position of the exit to 0
    game->test_collect = 0;     // Initialize test variable for collectibles to 0
    game->test_exit = 0;        // Initialize test variable for exit to 0
    game->count_moves = 0;      // Initialize counter for player moves to 0
}

/**
 * set_player - Set the player's position on the map and initialize the player structure.
 * @game: Pointer to the game variables structure.
 * @x: The x position of the player.
 * @y: The y position of the player.
 *
 * This function allocates memory for a new player structure, sets the player's
 * position and item, and assigns the player structure to the game variables.
 *
 * Return: 1 on success, 0 on failure (if player already exists or memory allocation fails).
 */
int	set_player(t_vars *game, int x, int y)
{
    t_player	*new_p;

    if (game->player)
        return (0);
    new_p = (t_player *)malloc(sizeof(t_player));
    if (!new_p)
        return (0);
    new_p->x = x;                                  // Set player's x and y positions
    new_p->y = y;
    new_p->item = game->map_line[y];               // Set item held by player based on map line
    game->player = new_p;                          // Assign new player to game structure
    return (1);
}