/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 14:20:08 by aaboudra          #+#    #+#             */
/*   Updated: 2025/08/24 19:13:56 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	void	thincking(t_philo *philo)
{
	long	time_to_think;

	write_status(THINKING, philo);
	time_to_think = philo->data->time_to_die
		- (get_time(MILLISECOND) - get_long(&philo->philo_mutx,
				&philo->time_last_meal, philo->data))
		- philo->data->time_to_eat;
	if (time_to_think > 0)
		precise_usleep(time_to_think * 500, philo->data);
	else
		precise_usleep(1000, philo->data);
}

static	void	eatinig(t_philo *philo)
{
	operation_mutex(&philo->first_fork->fork, LOCK, philo->data);
	write_status(TIKE_FERST_FORK, philo);
	operation_mutex(&philo->secend_fork->fork, LOCK, philo->data);
	write_status(TIKE_SECEND_FORK, philo);
	set_long(&philo->philo_mutx, &philo->time_last_meal,
		get_time(MILLISECOND), philo->data);
	set_long(&philo->philo_mutx, &philo->meals_conter,
		get_long(&philo->philo_mutx, &philo->meals_conter,
			philo->data) + 1, philo->data);
	write_status(EATING, philo);
	precise_usleep(philo->data->time_to_eat * 1000, philo->data);
	if (philo->data->nbr_limte_meals != -1
		&& get_long(&philo->philo_mutx, &philo->meals_conter,
			philo->data) == philo->data->nbr_limte_meals)
		set_bool(&philo->philo_mutx, &philo->is_full, true, philo->data);
	operation_mutex(&philo->first_fork->fork, UNLOCK, philo->data);
	operation_mutex(&philo->secend_fork->fork, UNLOCK, philo->data);
}

static	void	*simulation(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	white_for_syncronisation(philo->data);
	set_long(&philo->philo_mutx, &philo->time_last_meal,
		get_time(MILLISECOND), philo->data);
	syncro_runing_philos(&philo->data->data_mutx,
		&philo->data->philos_runing, philo->data);
	while (!get_bool(&philo->data->data_mutx,
			&philo->data->the_end, philo->data))
	{
		if (get_bool(&philo->philo_mutx, &philo->is_full, philo->data))
			break ;
		eatinig(philo);
		write_status(SLEEPING, philo);
		precise_usleep(philo->data->time_to_sleep * 1000, philo->data);
		if (get_bool(&philo->data->data_mutx, &philo->data->the_end,
				philo->data))
			break ;
		thincking(philo);
	}
	return (NULL);
}

static	int	cheks(t_data *data)
{
	int	i;

	i = 0;
	if (data->nbr_limte_meals == 0)
		return (1);
	else if (data->nbr_philos == 1)
		operation_thread(&data->philos[0].thread_id,
			simulation_for_one, &data->philos[0], CREATE);
	else
	{
		while (i < data->nbr_philos)
		{
			operation_thread(&data->philos[i].thread_id,
				simulation, &data->philos[i], CREATE);
			i++;
		}
	}
	return (0);
}

void	start_simulation(t_data *data)
{
	int	i;

	if (cheks(data))
		return ;
	operation_thread(&data->manager, manger_works, data, CREATE);
	set_long(&data->data_mutx, &data->start_sum, get_time(MILLISECOND), data);
	set_bool(&data->data_mutx, &data->all_philos_ready, true, data);
	operation_thread(&data->manager, NULL, NULL, JOIN);
	i = 0;
	while (i < data->nbr_philos)
	{
		operation_thread(&data->philos[i].thread_id, NULL, NULL, JOIN);
		i++;
	}
	set_bool(&data->data_mutx, &data->the_end, true, data);
}
