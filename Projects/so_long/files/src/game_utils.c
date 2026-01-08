/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:17:57 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/08 16:45:38 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/**
 * put_image - Put an image on the window.
 * @game: Pointer to the game variables structure.
 * @img: Pointer to the image to be put on the window.
 * @x: The x position where the image will be placed.
 * @y: The y position where the image will be placed.
 *
 * This function uses the MLX library to put an image on the window at the
 * specified x and y coordinates.
 */
void	put_image(t_vars *game, t_img *img, int x, int y)
{
    mlx_put_image_to_window(game->mlx, game->win, 
        img, y * IMG_SIZE, x * IMG_SIZE);
}

/**
 * update_player_direction - Update the player's direction based on key press.
 * @game: Pointer to the game variables structure.
 * @key: The key code representing the direction.
 *
 * This function updates the player's image based on the direction key pressed.
 * It destroys the current player image and loads the new image corresponding
 * to the direction.
 */
void	update_player_direction(t_vars *game, int key)
{
    int	img_h;
    int	img_w;

    mlx_destroy_image(game->mlx, game->map_img->player);
    if (key == XK_w || key == XK_W || key == XK_Up)
        game->map_img->player = mlx_xpm_file_to_image(game->mlx, 
                IMG_PLAYER_U, &img_w, &img_h);
    else if (key == XK_s || key == XK_S || key == XK_Down)
        game->map_img->player = mlx_xpm_file_to_image(game->mlx, 
                IMG_PLAYER_D, &img_w, &img_h);
    else if (key == XK_a || key == XK_A || key == XK_Left)
        game->map_img->player = mlx_xpm_file_to_image(game->mlx, 
                IMG_PLAYER_L, &img_w, &img_h);
    else if (key == XK_d || key == XK_D || key == XK_Right)
        game->map_img->player = mlx_xpm_file_to_image(game->mlx, 
                IMG_PLAYER_R, &img_w, &img_h);
    if (!game->map_img->player)
        exit(print_error(ERR_IMG, game));
}

/**
 * close_game - Close the game and free resources.
 * @game: Pointer to the game variables structure.
 *
 * This function handles the cleanup and closing of the game. It ends the MLX
 * loop and performs any necessary cleanup.
 *
 * @return: Always returns 0.
 */
int	close_game(t_vars *game)
{
    ft_putchar_fd('\n', 1);
    mlx_loop_end(game->mlx);
    return (0);
}