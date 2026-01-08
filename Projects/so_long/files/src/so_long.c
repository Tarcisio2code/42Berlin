/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 23:30:13 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/08 17:03:26 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/**
 * main - Entry point of the program.
 * @argc: The number of command line arguments.
 * @argv: The array of command line arguments.
 *
 * This function initializes the game, loads the map, checks the map validity,
 * starts the game, and performs cleanup before exiting.
 *
 * @return: Always returns 0.
 */
int	main(int argc, char **argv)
{
    t_vars	game;

    check_name(argv[1], argc);
    init_game_vars(&game);
    open_map(argv, &game);
    if (check_map(&game))
        start_game(&game);
    free_vars(&game);
    return (0);
}