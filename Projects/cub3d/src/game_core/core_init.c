/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:26:23 by tsilva            #+#    #+#             */
/*   Updated: 2025/11/04 14:38:32 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/game_core.h"

void	init_core(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_clean(ERR_MLX, game);
	game->zbuf = (double *)malloc(sizeof(double) * WIN_WIDTH);
	if (!game->zbuf)
		exit_clean(ERR_MALLOC, game);
	load_textures(game);
	init_door(game);
	init_sprites(game);
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!game->win)
		exit_clean(ERR_MLX_WIN, game);
	game->win_img.img_ptr = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->win_img.img_ptr)
		exit_clean(ERR_MLX_IMG_PTR, game);
	set_img_data(&game->win_img);
	mlx_put_image_to_window(game->mlx, game->win, game->win_img.img_ptr, 0, 0);
	set_player(game);
	game->refresh_screen = true;
	game->show_help_screen = true;
	game->is_running = true;
	game->show_mini_map = false;
	game->map->mini_x = WIN_WIDTH - (game->map->width * MINI_TILE_SIZE) - 10;
	game->map->mini_y = 10;
	game->game_over = false;
}
