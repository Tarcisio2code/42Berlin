/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_render_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:01:02 by tsilva            #+#    #+#             */
/*   Updated: 2025/11/03 17:57:12 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h" 

void	put_pixel(t_image *img, int x, int y, int color)
{
	int	offset;            // Final position in memory where pixel will be written
	int	bytes_per_pixel;   // Number of bytes used per pixel (typically 4 for 32-bit color)
	int	size_line;        // Number of bytes per horizontal line in the image

	// Calculate actual bytes per pixel from bits per pixel
	bytes_per_pixel = img->bpp / 8;     // Convert bits to bytes (e.g., 32 bits = 4 bytes)
	size_line = img->size_line;         // Get width of one line in bytes (includes padding)

	// Check if coordinates are within window bounds
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		// Calculate memory offset for pixel position
		offset = (y * size_line) + (x * bytes_per_pixel);
		
		// Safety check to prevent buffer overflow
		if (offset < 0 || offset + bytes_per_pixel > WIN_HEIGHT * size_line)
			return ;
			
		// Write color value directly to image memory at calculated offset
		*(unsigned int *)(img->data + offset) = color;
	}
}

int	argb_color(int *rgb_color)
{
	int	a;
	int	r;
	int	g;
	int	b;

	a = 255;
	r = rgb_color[0];
	g = rgb_color[1];
	b = rgb_color[2];
	return (((r & a) << 16) | ((g & a) << 8) | (b & a));
}

t_image	*get_wall_texture(t_game *game, t_ray *ray)
{
	if (game->map->data[ray->map_y][ray->map_x] == 'D')
		return (game->door.frames[0]);
	else if (game->map->data[ray->map_y][ray->map_x] == 'X')
		return (game->door.frames[game->door.curr_frame]);
	if (ray->side == 0)
	{
		if (ray->dir_x > 0)
			return (&game->textures.east);
		return (&game->textures.west);
	}
	if (ray->dir_y > 0)
		return (&game->textures.south);
	return (&game->textures.north);
}

int	get_texture_color(t_image *tex, int x, int y)
{
	int	*data;
	int	color;

	x = x % tex->width;  // Wrap x coordinate around texture width (texture repetition)
	y = y % tex->height; // Wrap y coordinate around texture height
	if (x < 0)          // Ensure x coordinate is not negative
		x = 0;
	if (y < 0)          // Ensure y coordinate is not negative
		y = 0;
	data = (int *)tex->data;  // Cast texture data to integer array for easier color access
	color = data[y * tex->width + x];  // Get color from texture at (x,y) using 1D array indexing
	return (color);
}
