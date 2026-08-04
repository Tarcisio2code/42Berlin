/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:34:29 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/11/04 14:34:54 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../inc/parse_and_validation.h"
#include "../../inc/rendering.h"

int	sprite_project(t_game *game, t_sprite *s, t_sprite_proj *pr)
{
	t_player	*p;
	double		t_x;
	double		t_y;
	int			ok;

	p = &game->player;
	ok = inv_det(p, &s->invd);
	if (!ok)
		return (0);
	cam_transform(p, s, &t_x, &t_y);
	if (t_y <= 0.1)
		return (0);
	pr->t_y = t_y;
	if (!sprite_within_fov(p, t_x, t_y, 1.5))
		return (0);
	set_bounds(pr, 
		screen_x_from_tx_ty(t_x, t_y),
		size_from_ty_scale(t_y, s->scale));
	return (pr->start_x <= pr->end_x && pr->start_y <= pr->end_y);
}

void	draw_sprite_stripe(t_game *game, t_image *tex, t_sprite_proj *pr, int x)
{
	int	y;
	int	col;
	int	tex_x;
	int	tex_y;

	if (x < 0 || x >= WIN_WIDTH || pr->t_y >= game->zbuf[x])
		return ;
	tex_x = (int)((x - (pr->screen_x - pr->size / 2)) 
			* tex->width / (double)pr->size);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= tex->width)
		tex_x = tex->width - 1;
	y = pr->start_y - 1;
	while (++y <= pr->end_y)
	{
		tex_y = (int)((y - pr->start_y) * tex->height / (double)pr->size);
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= tex->height)
			tex_y = tex->height - 1;
		col = get_texture_color(tex, tex_x, tex_y);
		if ((col & 0x00FFFFFF) != 0x000000)
			put_pixel(&game->win_img, x, y, col);
	}
}

void	draw_one_sprite(t_game *game, t_sprite *s)
{
	t_sprite_proj	pr;
	t_image			*tex;
	int				x;

	if (!s->alive || s->frame_count == 0)
		return ;
	tex = s->frames[s->curr_frame];
	if (!sprite_project(game, s, &pr))
		return ;
	x = pr.start_x;
	while (x <= pr.end_x)
	{
		draw_sprite_stripe(game, tex, &pr, x);
		x++;
	}
}

void	render_sprites(t_game *game)
{
	int	i;

	i = 0;
	if (!game->sprites || game->sprite_count <= 0)
		return ;
	while (i < game->sprite_count)
	{
		if (!game->sprites[i].alive)
		{
			i++;
			continue ;
		}
		draw_one_sprite(game, &game->sprites[i]);
		i++;
	}
}

int	sprite_within_fov(t_player *p, double tX, double tY, double margin)
{
	double	plane_len;

	if (tY == 0.0)
		return (0);
	plane_len = sqrt(p->plane_x * p->plane_x + p->plane_y * p->plane_y);
	if (fabs(tX / tY) <= plane_len * margin)
		return (1);
	return (0);
}
