/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 19:28:44 by aaboudra          #+#    #+#             */
/*   Updated: 2025/08/27 21:29:39 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_space(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	validation_number(const char *str, t_data *data,
			const char **result)
{
	const char	*s;

	while (is_space(*str))
		str++;
	if (check_sign(&str, data))
		return (1);
	s = str;
	if (*s == '\0')
		return (error_detector("empty number is not allowed", 0, data));
	return (*result = s, check_spaces_and_digits(s, data));
}

static	int	convert_to_long(const char *str, t_data *data, long *result)
{
	const char	*validated_str;

	*result = 0;
	if (validation_number(str, data, &validated_str) != 0)
		return (1);
	while (*validated_str && ft_isdigit(*validated_str))
	{
		if (*result > (INT_MAX - (*validated_str - '0')) / 10)
			return (error_detector("number is too big INT_MAX is the limit",
					0, data));
		*result = *result * 10 + (*validated_str - '0');
		validated_str++;
	}
	return (0);
}

int	parce_input(char **av, t_data *data)
{
	if (convert_to_long(av[1], data, &data->nbr_philos) != 0)
		return (1);
	if (convert_to_long(av[2], data, &data->time_to_die) != 0)
		return (1);
	if (convert_to_long(av[3], data, &data->time_to_eat) != 0)
		return (1);
	if (convert_to_long(av[4], data, &data->time_to_sleep) != 0)
		return (1);
	if (data->time_to_die < 60
		|| data->time_to_eat < 60
		|| data->time_to_sleep < 60)
		return (error_detector("please enter a valid time (at least 60ms)",
				0, data));
	if (data->nbr_philos == 0)
		return (error_detector("please enter a valid number of philosophers",
				0, data));
	if (av[5])
	{
		if (convert_to_long(av[5], data, &data->nbr_limte_meals) != 0)
			return (1);
	}
	else
		data->nbr_limte_meals = -1;
	return (0);
}
