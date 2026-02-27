/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:36:48 by tsilva            #+#    #+#             */
/*   Updated: 2024/12/16 09:14:48 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <pthread.h>
#include <sys/time.h>

#define RESET  "\033[0m"
#define RED    "\033[1;31m"
#define GREEN  "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE   "\033[1;34m"
#define PURPLE "\033[1;35m"
#define CYAN   "\033[1;36m" 

/**
 * @enum t_thcode
 * @brief Thread and mutex operation codes for cleaner error handling wrappers.
 */
typedef enum e_thcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE_DINNER,
	CREATE_MONITOR,
	CREATE_ALONE,
	JOIN_DINNER,
	JOIN_MONITOR,
	DETACH,
}			t_thcode;

/**
 * @enum t_ph_action
 * @brief Status codes for logging philosopher activities.
 */
typedef enum e_action
{
	EATING,
	SLEEPING,
	THINKING,
	HAS_FORK_ONE,
	HAS_FORK_TWO,
	DIED,
}			t_ph_action;

/**
 * @enum t_dinner_status
 * @brief Simulation lifecycle states.
 */
typedef enum e_dinner_status
{
	CONTINUE,
	FINISHED,
	PHILO_DIED,
}			t_dinner_status;

typedef struct s_data	t_data;

/**
 * @struct t_ph_fork
 * @brief Representation of a fork using a mutex for concurrency control.
 */
typedef struct s_ph_fork
{
	pthread_mutex_t	ph_fork;
	int				ph_fork_n; // Fork ID for tracking/debugging
}				t_ph_fork;

/**
 * @struct t_philo
 * @brief Individual philosopher state and thread context.
 */
typedef struct s_philo
{
	int				ph_id;
	long			n_meals;    // Number of meals consumed
	long			last_meal;  // Timestamp of the last meal
	bool			ph_full;    // True if n_meals requirement is met
	t_ph_fork		*l_fork;    // Pointer to left fork
	t_ph_fork		*r_fork;    // Pointer to right fork
	pthread_t		th_id;      // Philosopher's thread ID
	t_data			*ph_data;   // Pointer to shared global data
	pthread_mutex_t	ph_mtx;     // Mutex for philosopher-specific data protection
}				t_philo;

/**
 * @struct s_data
 * @brief Global simulation context and synchronization resources.
 */
struct s_data
{
	long			ph_num;
	long			t_die;
	long			t_eat;
	long			t_sleep;
	long			n_meals;
	// State & Sync
	long			dinner_start_time;
	long			th_running;			// Counter for active threads
	bool			dinner_over;		// Global termination flag
	bool			th_ready;			// Sync flag to start all threads at once
	// Resources
	t_ph_fork		*ph_forks;
	t_philo			*ph_members;
	pthread_mutex_t	ph_data_mtx;		// Mutex for global state protection
	pthread_mutex_t	ph_activity_mtx;	// Mutex for thread-safe console output
	pthread_t		ph_monitor;			// Death and meal monitoring thread
};

/* --- Lifecycle & Routine --- */
int     set_data(t_data *ph_data);                      // Init memory and mutexes
void    start_dinner(t_data *ph_data);                  // Spawns threads and joins them
void    *dinner_routine(void *ph_data);                 // Main Philsopher loop
void    eating_routine(t_philo *ph_member);             // Fork logic and eating duration
void    *monitor(void *data);                           // Monitor thread routine

/* --- Logic Utils --- */
void    show_action(t_ph_action ph_action, t_philo *ph_member); // Thread-safe logger
bool    end_of_dinner(t_data *ph_data);                         // Global end check
void    *alone_philosopher_routine(void *data);                 // Edge case logic
void    odd_philo_handle(t_philo *ph_member);                   // Balance delay for odd num
void    precise_sleep(long sleep_time, t_data *ph_data);        // Accurate sleep loop

/* --- Thread & Mutex Management --- */
int     mtx_handle(pthread_mutex_t *mutex, t_thcode thcode);    // Mutex wrapper
int     th_handle(t_data *ph_data, int ph_id, t_thcode op);     // Thread wrapper
void    wait_threads_ready(t_data *ph_data);                    // Start-sync barrier
void    count_running_threads(t_data *ph_data, long *th_num);   // Counter incrementer
bool    threads_running(pthread_mutex_t *mtx, t_data *ph_data); // Verify all launched

/* --- Safe Getters & Setters --- */
void    set_b(pthread_mutex_t *mtx, bool *dst, bool val);       // Set boolean thread-safely
bool    get_b(pthread_mutex_t *mtx, bool *val);                 // Get boolean thread-safely
void    set_l(pthread_mutex_t *mtx, long *dst, long val);       // Set long thread-safely
long    get_l(pthread_mutex_t *mtx, long *val);                 // Get long thread-safely

/* --- General Utils --- */
int     print_error(const char *msg);                           // Error logger
long    ft_atoi_long(const char *str);                          // Input conversion
int     parse_and_check_args(t_data *ph_data, char **argv, int argc); // Arg validation
long    ft_now(void);                                           // Get current ms
int     clean_data(t_data *ph_data);                            // Free and destroy all
