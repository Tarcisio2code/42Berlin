/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:08:06 by tsilva            #+#    #+#             */
/*   Updated: 2024/12/12 11:00:54 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/**
 * @brief Logs philosopher activities to the console in a thread-safe manner.
 * Ensures that timestamps are relative to the dinner start and that no logs
 * are printed after a philosopher has died or the simulation has ended.
 * @param ph_action The specific action to print.
 * @param ph_member The philosopher performing the action.
 */
void	show_action(t_ph_action ph_action, t_philo *ph_member)
{
	long	elap_time;

	mtx_handle(&ph_member->ph_data->ph_activity_mtx, LOCK);
	elap_time = ft_now() - ph_member->ph_data->dinner_start_time;
	if (ph_action == DIED)
		printf("%-10ld ms | philo %d " RED "💀 - died" RESET "\n", elap_time, ph_member->ph_id);
	else if (!end_of_dinner(ph_member->ph_data))
	{
		if (ph_action == HAS_FORK_ONE || ph_action == HAS_FORK_TWO)
			printf("%-10ld ms | philo %d " YELLOW "🍴 - has taken a fork" RESET "\n", elap_time, ph_member->ph_id);
		else if (ph_action == EATING)
			printf("%-10ld ms | philo %d " GREEN "🍝 - is eating" RESET "\n", elap_time, ph_member->ph_id);
		else if (ph_action == SLEEPING)
			printf("%-10ld ms | philo %d " BLUE "😴 - is sleeping" RESET "\n", elap_time, ph_member->ph_id);
		else if (ph_action == THINKING)
			printf("%-10ld ms | philo %d " PURPLE "💭 - is thinking" RESET "\n", elap_time, ph_member->ph_id);
	}
	mtx_handle(&ph_member->ph_data->ph_activity_mtx, UNLOCK);
}

/**
 * @brief Thread-safe check to determine if the simulation should terminate.
 * @return True if a philosopher died or all meal requirements were met.
 */
bool	end_of_dinner(t_data *ph_data)
{
	return (get_b(&ph_data->ph_data_mtx, &ph_data->dinner_over));
}

/**
 * @brief Specialized routine for the edge case of a single philosopher.
 * A lone philosopher will pick up one fork and wait to die, as they can 
 * never acquire a second fork to eat.
 */
void	*alone_philosopher_routine(void *data)
{
	t_philo	*ph_member;

	ph_member = (t_philo *)data;
	wait_threads_ready(ph_member->ph_data);
	set_l(&ph_member->ph_mtx, &ph_member->last_meal, ft_now());
	count_running_threads(ph_member->ph_data, &ph_member->ph_data->th_running);
	show_action(HAS_FORK_ONE, ph_member);
	while (!end_of_dinner(ph_member->ph_data))
		usleep(200);
	return (NULL);
}

/**
 * @brief Helps balance the simulation for odd numbers of philosophers.
 * Introduces a small delay to prevent desynchronization and potential 
 * starvation in cases where the schedule is tight.
 */
void	odd_philo_handle(t_philo *ph_member )
{
	long	wait_time;

	if (ph_member->ph_data->ph_num % 2 == 0)
		return ;
	wait_time = ph_member->ph_data->t_eat;
	precise_sleep(wait_time / 1000L, ph_member->ph_data);
}

/**
 * @brief A high-precision sleep function.
 * Instead of a single long usleep(), it breaks the wait into small chunks
 * and continuously checks the 'end_of_dinner' flag for immediate termination.
 * @param sleep_time Time to sleep in milliseconds.
 */
void	precise_sleep(long sleep_time, t_data *ph_data)
{
	long	start;

	start = ft_now();
	while ((ft_now() - start) < sleep_time && !end_of_dinner(ph_data))
		usleep(500);
}
