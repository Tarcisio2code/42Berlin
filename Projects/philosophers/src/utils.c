/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:13:38 by tsilva            #+#    #+#             */
/*   Updated: 2024/12/13 15:32:54 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/**
 * @brief Prints a formatted error message to the standard output.
 * @param msg The specific error description.
 * @return Always returns 0 for consistent error handling in calling functions.
 */
int	print_error(const char *msg)
{
	if (msg)
		printf("Error:\n%s\n", msg);
	return (0);
}

/**
 * @brief Converts a string to a long integer with basic overflow and 
 * non-digit character validation.
 * @param str The string to convert.
 * @return The converted long, or 0 if invalid or exceeding INT_MAX.
 */
long	ft_atoi_long(const char *str)
{
	int		sn;
	long	r;

	sn = 1;
	r = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if ((*str == '+' || *str == '-') && *str++ == '-')
		sn = -1;
	while (*str >= 48 && *str <= 57)
	{
		r = r * 10 + (*str - 48);
		str++;
	}
	if ((*str && !(*str >= 48 && *str <= 57)) || r > INT_MAX)
		r = 0;
	return (r * sn);
}

/**
 * @brief Parses command line arguments into the global data structure.
 * Converts input milliseconds to microseconds for use with precise timers.
 * Validates against project constraints (e.g., max 200 philosophers, 60ms min).
 * @return 1 if valid, 0 if an error is detected.
 */
int	parse_and_check_args(t_data *ph_data, char **argv, int argc)
{
	if (!(argc == 5 || argc == 6))
		return (print_error("Wrong number of arguments"));
	ph_data->ph_num = ft_atoi_long(argv[1]);
	ph_data->t_die = ft_atoi_long(argv[2]) * 1000L;
	ph_data->t_eat = ft_atoi_long(argv[3]) * 1000L;
	ph_data->t_sleep = ft_atoi_long(argv[4]) * 1000L;
	if (argv[5])
		ph_data->n_meals = ft_atoi_long(argv[5]);
	if (ph_data->ph_num <= 0 || ph_data->ph_num > 200
		|| ph_data->t_die < 60000 || ph_data->t_eat < 60000
		|| ph_data->t_sleep < 60000 || (argv[5] && ph_data->n_meals <= 0))
		return (print_error("Invalid entry"));
	if (!argv[5])
		ph_data->n_meals = -1;
	return (1);
}

/**
 * @brief Releases all allocated memory and destroys initialized mutexes.
 * Ensures the simulation shuts down cleanly without resource leaks.
 * @param ph_data Pointer to the main simulation context.
 * @return EXIT_SUCCESS if cleaned, EXIT_FAILURE if pointers are null.
 */
int	clean_data(t_data *ph_data)
{
	int		ph_id;

	if (!ph_data->ph_members)
		return (EXIT_FAILURE);
	ph_id = -1;
	while (++ph_id < ph_data->ph_num)
		pthread_mutex_destroy(&ph_data->ph_members[ph_id].ph_mtx);
	pthread_mutex_destroy(&ph_data->ph_activity_mtx);
	pthread_mutex_destroy(&ph_data->ph_data_mtx);
	free(ph_data->ph_members);
	ph_data->ph_members = NULL;
	if (!ph_data->ph_forks)
		return (EXIT_FAILURE);
	free(ph_data->ph_forks);
	ph_data->ph_forks = NULL;
	return (EXIT_SUCCESS);
}

/**
 * @brief Retrieves the current time in milliseconds.
 * Uses gettimeofday to calculate elapsed time since the Epoch.
 * @return Current timestamp in milliseconds.
 */
long	ft_now(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000L) + (tv.tv_usec / 1000L));
}
