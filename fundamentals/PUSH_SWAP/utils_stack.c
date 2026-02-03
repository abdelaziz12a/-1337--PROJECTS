/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 23:20:22 by aaboudra          #+#    #+#             */
/*   Updated: 2025/03/05 15:41:02 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	error_syntax(char	*str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

long	ft_atoi(char	*str_nb, char **str, t_stack **a)
{
	int		i;
	int		seg;
	long	res;

	i = 0;
	seg = 1;
	res = 0;
	if (error_syntax(str_nb))
		error_detect(a, str);
	while (str_nb[i] == ' ' || (str_nb[i] >= 9 && str_nb[i] <= 13))
		i++;
	if (str_nb[i] == '-' || str_nb[i] == '+')
	{
		if (str_nb[i] == '-')
			seg *= -1;
		i++;
	}
	while (str_nb[i] >= '0' && str_nb[i] <= '9')
	{
		res = (res * 10) + (str_nb[i] - '0');
		i++;
	}
	return (res * seg);
}

char	*ft_strcat(char *dest, char *src)
{
	int		c;
	int		d;

	c = 0;
	d = 0;
	while (dest[c] != '\0')
		c++;
	while (src[d] != '\0')
	{
		dest[c] = src[d];
		c++;
		d++;
	}
	dest[c] = '\0';
	return (dest);
}

char	*ft_strjoin(char **st, int count)
{
	int		i;
	int		total_lenth;
	char	*new;

	total_lenth = 0;
	i = 0;
	while (i < count)
	{
		total_lenth += ft_strlen(st[i]);
		if (i < count - 1)
			total_lenth += 1;
		i++;
	}
	new = malloc(sizeof(char) * total_lenth + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < count)
	{
		ft_strcat(new, st[i]);
		if (i < count - 1)
			ft_strcat(new, " ");
		i++;
	}
	return (new);
}
