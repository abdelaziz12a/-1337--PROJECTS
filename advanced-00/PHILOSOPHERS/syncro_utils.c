/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syncro_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 15:56:13 by aaboudra          #+#    #+#             */
/*   Updated: 2025/08/20 20:25:40 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	syncro_runing_philos(pthread_mutex_t *mtx, long *dest, t_data *data)
{
	operation_mutex(mtx, LOCK, data);
	(*dest)++;
	operation_mutex(mtx, UNLOCK, data);
}

void	set_bool(pthread_mutex_t	*mtx, bool *dest, bool value, t_data *data)
{
	operation_mutex(mtx, LOCK, data);
	*dest = value;
	operation_mutex(mtx, UNLOCK, data);
}

bool	get_bool(pthread_mutex_t	*mtx, bool *value, t_data *data)
{
	bool	ret;

	operation_mutex(mtx, LOCK, data);
	ret = *value;
	operation_mutex(mtx, UNLOCK, data);
	return (ret);
}

void	set_long(pthread_mutex_t	*mtx, long *dest, long value, t_data *data)
{
	operation_mutex(mtx, LOCK, data);
	*dest = value;
	operation_mutex(mtx, UNLOCK, data);
}

long	get_long(pthread_mutex_t	*mtx, long *value, t_data *data)
{
	long	ret;

	operation_mutex(mtx, LOCK, data);
	ret = *value;
	operation_mutex(mtx, UNLOCK, data);
	return (ret);
}
