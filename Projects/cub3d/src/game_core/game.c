/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:06:27 by tsilva            #+#    #+#             */
/*   Updated: 2025/11/01 12:08:30 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/game_core.h"
#include "../../inc/rendering.h"

static int	loop_control(t_game *game);
static int	game_loop(t_game *game);
static int	game_over_loop(t_game *game);

void	start_game(t_game *game)
{
	init_core(game);

	// --- MiniLibX Event Hook and Loop Setup ---

	mlx_hook(game->win, 17, 0, close_game, game);
	// 	Sets up a hook for the 'DestroyNotify' event (event code 17, mask 0).
	// 	For a DestroyNotify (event code 17), the event is always sent to the window manager when the close request happens. 
	// 	It is a "passive" event that does not require the application to actively select a mask. 
	// 	Therefore, a mask of 0 is used because no specific event selection is needed for the window close request to be delivered.

	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	// 	Sets up a hook for the 'KeyPress' event (event code 2, mask 1L << 0, which is 1).
	// 	Code 2 is the specific integer identifier for the X11 event type known as KeyPress.
	// 	1L << 0 is a bitwise shift operation that evaluates to the integer value of 1 that corresponds to the specific X11 mask known as KeyPressMask.
	// 	Key presses and mouse movements are continuous events. 
	// 	Explicitly tell the window server to listen for key press events on this window. The KeyPressMask (or 1L << 0) is the signal to enable this listening.

	mlx_hook(game->win, 6, 1L << 6, mouse_move, game);
	// 	Sets up a hook for the 'MotionNotify' event (event code 6, mask 1L << 6, which is 64).
	// 	Code 6 is the specific integer identifier for the X11 event type known as 'MotionNotify',
	// 	which triggers whenever the mouse cursor moves within the window.
	// 	1L << 6 is a bitwise shift operation that evaluates to the integer value 64,
	// 	which corresponds to the specific X11 mask known as 'PointerMotionMask'.
	// 	Just like key presses, motion events are continuous; this mask explicitly tells the
	// 	window server to report every movement of the mouse cursor to the 'mouse_move' function.

	mlx_mouse_hide(game->mlx, game->win);
	// 	Hides the mouse cursor within the game window.
	// 	This is essential for an immersive first-person perspective, where the mouse movement
	// 	is used to control the player's camera angle (like in a modern FPS game).

	mlx_loop_hook(game->mlx, loop_control, game);
	// 	Sets up the primary game loop callback. This function ('loop_control') is called continuously
	// 	by MiniLibX as fast as possible to handle logic, raycasting, and rendering every frame.

	mlx_loop(game->mlx);
	// 	Starts the MiniLibX event loop. This function enters an infinite loop that monitors
	// 	and dispatches all the hooked events (key presses, mouse movements, window close),
	// 	and repeatedly calls 'loop_control'. The game execution blocks here until the window is closed.
}

static int	loop_control(t_game *game)
{
	if (!game->is_running)
		return (mlx_loop_end(game->mlx), 0);
	if (!game->game_over)
		game_loop(game);
	else
		game_over_loop(game);
	return (0);
}

static int	game_loop(t_game *game)
{
	void	*window_image;

	if (game->refresh_screen)
	{
		ft_memset(game->win_img.data, 0, game->win_img.size_line * WIN_HEIGHT);  // clear the entire image buffer that represents the window's frame.
		update_collectibles(game);
		render_3d_scene(game);
		if (game->sprite_count > 0)
			render_sprites(game);
		if (game->show_mini_map)
			draw_mini_map(game);
		if (game->show_help_screen)
			render_help_screen(game);
		window_image = game->win_img.img_ptr;
		mlx_put_image_to_window(game->mlx, game->win, window_image, 0, 0);  // Makes the newly rendered frame visible to the player
		render_score(game);
		if (!game->game_over)
			game->refresh_screen = false;
	}
	animate_door(game);
	animate_sprites(game);
	return (0);
}

static int	game_over_loop(t_game *game)
{
	void	*window_image;

	if (game->refresh_screen)
	{
		ft_memset(game->win_img.data, 0, game->win_img.size_line * WIN_HEIGHT);
		render_3d_scene(game);
		if (game->show_mini_map)
			draw_mini_map(game);
		render_game_over_screen(game);
		window_image = game->win_img.img_ptr;
		mlx_put_image_to_window(game->mlx, game->win, window_image, 0, 0);
		render_score(game);
		game->refresh_screen = false;
	}
	return (0);
}
