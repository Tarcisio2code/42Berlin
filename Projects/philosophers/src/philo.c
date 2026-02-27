/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:38:09 by tsilva            #+#    #+#             */
/*   Updated: 2024/12/13 15:29:25 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/**
 * @brief Entry point of the Philosophers simulation.
 * * 1. Parses and validates CLI arguments.
 * 2. Initializes the global data structure (mutexes, memory, and philosophers).
 * 3. Starts the simulation threads and the monitor.
 * 4. Ensures all resources are freed and mutexes destroyed before exiting.
 * * @return EXIT_SUCCESS on completion, EXIT_FAILURE on invalid input or init error.
 */
int	main(int argc, char **argv)
{
	t_data	ph_data;

	// Validate inputs and convert units
	if (!parse_and_check_args(&ph_data, argv, argc))
		return (EXIT_FAILURE);

	// Initialize simulation resources (forks, threads, data)
	if (set_data(&ph_data))
		start_dinner(&ph_data);

	// Deallocate memory and destroy all mutexes
	return (clean_data(&ph_data));
}
