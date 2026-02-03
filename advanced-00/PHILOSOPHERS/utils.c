/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:01:27 by aaboudra          #+#    #+#             */
/*   Updated: 2025/08/27 22:55:35 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*simulation_for_one(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	white_for_syncronisation(philo->data);
	set_long(&philo->philo_mutx, &philo->time_last_meal,
		get_time(MILLISECOND), philo->data);
	syncro_runing_philos(&philo->data->data_mutx,
		&philo->data->philos_runing, philo->data);
	write_status(TIKE_FERST_FORK, philo);
	precise_usleep(philo->data->time_to_die * 1000, philo->data);
	return (NULL);
}

void	precise_usleep(long usec, t_data *data)
{
	long	start;
	long	elapsed;
	long	rem;
	long	current_time;

	start = get_time(MICROSECOND);
	if (start == -1)
		return ;
	while (1)
	{
		current_time = get_time(MICROSECOND);
		if (current_time == -1 || (current_time - start) >= usec)
			break ;
		if (get_bool(&data->data_mutx, &data->the_end, data))
			break ;
		elapsed = current_time - start;
		rem = usec - elapsed;
		if (rem > 100)
			usleep(rem / 2);
		else
		{
			usleep_help(start, usec);
			break ;
		}
	}
}

void	write_status(t_status status, t_philo *philo)
{
	long	time;
	long	current_time;

	operation_mutex(&philo->data->for_write, LOCK, philo->data);
	current_time = get_time(MILLISECOND);
	if (current_time != -1)
	{
		time = current_time - get_long(&philo->data->data_mutx,
				&philo->data->start_sum, philo->data);
		if (status == DEAD || !get_bool(&philo->data->data_mutx,
				&philo->data->the_end, philo->data))
			print_status(status, time, philo);
	}
	operation_mutex(&philo->data->for_write, UNLOCK, philo->data);
}

long	get_time(t_time tm)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
	{
		error_detector("gettimeofday() failed", 0, NULL);
		return (-1);
	}
	if (tm == MICROSECOND)
		return ((time.tv_sec * 1000000) + time.tv_usec);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	error_detector(char *str, int check, t_data *data)
{
	printf("error: ");
	printf("%s\n", str);
	if (check == 1 && data)
	{
		set_bool(&data->data_mutx, &data->the_end, true, data);
		free_all(data);
	}
	return (1);
}
