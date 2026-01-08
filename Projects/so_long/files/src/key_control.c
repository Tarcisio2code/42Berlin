/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 08:47:24 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/08 16:48:16 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// Function prototypes for static functions
static int	is_move_keys(int key, t_player *player);
static int	valid_pos(char next_item, t_vars *game);
static void	count_items(t_vars *game);
static void	show_moves(int n);

/**
 * key_control - Handle key press events.
 * @key: The key code representing the key pressed.
 * @game: Pointer to the game variables structure.
 *
 * This function handles the key press events for moving the player and
 * updating the game state. It checks if the key pressed is a movement key,
 * updates the player's direction, and moves the player if the next position
 * is valid. It also counts the items collected and updates the move count.
 *
 * @return: Always returns 0.
 */
int	key_control(int key, t_vars *game)
{
    char	**map;

    if (key == XK_Escape)
        close_game(game);
    map = game->map_data;
    if (is_move_keys(key, game->player))
    {
        update_player_direction(game, key);
        if ((key == XK_w || key == XK_W || key == XK_Up) 
            && valid_pos(map[game->player->x - 1][game->player->y], game))
            game->player->x--;
        else if ((key == XK_s || key == XK_S || key == XK_Down) 
            && valid_pos(map[game->player->x + 1][game->player->y], game))
            game->player->x++;
        else if ((key == XK_a || key == XK_A || key == XK_Left) 
            && valid_pos(map[game->player->x][game->player->y - 1], game))
            game->player->y--;
        else if ((key == XK_d || key == XK_D || key == XK_Right) 
            && valid_pos(map[game->player->x][game->player->y + 1], game))
            game->player->y++;
        else
            return (0);
        // Count items collected and update move count
        count_items(game);
    }
    return (0);
}

/**
 * is_move_keys - Check if the key pressed is a movement key.
 * @key: The key code representing the key pressed.
 * @player: Pointer to the player structure.
 *
 * This function checks if the key pressed is one of the movement keys (W, A, S, D, or arrow keys).
 * If it is, it updates the player's old position and returns 1.
 *
 * @return: 1 if the key is a movement key, 0 otherwise.
 */
static int	is_move_keys(int key, t_player *player)
{
    if (key == XK_w || key == XK_W || key == XK_Up 
        || key == XK_s || key == XK_S || key == XK_Down 
        || key == XK_a || key == XK_A || key == XK_Left 
        || key == XK_d || key == XK_D || key == XK_Right)
    {
        player->old_x = player->x;
        player->old_y = player->y;
        return (1);
    }
    return (0);
}

/**
 * valid_pos - Check if the next position is valid.
 * @next_item: The item at the next position.
 * @game: Pointer to the game variables structure.
 *
 * This function checks if the next position is valid for the player to move to.
 * A position is valid if it is not a wall ('1') or an exit ('E') unless the exit is open.
 *
 * @return: 1 if the position is valid, 0 otherwise.
 */
static int	valid_pos(char next_item, t_vars *game)
{
    if (next_item != '1' && next_item != 'E')
        return (1);
    else if (next_item == 'E' && game->test_exit)
        return (1);
    return (0);
}

/**
 * count_items - Count the items collected and update move count.
 * @game: Pointer to the game variables structure.
 *
 * This function checks if the player has collected an item ('C') and updates
 * the count of collected items. It also increments the move count and updates
 * the map state.
 */
static void	count_items(t_vars *game)
{
    char	**map;

    map = game->map_data;
    if (map[game->player->x][game->player->y] == 'C')
    {
        game->test_collect++;
        // Update map to remove collected item
        map[game->player->x][game->player->y] = '0';
    }
    game->count_moves++;
    show_moves(game->count_moves);
    game->map_updated = 0;
}

/**
 * show_moves - Display the number of moves made by the player.
 * @n: The number of moves.
 *
 * This function prints the number of moves made by the player to the standard output.
 */
static void	show_moves(int n)
{
    ft_putstr_fd("\r", 1);
    ft_putstr_fd("Number of movements: ", 1);
    ft_putnbr_fd(n, 1);
}