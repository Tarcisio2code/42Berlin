/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:46:09 by tsilva            #+#    #+#             */
/*   Updated: 2024/12/13 15:57:33 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/**
 * @brief Unified wrapper for mutex operations.
 * Handles locking, unlocking, initialization, and destruction while 
 * centralizing error reporting.
 * @return 1 on success, 0 if a pthread_mutex function returns an error.
 */
int	mtx_handle(pthread_mutex_t *mutex, t_thcode thcode)
{
	int	err;

	err = 0;
	if (thcode == LOCK)
		err = pthread_mutex_lock(mutex);
	else if (thcode == UNLOCK)
		err = pthread_mutex_unlock(mutex);
	else if (thcode == INIT)
		err = pthread_mutex_init(mutex, NULL);
	else if (thcode == DESTROY)
		err = pthread_mutex_destroy(mutex);
	if (err)
		return (print_error("Mutex fail"));
	return (1);
}

/**
 * @brief Unified wrapper for thread lifecycle management.
 * Dispatches thread creation (for philosophers, single-philo edge case, or monitor)
 * and thread joining, while validating operation success.
 * @return 1 on success, 0 if a pthread_create/join operation fails.
 */
int	th_handle(t_data *ph_data, int ph_id, t_thcode op)
{
	int	err;

	err = 0;
	if (op == CREATE_DINNER)
		err = pthread_create(&ph_data->ph_members[ph_id].th_id, NULL,
				dinner_routine, &ph_data->ph_members[ph_id]);
	else if (op == JOIN_DINNER)
		err = pthread_join(ph_data->ph_members[ph_id].th_id, NULL);
	else if (op == CREATE_ALONE)
		err = pthread_create(&ph_data->ph_members[ph_id].th_id, NULL,
				alone_philosopher_routine, &ph_data->ph_members[ph_id]);
	else if (op == CREATE_MONITOR)
		err = pthread_create(&ph_data->ph_monitor, NULL, monitor, ph_data);
	else if (op == JOIN_MONITOR)
		err = pthread_join(ph_data->ph_monitor, NULL);
	if (err)
		return (print_error("Thread fail"));
	return (1);
}

/**
 * @brief Blocks the calling thread until the 'th_ready' flag is set to true.
 * Used to ensure all philosophers start their routine simultaneously.
 */
void	wait_threads_ready(t_data *ph_data)
{
	while (!get_b(&ph_data->ph_data_mtx, &ph_data->th_ready))
		usleep(100);
}

/**
 * @brief Thread-safe increment of the global active thread counter.
 * Helps the monitor know exactly how many threads have successfully launched.
 */
void	count_running_threads(t_data *ph_data, long *th_num)
{
	mtx_handle(&ph_data->ph_data_mtx, LOCK);
	(*th_num)++;
	mtx_handle(&ph_data->ph_data_mtx, UNLOCK);
}

/**
 * @brief Thread-safe check to verify if all expected threads are running.
 * @return True if the count of running threads matches the total number 
 * of philosophers.
 */
bool	threads_running(pthread_mutex_t *mtx, t_data *ph_data)
{
	bool	is_running;

	is_running = false;
	mtx_handle(mtx, LOCK);
	if (ph_data->th_running == ph_data->ph_num)
		is_running = true;
	mtx_handle(mtx, UNLOCK);
	return (is_running);
}
