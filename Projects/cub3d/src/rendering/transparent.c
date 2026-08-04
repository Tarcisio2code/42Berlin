/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transparent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:20:41 by tsilva            #+#    #+#             */
/*   Updated: 2025/11/04 12:09:14 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"

static void	destination_rgb(t_image *img, int idx, int bpp, unsigned int *rgb);
static void	source_rgb(int color, unsigned int *rgb);
static void	blend_colors(unsigned int *dst, unsigned int *src,
				unsigned char *out);

/*
** Transparent Background Drawing
** This function draws a single transparent pixel by:
** 1. Checking if pixel coordinates are within window bounds
** 2. Converting color formats and calculating memory positions
** 3. Blending source (new) and destination (existing) colors
** Parameters:
**   - game: Main game structure containing window image
**   - px,py: Pixel coordinates
**   - color: Color to be drawn with transparency
*/
void	draw_transparent_background(t_game *game, int px, int py, int color)
{
	unsigned char	*out;
	unsigned int	src[3];
	unsigned int	dst[3];
	int				idx;
	int				bpp;

	if (px < 0 || py < 0 || px >= WIN_WIDTH || py >= WIN_HEIGHT)
		return ;
	bpp = game->win_img.bpp / 8;
	idx = py * game->win_img.size_line + px * bpp;
	destination_rgb(&game->win_img, idx, bpp, dst);
	source_rgb(color, src);
	out = (unsigned char *)game->win_img.data + idx;
	blend_colors(dst, src, out);
	if (bpp == 4)
		out[3] = 0;
}

/*
** Destination RGB Extractor
** Extracts RGB components from the existing image at specified position:
** 1. Accesses raw image data at calculated index
** 2. Initializes RGB array to black (0,0,0)
** 3. If image has at least 3 bytes per pixel, extracts BGR components
** Note: MLX stores colors in BGR format
*/
static void	destination_rgb(t_image *img, int idx, int bpp, unsigned int *rgb)
{
	unsigned char	*data;

	data = (unsigned char *)img->data;
	rgb[0] = 0;
	rgb[1] = 0;
	rgb[2] = 0;
	if (bpp >= 3)
	{
		rgb[2] = data[idx + 2];
		rgb[1] = data[idx + 1];
		rgb[0] = data[idx + 0];
		return ;
	}
}

/*
** Source RGB Extractor
** Converts a 32-bit color value into separate RGB components:
** 1. Masks out alpha channel (if any) with 0x00FFFFFF
** 2. Extracts individual color channels using bit shifts
** 3. Stores components in RGB array for blending
*/
static void	source_rgb(int color, unsigned int *rgb)
{
	unsigned int	src;

	src = (unsigned int)color & 0x00FFFFFF;
	rgb[2] = (src >> 16) & 0xFF;
	rgb[1] = (src >> 8) & 0xFF;
	rgb[0] = src & 0xFF;
}

/*
** Color Blending Function
** Implements alpha blending between source and destination colors:
** 1. Uses fixed 50% transparency (alpha = 128)
** 2. Calculates inverse alpha for destination color weight
** 3. Blends each color channel separately using the formula:
**    result = (src * alpha + dst * (255-alpha)) / 255
*/
static void	blend_colors(unsigned int *dst, unsigned int *src,
			unsigned char *out)
{
	int	alpha;
	int	inv;

	alpha = 128;
	inv = 255 - alpha;
	out[2] = (unsigned char)((src[2] * alpha + dst[2] * inv) / 255);
	out[1] = (unsigned char)((src[1] * alpha + dst[1] * inv) / 255);
	out[0] = (unsigned char)((src[0] * alpha + dst[0] * inv) / 255);
}

/*
** Transparent Box Drawing
** Draws a filled rectangle with transparency:
** 1. Takes starting coordinates and desired color
** 2. Iterates over box dimensions (MINI_TILE_SIZE x MINI_TILE_SIZE)
** 3. Calls transparent_background for each pixel in the box
** Used primarily for minimap overlay elements
*/
void	draw_transparent_box(t_game *game, int s_x, int s_y, int color)
{
	int	dx;
	int	dy;

	dy = 0;
	while (dy < MINI_TILE_SIZE)
	{
		dx = 0;
		while (dx < MINI_TILE_SIZE)
		{
			draw_transparent_background(game, s_x + dx, s_y + dy, color);
			dx++;
		}
		dy++;
	}
}
