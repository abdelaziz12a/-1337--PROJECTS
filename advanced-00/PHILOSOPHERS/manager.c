/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:37:08 by aaboudra          #+#    #+#             */
/*   Updated: 2025/08/24 19:13:17 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	bool	all_philos_are_full(t_data *data)
{
	int	i;
	int	full_philos_count;

	if (data->nbr_limte_meals == -1)
		return (false);
	i = 0;
	full_philos_count = 0;
	while (i < data->nbr_philos)
	{
		if (get_bool(&data->philos[i].philo_mutx,
				&data->philos[i].is_full, data))
			full_philos_count++;
		i++;
	}
	return (full_philos_count == data->nbr_philos);
}

static	bool	philo_dead(t_philo *philo)
{
	long	time;
	bool	is_dead;
	long	last_meal;

	is_dead = false;
	if (get_bool(&philo->philo_mutx, &philo->is_full, philo->data))
		return (false);
	last_meal = get_long(&philo->philo_mutx,
			&philo->time_last_meal, philo->data);
	time = get_time(MILLISECOND) - last_meal;
	if (time > philo->data->time_to_die)
		is_dead = true;
	return (is_dead);
}

static	bool	all_philos_raning(pthread_mutex_t *mutx, long *nbr_are_runing,
			long nbr_of_philos, t_data *data)
{
	bool	ret;

	ret = false;
	operation_mutex(mutx, LOCK, data);
	if (*nbr_are_runing == nbr_of_philos)
		ret = true;
	operation_mutex(mutx, UNLOCK, data);
	return (ret);
}

static	int	check_fi_is_full(t_data *data)
{
	if (all_philos_are_full(data))
	{
		set_bool(&data->data_mutx, &data->the_end, true, data);
		return (1);
	}
	return (0);
}

void	*manger_works(void *arg)
{
	int		i;
	t_data	*data;

	data = (t_data *)arg;
	while (!all_philos_raning(&data->data_mutx, &data->philos_runing,
			data->nbr_philos, data))
		continue ;
	while (!get_bool(&data->data_mutx, &data->the_end, data))
	{
		i = 0;
		while (i < data->nbr_philos && !get_bool(&data->data_mutx,
				&data->the_end, data))
		{
			if (philo_dead(data->philos + i))
			{
				set_bool(&data->data_mutx, &data->the_end, true, data);
				write_status(DEAD, data->philos + i);
			}
			i++;
		}
		if (check_fi_is_full(data))
			break ;
	}
	return (NULL);
}
