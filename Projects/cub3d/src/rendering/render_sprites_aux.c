/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites_aux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 18:08:55 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/11/04 14:32:34 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../inc/parse_and_validation.h"
#include "../../inc/rendering.h"

int	clampi(int v, int lo, int hi)
{
	if (v < lo)
		return (lo);
	if (v > hi)
		return (hi);
	return (v);
}

int	inv_det(t_player *p, double *out)
{
	double	det;

	det = (p->plane_x * p->dir_y) - (p->dir_x * p->plane_y);
	if (det == 0.0)
		return (0);
	*out = 1.0 / det; 
	return (1);
}

void	cam_transform(t_player *p, t_sprite *s, double *tX, double *tY)
{
	double	dx;
	double	dy;

	dx = (s->x - p->x);
	dy = (s->y - p->y);
	*tX = s->invd * (p->dir_y * dx - p->dir_x * dy);
	*tY = s->invd * (-p->plane_y * dx + p->plane_x * dy);
}

int	screen_x_from_tx_ty(double tX, double tY)
{
	int	screen_x;

	screen_x = (int)((WIN_WIDTH / 2.0) * (1.0 + tX / tY));
	return (screen_x);
}

int	size_from_ty_scale(double tY, double scale)
{
	int	base;
	int	size;

	if (scale <= 0.0)
		scale = 1.0;
	base = abs((int)(WIN_HEIGHT / tY));
	size = (int)(base * scale);
	return (size);
}
