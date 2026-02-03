/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 22:04:27 by aaboudra          #+#    #+#             */
/*   Updated: 2025/08/20 21:53:57 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	void	init_philos(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = -1;
	while (++i < data->nbr_philos)
	{
		philo = data->philos + i;
		philo->philo_id = i + 1;
		philo->is_full = false;
		philo->meals_conter = 0;
		philo->data = data;
		operation_mutex(&philo->philo_mutx, INIT, data);
		philo->first_fork = &philo->data->forks[(i + 1)
			% philo->data->nbr_philos];
		philo->secend_fork = &philo->data->forks[i];
		if (philo->philo_id % 2 == 0)
		{
			philo->first_fork = &philo->data->forks[i];
			philo->secend_fork = &philo->data->forks[(i + 1)
				% philo->data->nbr_philos];
		}
	}
}

int	init_data(t_data	*data)
{
	int	i;

	data->the_end = false;
	data->all_philos_ready = false;
	data->philos_runing = 0;
	data->gc_list = NULL;
	data->philos = gc_malloc(sizeof(t_philo) * data->nbr_philos, data);
	if (!data->philos)
		return (1);
	data->forks = gc_malloc(sizeof(t_fork) * data->nbr_philos, data);
	if (!data->forks)
		return (1);
	operation_mutex(&data->data_mutx, INIT, data);
	operation_mutex(&data->for_write, INIT, data);
	i = -1;
	while (++i < data->nbr_philos)
	{
		operation_mutex(&data->forks[i].fork, INIT, data);
	}
	init_philos(data);
	return (0);
}
