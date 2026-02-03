/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 23:35:43 by aaboudra          #+#    #+#             */
/*   Updated: 2025/08/27 22:54:47 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>

typedef enum s_status
{
	EATING,
	SLEEPING,
	THINKING,
	DEAD,
	TIKE_FERST_FORK,
	TIKE_SECEND_FORK,
}	t_status;

typedef enum s_time
{
	MILLISECOND,
	MICROSECOND,
}	t_time;

typedef enum s_operation
{
	INIT,
	DESTROY,
	LOCK,
	UNLOCK,
	CREATE,
	JOIN,
	DETACH,
}	t_operation;

typedef struct s_data	t_data;

typedef struct s_gc_node
{
	void				*ptr;
	struct s_gc_node	*next;
}	t_gc_node;

typedef struct s_fork
{
	pthread_mutex_t	fork;
}	t_fork;

typedef struct s_philo
{
	int				philo_id;
	pthread_t		thread_id;
	long			time_last_meal;
	long			meals_conter;
	bool			is_full;
	t_fork			*first_fork;
	t_fork			*secend_fork;
	t_data			*data;
	pthread_mutex_t	philo_mutx;
}	t_philo;

struct s_data
{
	t_philo			*philos;
	t_fork			*forks;
	long			nbr_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			nbr_limte_meals;
	long			start_sum;
	long			philos_runing;
	bool			the_end;
	bool			all_philos_ready;
	pthread_t		manager;
	pthread_mutex_t	data_mutx;
	pthread_mutex_t	for_write;
	t_gc_node		*gc_list;
};

int		parce_input(char **av, t_data *data);
int		init_data(t_data *data);
void	operation_thread(pthread_t *thread, void *(*routine)(void *),
			void *data, t_operation action);
void	operation_mutex(pthread_mutex_t *mutex,
			t_operation action, t_data *data);
int		error_detector(char *str, int check, t_data *data);
void	*gc_malloc(size_t size, t_data *data);
void	free_all(t_data *data);
void	set_bool(pthread_mutex_t	*mtx, bool *dest, bool value, t_data *data);
bool	get_bool(pthread_mutex_t	*mtx, bool *value, t_data *data);
void	set_long(pthread_mutex_t	*mtx, long *dest, long value, t_data *data);
long	get_long(pthread_mutex_t	*mtx, long *value, t_data *data);
void	start_simulation(t_data *data);
long	get_time(t_time status);
void	white_for_syncronisation(t_data *data);
void	write_status(t_status status, t_philo *philo);
void	*manger_works(void *arg);
void	syncro_runing_philos(pthread_mutex_t *mtx, long *dest, t_data *data);
void	clean_data(t_data *data);
void	precise_usleep(long usec, t_data *data);
void	*simulation_for_one(void *arg);
void	usleep_help(long start, long usec);
int		check_sign(const char **str, t_data *data);
int		check_spaces_and_digits(const char *str, t_data *data);
int		is_space(int c);
int		ft_isdigit(int c);
void	print_status(t_status status, long time, t_philo *philo);
#endif
