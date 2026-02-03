/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:06:51 by aaboudra          #+#    #+#             */
/*   Updated: 2024/11/21 21:35:17 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(int sg)
{
	if (sg > 0)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int					seg;
	unsigned long long	res;

	seg = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
	{
		str++;
	}
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			seg = (-1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (res > ((unsigned long long)((9223372036854775807
					- (*str - 48)) / 10)))
			return (check(seg));
		res = (res * 10) + *str - 48;
		str++;
	}
	return (res * seg);
}
