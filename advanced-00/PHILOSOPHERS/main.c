/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 23:34:24 by aaboudra          #+#    #+#             */
/*   Updated: 2025/08/20 19:42:23 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		if (parce_input(av, &data) != 0)
			return (1);
		if (init_data(&data) != 0)
			return (1);
		start_simulation(&data);
		clean_data(&data);
		return (0);
	}
	error_detector("number of args not 5 or 6", 0, &data);
	return (1);
}
