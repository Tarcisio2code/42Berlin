/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters_getters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:19:42 by tsilva            #+#    #+#             */
/*   Updated: 2024/08/07 10:07:49 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/**
 * @brief Thread-safe setter for boolean variables.
 * Protects the shared boolean from data races using the provided mutex.
 * @param mtx Mutex associated with the variable.
 * @param dst Pointer to the boolean to be updated.
 * @param val New value to assign.
 */
void	set_b(pthread_mutex_t *mtx, bool *dst, bool val)
{
	mtx_handle(mtx, LOCK);
	*dst = val;
	mtx_handle(mtx, UNLOCK);
}

/**
 * @brief Thread-safe getter for boolean variables.
 * @param mtx Mutex associated with the variable.
 * @param val Pointer to the boolean to be read.
 * @return The current value of the boolean.
 */
bool	get_b(pthread_mutex_t *mtx, bool *val)
{
	bool	r;

	mtx_handle(mtx, LOCK);
	r = *val;
	mtx_handle(mtx, UNLOCK);
	return (r);
}

/**
 * @brief Thread-safe setter for long variables (timestamps, meal counts).
 * Essential for synchronizing values shared between philosopher and monitor threads.
 * @param mtx Mutex associated with the variable.
 * @param dst Pointer to the long to be updated.
 * @param val New value to assign.
 */
void	set_l(pthread_mutex_t *mtx, long *dst, long val)
{
	mtx_handle(mtx, LOCK);
	*dst = val;
	mtx_handle(mtx, UNLOCK);
}

/**
 * @brief Thread-safe getter for long variables.
 * @param mtx Mutex associated with the variable.
 * @param val Pointer to the long to be read.
 * @return The current value of the long.
 */
long	get_l(pthread_mutex_t *mtx, long *val)
{
	long	r;

	mtx_handle(mtx, LOCK);
	r = *val;
	mtx_handle(mtx, UNLOCK);
	return (r);
}
