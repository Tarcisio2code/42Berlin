/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 23:30:13 by tsilva            #+#    #+#             */
/*   Updated: 2025/11/01 12:07:50 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/parse_and_validation.h"
#include "../inc/game_core.h"

int	main(int argc, char **argv)
{
	t_game	game;

	check_entry(argv[1], argc);
	init_game_vars(argv[1], &game);
	parse_scene(&game);				// Read and process the .cub file (extracting textures, colors, and map data).
	validate_scene(&game);			// Perform checks on the parsed data (e.g., map structure, wall closure, player spawn).
	find_sprites(&game);
	start_game(&game);
	free_vars(&game);
	return (0);
}
