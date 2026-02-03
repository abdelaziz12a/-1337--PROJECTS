/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safety_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 21:24:09 by aaboudra          #+#    #+#             */
/*   Updated: 2025/08/24 00:50:56 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	white_for_syncronisation(t_data *data)
{
	while (!get_bool(&data->data_mutx, &data->all_philos_ready, data))
		continue ;
}

static	int	sefty_mutx(int result, t_operation action, t_data *data)
{
	if (result != 0)
	{
		if (data)
			set_bool(&data->data_mutx, &data->the_end, true, data);
		if (action == INIT)
			error_detector("pthread_mutex_init failed\n", 1, data);
		if (action == DESTROY)
			error_detector("pthread_mutex_destroy failed\n", 1, data);
		if (action == LOCK)
			error_detector("pthread_mutex_lock failed\n", 1, data);
		if (action == UNLOCK)
			error_detector("pthread_mutex_unlock failed\n", 1, data);
		return (1);
	}
	return (0);
}

void	operation_mutex(pthread_mutex_t *mutex,
			t_operation action, t_data *data)
{
	if (action == INIT)
		sefty_mutx(pthread_mutex_init(mutex, NULL), action, data);
	if (action == DESTROY)
		sefty_mutx(pthread_mutex_destroy(mutex), action, data);
	if (action == LOCK)
		sefty_mutx(pthread_mutex_lock(mutex), action, data);
	if (action == UNLOCK)
		sefty_mutx(pthread_mutex_unlock(mutex), action, data);
}

static	int	syfty_thread(int result, t_operation action, t_data *data)
{
	if (result != 0)
	{
		if (data)
			set_bool(&data->data_mutx, &data->the_end, true, data);
		if (action == CREATE)
			error_detector("pthread_create failed\n", 1, data);
		if (action == JOIN)
			error_detector("pthread_join failed\n", 1, data);
		if (action == DETACH)
			error_detector("pthread_detach failed\n", 1, data);
	}
	return (0);
}

void	operation_thread(pthread_t *thread, void *(*routine)(void *),
			void *data, t_operation action)
{
	t_data	*thread_data;

	thread_data = (t_data *)data;
	if (action == CREATE)
		syfty_thread(pthread_create(thread, NULL, routine, data),
			action, thread_data);
	if (action == JOIN)
		syfty_thread(pthread_join(*thread, NULL), action, thread_data);
	if (action == DETACH)
		syfty_thread(pthread_detach(*thread), action, thread_data);
}
