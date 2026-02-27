/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:13:38 by tsilva            #+#    #+#             */
/*   Updated: 2024/12/13 16:19:02 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	init_mutexes(t_data *ph_data);
static int	init_memory(t_data *ph_data);
static int	set_philo(t_data *ph_data);
static void	get_forks(t_philo *philo, t_ph_fork *ph_fork, int ph_pos);

/**
 * @brief Main entry point for data initialization. Sets default states
 * and triggers memory allocation, mutex creation, and philosopher setup.
 * @return 1 on success, 0 if any initialization step fails.
 */
int	set_data(t_data *ph_data)
{
	ph_data->th_ready = false;
	ph_data->th_running = 0;
	ph_data->dinner_over = false;
	ph_data->ph_members = NULL;
	ph_data->ph_forks = NULL;
	if (!init_memory(ph_data))
		return (0);
	if (!init_mutexes(ph_data))
	{
		free(ph_data->ph_members);
		ph_data->ph_members = NULL;
		free(ph_data->ph_forks);
		return (0);
	}
	return (set_philo(ph_data));
}

/**
 * @brief Allocates heap memory for the array of philosophers and the array of forks.
 * @return 1 on success, 0 on allocation failure (with error message).
 */
static int	init_memory(t_data *ph_data)
{
	ph_data->ph_members = malloc(sizeof(t_philo) * ph_data->ph_num);
	if (!ph_data->ph_members)
		return (print_error("Unable to allocate memory"));
	ph_data->ph_forks = malloc(sizeof(t_ph_fork) * ph_data->ph_num);
	if (!ph_data->ph_forks)
	{
		free(ph_data->ph_members);
		ph_data->ph_members = NULL;
		return (print_error("Unable to allocate memory"));
	}
	return (1);
}

/**
 * @brief Initializes all necessary mutexes: global state, logging, and 
 * individual forks. Handles partial cleanup if a mutex fails mid-loop.
 * @return 1 on success, 0 if a mutex operation fails.
 */
static int	init_mutexes(t_data *ph_data)
{
	int	n;

	if (!mtx_handle(&ph_data->ph_data_mtx, INIT))
		return (0);
	if (!mtx_handle(&ph_data->ph_activity_mtx, INIT))
	{
		pthread_mutex_destroy(&ph_data->ph_data_mtx);
		return (0);
	}
	n = 0;
	while (n < ph_data->ph_num)
	{
		if (!mtx_handle(&ph_data->ph_forks[n].ph_fork, INIT))
		{
			pthread_mutex_destroy(&ph_data->ph_data_mtx);
			pthread_mutex_destroy(&ph_data->ph_activity_mtx);
			return (0);
		}
		ph_data->ph_forks[n].ph_fork_n = n;
		n++;
	}
	return (1);
}

/**
 * @brief Initializes individual philosopher structures, including their IDs,
 * personal mutexes, and fork assignments.
 * @return 1 on success, 0 if initialization fails.
 */
static int	set_philo(t_data *ph_data)
{
	int		n;
	t_philo	*ph_member;

	n = 0;
	while (n < ph_data->ph_num)
	{
		ph_member = ph_data->ph_members + n;
		ph_member->ph_id = n + 1;
		ph_member->ph_full = false;
		ph_member->n_meals = 0;
		ph_member->last_meal = 0;
		ph_member->ph_data = ph_data;
		if (!mtx_handle(&ph_member->ph_mtx, INIT))
		{
			free(ph_data->ph_forks);
			ph_data->ph_forks = NULL;
			return (0);
		}
		get_forks(ph_member, ph_data->ph_forks, n++);
	}
	return (1);
}

/**
 * @brief Assigns left and right fork pointers to each philosopher.
 * Implements an asymmetry strategy (swapping forks for even-indexed philosophers)
 * to prevent circular wait deadlocks.
 * * @param philo The philosopher receiving the forks.
 * @param ph_fork The global array of forks.
 * @param ph_pos The philosopher's position in the array.
 */
static void	get_forks(t_philo *philo, t_ph_fork *ph_fork, int ph_pos)
{
	int	ph_num;

	ph_num = philo->ph_data->ph_num;
	philo->r_fork = &ph_fork[(ph_pos + 1) % ph_num];
	philo->l_fork = &ph_fork[ph_pos];

	// Deadlock prevention: Swapping fork priority for even philosophers
	if (philo->ph_id % 2 == 0)
	{
		philo->r_fork = &ph_fork[ph_pos];
		philo->l_fork = &ph_fork[(ph_pos + 1) % ph_num];
	}
}
