/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:58:26 by tsilva            #+#    #+#             */
/*   Updated: 2024/12/12 17:58:55 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	create_threads(t_data *ph_data);

/**
 * @brief Initializes and launches the simulation.
 * Handles the special case for a single philosopher and synchronizes the 
 * start of all threads using a 'ready' flag. After spawning, it waits 
 * for all threads to finish before returning.
 * @param ph_data Pointer to the main simulation context.
 */
void	start_dinner(t_data *ph_data)
{
	int	ph_id;

	if (ph_data->n_meals == 0)
		return ;
	ph_data->dinner_start_time = ft_now();
	if (ph_data->ph_num == 1)
	{
		show_action(HAS_FORK_ONE, &ph_data->ph_members[0]);
		precise_sleep(ph_data->t_die / 1000L, ph_data);
		show_action(DIED, &ph_data->ph_members[0]);
		return ;
	}
	if (!create_threads(ph_data))
		return ;
	set_b(&ph_data->ph_data_mtx, &ph_data->th_ready, true);
	ph_id = -1;
	while (++ph_id < ph_data->ph_num)
	{
		if (!th_handle(ph_data, ph_id, JOIN_DINNER))
			return ;
	}

	// Final simulation cleanup happens after the JOIN_MONITOR
	set_b(&ph_data->ph_data_mtx, &ph_data->dinner_over, true);
	if (!th_handle(ph_data, 0, JOIN_MONITOR))
		return ;
}

/**
 * @brief Spawns the individual philosopher threads and the monitor thread.
 * The monitor is created last to ensure all philosophers are already 
 * initialized and ready to be tracked.
 * @return 1 on success, 0 if any thread creation fails.
 */
static int	create_threads(t_data *ph_data)
{
	int	ph_id;

	ph_id = -1;
	while (++ph_id < ph_data->ph_num)
	{
		if (!th_handle(ph_data, ph_id, CREATE_DINNER))
			return (0);
	}
	if (!th_handle(ph_data, 0, CREATE_MONITOR))
		return (0);
	return (1);
}
