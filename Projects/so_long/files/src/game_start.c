/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:31:13 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/08 17:07:37 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <X11/Xlib.h>


// Function prototypes for static functions
static int	update_map(t_vars *game);
static void	load_img(t_vars *game);
static void	draw_map(t_vars *game);
static void	update_item(t_vars *game);

/**
 * start_game - Initialize and start the game.
 * @game: Pointer to the game variables structure.
 *
 * This function initializes the MLX instance, loads images, creates a window,
 * draws the initial map, sets up event hooks, and starts the MLX loop.
 */
void	start_game(t_vars *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
        exit(print_error(ERR_MLX, game));

    load_img(game);

    game->win = mlx_new_window(game->mlx, game->map_w * IMG_SIZE,
            game->map_h * IMG_SIZE, "Welcome to So_Long");

    draw_map(game);

    // Register KeyPress event (2) using the KeyPressMask (1L<<0)
    mlx_hook(game->win, 2, 1L << 0, key_control, game);     
    
    // Register DestroyNotify event (17) to handle window closure (NoEventMask = 0)
    mlx_hook(game->win, 17, 0, close_game, game);

    mlx_loop_hook(game->mlx, update_map, game);
    mlx_loop(game->mlx);                                    
}


/**
 * load_img - Load game images.
 * @game: Pointer to the game variables structure.
 *
 * This function loads the images for the game elements (wall, empty space,
 * collectible, player, exit, winner) and assigns them to the game structure.
 */
static void	load_img(t_vars *game)
{
    int	img_h;
    int	img_w;

    game->map_img = (t_map_img *)malloc(sizeof(t_map_img));
    if (!game->map_img)
        exit(print_error(ERR_MEM, game));
    game->map_img->wall = mlx_xpm_file_to_image(game->mlx, IMG_WALL, &img_w, &img_h);
    game->map_img->empty = mlx_xpm_file_to_image(game->mlx, IMG_EMPTY, &img_w, &img_h);
    game->map_img->collect = mlx_xpm_file_to_image(game->mlx, IMG_COLLECT, &img_w, &img_h);
    game->map_img->player = mlx_xpm_file_to_image(game->mlx, IMG_PLAYER_U, &img_w, &img_h);
    game->map_img->exit = mlx_xpm_file_to_image(game->mlx, IMG_EXIT_CLOSE, &img_w, &img_h);
    game->map_img->winner = mlx_xpm_file_to_image(game->mlx, IMG_WINNER, &img_w, &img_h);
    if (!game->map_img->wall || !game->map_img->empty || !game->map_img->collect || !game->map_img->player 
        || !game->map_img->exit || !game->map_img->winner)
        exit(print_error(ERR_IMG, game));
}

/**
 * draw_map - Draw the game map.
 * @game: Pointer to the game variables structure.
 *
 * This function iterates through the map data and draws the corresponding
 * images for each map element (wall, empty space, collectible, exit, player).
 */
static void	draw_map(t_vars *game)
{
    int		x;
    int		y;

    x = -1;
    while (++x < game->map_h)
    {
        y = 0;
        while (y < game->map_w)
        {
            if (game->map_data[x][y] == '1')
                put_image(game, game->map_img->wall, x, y);
            else if (game->map_data[x][y] == '0')
                put_image(game, game->map_img->empty, x, y);
            else if (game->map_data[x][y] == 'E')
                put_image(game, game->map_img->exit, x, y);
            else if (game->map_data[x][y] == 'C')
                put_image(game, game->map_img->collect, x, y);
            y++;
        }
    }
    put_image(game, game->map_img->player, game->player->x, game->player->y);
}

/**
 * update_item - Update the game items.
 * @game: Pointer to the game variables structure.
 *
 * This function updates the game items based on the player's actions and
 * the current state of the map. It handles the transition of the exit image
 * and updates the player's position on the map.
 */
static void	update_item(t_vars *game)
{
    int	img_h;
    int	img_w;

    // Trigger: All items collected -> Open the exit door
    if (!game->test_exit && game->test_collect == game->collect)
    {
        game->test_exit = 1;
        mlx_destroy_image(game->mlx, game->map_img->exit);
        game->map_img->exit = mlx_xpm_file_to_image(game->mlx, IMG_EXIT_OPEN, &img_w, &img_h);
        if (!game->map_img->exit)
            exit(print_error(ERR_IMG, game));
        put_image(game, game->map_img->exit, game->exit_x, game->exit_y);
    }
    
    // Redraw the tile the player just left (either floor or exit)
    if (game->map_data[game->player->old_x][game->player->old_y] != 'E')
        put_image(game, game->map_img->empty, game->player->old_x, game->player->old_y);
    else if (game->map_data[game->player->old_x][game->player->old_y] == 'E')
        put_image(game, game->map_img->exit, game->player->old_x, game->player->old_y);

    // Draw the player at the new position
    put_image(game, game->map_img->player, game->player->x, game->player->y);

    game->map_updated = 1;
}

/**
 * update_map - Update the game map.
 * @game: Pointer to the game variables structure.
 *
 * This function updates the game map based on the player's actions and
 * the current state of the game. It handles the transition to the winner
 * state if the player reaches the exit.
 *
 * @return: Always returns 0.
 */
static int	update_map(t_vars *game)
{
    t_img	*win_img;
    int		x;
    int		y;
    int     screen_center_x;
    int     screen_center_y;

    if (!game->map_updated)
        update_item(game);
    if (game->player->x == game->exit_x && game->player->y == game->exit_y && game->test_exit)
    {
        win_img = game->map_img->winner;
        // Calculate coordinates to center the "winner" image on the window
        screen_center_x = (game->map_w * IMG_SIZE) / 2;
        screen_center_y = (game->map_h * IMG_SIZE) / 2;
        x = screen_center_x - (win_img->width / 2);
        y = screen_center_y - (win_img->height / 2);
        mlx_clear_window(game->mlx, game->win);
        mlx_put_image_to_window(game->mlx, game->win, win_img, x, y);
        game->test_exit = 0;  // Reset exit test flag
        ft_putstr_fd(" * * * Congratulations you won ! * * *", 1);
    }
    return (0);
}