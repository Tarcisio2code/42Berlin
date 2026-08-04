/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 19:00:30 by tsilva            #+#    #+#             */
/*   Updated: 2025/11/04 14:34:39 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include "../inc/game_core.h"
# include "../inc/structs.h"

void	render_3d_scene(t_game *game);
void	put_pixel(t_image *img, int x, int y, int color);
int		argb_color(int *rgb_color);
void	init_ray(t_game *game, t_ray *ray, int x);
int		get_texture_color(t_image *tex, int x, int y);
void	calc_step_and_side_dist(t_ray *ray);
void	perform_dda(t_game *game, t_ray *ray);
void	calc_wall_height(t_ray *ray);
void	calc_texture_x(t_ray *ray, t_image *tex);
t_image	*get_wall_texture(t_game *game, t_ray *ray);
void	draw_mini_map(t_game *game);
void	draw_transparent_background(t_game *game, int x, int y, int color);
void	draw_transparent_box(t_game *game, int s_x, int s_y, int color);
void	render_game_over_screen(t_game *game);
void	render_help_screen(t_game *game);
void	render_floor_ceil_column(t_game *game, int x, int top, int bot);
void	render_sprites(t_game *game);
void	update_collectibles(t_game *game);
void	render_score(t_game *game);
int		clampi(int v, int lo, int hi);
int		inv_det(t_player *p, double *out);
void	cam_transform(t_player *p, t_sprite *s, double *tX, double *tY);
int		screen_x_from_tx_ty(double tX, double tY);
int		size_from_ty_scale(double tY, double scale);
void	set_bounds(t_sprite_proj *pr, int screenX, int size);
int		sprite_within_fov(t_player *p, double tX, double tY, double margin);

#endif