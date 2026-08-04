/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:07:31 by tsilva            #+#    #+#             */
/*   Updated: 2025/09/25 15:21:55 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/game_core.h"

static void	set_minimap_status(t_game *game);
static void	set_help_screen_status(t_game *game);

int	key_press(int key, t_game *game)
{
	if ((key == XK_Escape && !game->show_help_screen) || game->game_over)
		close_game(game);
	else if (key == XK_m || key == XK_M)
		set_minimap_status(game);
	else if (key == XK_w || key == XK_W || key == XK_Up)
		move_player(game, MOVE_FORWARD);
	else if (key == XK_s || key == XK_S || key == XK_Down)
		move_player(game, MOVE_BACKWARD);
	else if (key == XK_a || key == XK_A)
		move_player(game, STRAFE_LEFT);
	else if (key == XK_d || key == XK_D)
		move_player(game, STRAFE_RIGHT);
	else if (key == XK_Left)
		move_player(game, TURN_LEFT);
	else if (key == XK_Right)
		move_player(game, TURN_RIGHT);
	else if (key == XK_space)
		change_door_state(game);
	else if (key == XK_h || key == XK_H 
		|| (key == XK_Escape && game->show_help_screen))
		set_help_screen_status(game);
	return (0);
}

static void	set_minimap_status(t_game *game)
{
	if (game->show_mini_map)
		game->show_mini_map = false;
	else
		game->show_mini_map = true;
	game->refresh_screen = true;
}

static void	set_help_screen_status(t_game *game)
{
	if (game->show_help_screen)
		game->show_help_screen = false;
	else
		game->show_help_screen = true;
	game->refresh_screen = true;
}
