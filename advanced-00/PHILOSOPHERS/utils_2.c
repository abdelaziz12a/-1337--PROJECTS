/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:24:17 by aaboudra          #+#    #+#             */
/*   Updated: 2025/08/24 19:44:43 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_status status, long time, t_philo *philo)
{
	if (status == TIKE_FERST_FORK || status == TIKE_SECEND_FORK)
		printf("%-6ld %d has taken a fork\n", time, philo->philo_id);
	else if (status == EATING)
		printf("%-6ld %d is eating\n", time, philo->philo_id);
	else if (status == THINKING)
		printf("%-6ld %d is thinking\n", time, philo->philo_id);
	else if (status == SLEEPING)
		printf("%-6ld %d is sleeping\n", time, philo->philo_id);
	else if (status == DEAD)
		printf("%-6ld %d died\n", time, philo->philo_id);
}

void	usleep_help(long start, long usec)
{
	long	curent;

	while (1)
	{
		curent = get_time(MICROSECOND);
		if (curent == -1 || curent - start >= usec)
			break ;
	}
}

int	check_sign(const char **str, t_data *data)
{
	if (**str == '+')
		(*str)++;
	else if (**str == '-')
		return (error_detector("please enter a positive number", 0, data));
	return (0);
}

int	check_spaces_and_digits(const char *str, t_data *data)
{
	while (*str)
	{
		if (is_space(*str))
		{
			while (is_space(*str))
				str++;
			if (*str != '\0')
				return (error_detector("spaces are not allowed", 0, data));
		}
		else if (!ft_isdigit(*str))
			return (error_detector("please enter only digits", 0, data));
		else
			str++;
	}
	return (0);
}
