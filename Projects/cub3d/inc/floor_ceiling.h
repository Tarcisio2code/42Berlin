/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:34:13 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/11/04 12:03:32 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_CEILING_H
# define FLOOR_CEILING_H

# include "../inc/rendering.h"

typedef struct s_floor_params
{
	double	px;
	double	py;
	double	bx;
	double	by;
	double	wall_dist_tiles;
	bool	textured;
	int		x;
	int		y;
}			t_floor_params;

typedef struct s_floor_calc
{
	double	denom;
	double	row_dist;
	double	w;
	double	world_x;
	double	world_y;
	int		tx;
	int		ty;
	int		col;
}			t_floor_calc;

void			floor_wall_point(t_ray *ray, double *wx, double *wy);
t_floor_params	floor_row_params(t_game *game, t_ray *r);
void			draw_floor_row(t_game *game, t_floor_params *p);
void			draw_ceiling_row(t_game *game, t_floor_params *p);

#endif