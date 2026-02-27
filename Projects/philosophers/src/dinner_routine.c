/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:58:26 by tsilva            #+#    #+#             */
/*   Updated: 2024/12/11 12:54:13 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	check_dinner_status(t_data *ph_data);

/**
 * @brief The main lifecycle loop for each philosopher thread.
 * Synchronizes start time, staggers execution to prevent immediate deadlocks,
 * and cycles through Eating, Sleeping, and Thinking until the dinner ends.
 */
void	*dinner_routine(void *data)
{
	t_philo	*ph_member;

	ph_member = (t_philo *)data;
	wait_threads_ready(ph_member->ph_data);
	set_l(&ph_member->ph_mtx, &ph_member->last_meal, ft_now());
	count_running_threads(ph_member->ph_data, &ph_member->ph_data->th_running);

	// Desynchronize even philosophers by a small margin (1ms) to allow
	// odd philosophers to acquire forks first, reducing initial contention
	if (ph_member->ph_data->ph_num % 2 == 0 && ph_member->ph_id % 2 == 0)
		precise_sleep(1L, ph_member->ph_data);
	else if (ph_member->ph_id % 2)
		odd_philo_handle(ph_member);
	while (!end_of_dinner(ph_member->ph_data))
	{
		if (ph_member->ph_full)
			break ;
		eating_routine(ph_member);
		show_action(SLEEPING, ph_member);
		precise_sleep(ph_member->ph_data->t_sleep / 1000L, ph_member->ph_data);
		show_action(THINKING, ph_member);
		odd_philo_handle(ph_member);
	}
	return (NULL);
}

/**
 * @brief Handles the fork acquisition and consumption logic.
 * Protects meal timestamps and counters with philosopher-specific mutexes
 * and ensures forks are released immediately after eating.
 * @param ph_member The philosopher currently attempting to eat.
 */
void	eating_routine(t_philo *ph_member)
{
	mtx_handle(&ph_member->r_fork->ph_fork, LOCK);
	show_action(HAS_FORK_ONE, ph_member);
	mtx_handle(&ph_member->l_fork->ph_fork, LOCK);
	show_action(HAS_FORK_TWO, ph_member);
	set_l(&ph_member->ph_mtx, &ph_member->last_meal, ft_now());
	ph_member->n_meals++;
	show_action(EATING, ph_member);
	precise_sleep(ph_member->ph_data->t_eat / 1000L, ph_member->ph_data);
	if (ph_member->ph_data->n_meals > 0)
	{
		if (ph_member->n_meals == ph_member->ph_data->n_meals)
			set_b(&ph_member->ph_mtx, &ph_member->ph_full, true);
	}
	mtx_handle(&ph_member->r_fork->ph_fork, UNLOCK);
	mtx_handle(&ph_member->l_fork->ph_fork, UNLOCK);
}

/**
 * @brief Background observer thread that monitors the entire simulation.
 * It waits for all threads to be active, then continuously polls for
 * philosopher deaths or the completion of all required meals.
 */
void	*monitor(void *data)
{
	t_data	*ph_data;
	int		status;

	ph_data = (t_data *)data;
	wait_threads_ready(ph_data);
	while (!threads_running(&ph_data->ph_data_mtx, ph_data))
		usleep(100);
	while (!end_of_dinner(ph_data))
	{
		status = check_dinner_status(ph_data);
		if (status == FINISHED || status == PHILO_DIED)
		{
			set_b(&ph_data->ph_data_mtx, &ph_data->dinner_over, true);
			break ;
		}
		usleep(1000);
	}
	return (NULL);
}

/**
 * @brief Performs a sweep of all philosophers to check their status.
 * Calculates time since last meal against 'time_to_die' and verifies if 
 * all philosophers have reached their 'n_meals' requirement.
 * @return PHILO_DIED if a death is detected, FINISHED if all are full, 
 * or CONTINUE to keep the simulation running.
 */
static int	check_dinner_status(t_data *ph_data)
{
	t_philo	*ph_member;
	long	current_time;
	long	last_meal;
	int		i;

	i = -1;
	while (++i < ph_data->ph_num)
	{
		ph_member = &ph_data->ph_members[i];
		current_time = ft_now();
		last_meal = get_l(&ph_member->ph_mtx, &ph_member->last_meal);
		if (current_time - last_meal > ph_data->t_die / 1000L)
		{
			show_action(DIED, ph_member);
			return (PHILO_DIED);
		}
		if (ph_data->n_meals > 0 
			&& !get_b(&ph_member->ph_mtx, &ph_member->ph_full))
			return (CONTINUE);
	}
	if (ph_data->n_meals > 0)
		return (FINISHED);
	return (CONTINUE);
}
