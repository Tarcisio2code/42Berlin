/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites_aux_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 18:40:02 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/11/04 12:08:39 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../inc/parse_and_validation.h"
#include "../../inc/rendering.h"

void	set_bounds(t_sprite_proj *pr, int screenX, int size)
{
	int	start_x;
	int	end_x;
	int	start_y;
	int	end_y;

	start_y = -size / 2 + WIN_HEIGHT / 2;
	end_y = size / 2 + WIN_HEIGHT / 2;
	start_y = clampi(start_y, 0, WIN_HEIGHT - 1);
	end_y = clampi(end_y, 0, WIN_HEIGHT - 1);
	start_x = -size / 2 + screenX;
	end_x = size / 2 + screenX;
	start_x = clampi(start_x, 0, WIN_WIDTH - 1);
	end_x = clampi(end_x, 0, WIN_WIDTH - 1);
	pr->screen_x = screenX;
	pr->size = size;
	pr->start_x = start_x;
	pr->end_x = end_x;
	pr->start_y = start_y;
	pr->end_y = end_y;
}

double	dist2(double ax, double ay, double bx, double by)
{
	double	dx;
	double	dy;

	dx = ax - bx;
	dy = ay - by;
	return (dx * dx + dy * dy);
}

void	update_collectibles(t_game *game)
{
	double		r;
	int			i;
	t_sprite	*s;

	if (!game->sprites || game->sprite_count <= 0)
		return ;
	r = TILE_SIZE * 0.5;
	i = 0;
	while (i < game->sprite_count)
	{
		s = &game->sprites[i];
		if (!s->alive)
		{
			i++;
			continue ;
		}
		if (dist2(game->player.x, game->player.y, s->x, s->y) <= (r * r))
		{
			s->alive = false;
			game->score++;
			game->refresh_screen = true;
		}
		i++;
	}
}

// black shadow 0x00000 and white text 0xFFFFFF
void	render_score(t_game *game)
{
	char	*num;
	int		x;
	int		y;

	num = ft_itoa(game->score);
	if (!num)
		return ;
	x = 16;
	y = 28;
	mlx_string_put(game->mlx, game->win, x + 1, y + 1, 0xFFFFFF, "Score:");
	mlx_string_put(game->mlx, game->win, x + 60, y + 1, 0xFFFFFF, num);
	free(num);
}
