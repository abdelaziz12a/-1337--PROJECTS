/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_manage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 18:52:44 by aaboudra          #+#    #+#             */
/*   Updated: 2025/08/20 19:53:22 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_data(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < data->nbr_philos)
	{
		philo = data->philos + i;
		operation_mutex(&philo->philo_mutx, DESTROY, data);
		i++;
	}
	i = 0;
	while (i < data->nbr_philos)
	{
		operation_mutex(&data->forks[i].fork, DESTROY, data);
		i++;
	}
	operation_mutex(&data->data_mutx, DESTROY, data);
	operation_mutex(&data->for_write, DESTROY, data);
	free_all(data);
}

void	free_all(t_data *data)
{
	t_gc_node	*node;

	while (data->gc_list)
	{
		node = data->gc_list;
		data->gc_list = data->gc_list->next;
		free(node->ptr);
		free(node);
	}
}

void	*gc_malloc(size_t size, t_data *data)
{
	void		*ptr;
	t_gc_node	*node;

	ptr = malloc(size);
	if (!ptr)
	{
		error_detector("malloc failed", 1, data);
		return (NULL);
	}
	node = malloc(sizeof(t_gc_node));
	if (!node)
	{
		free(ptr);
		error_detector("malloc failed", 1, data);
		return (NULL);
	}
	node->ptr = ptr;
	node->next = data->gc_list;
	data->gc_list = node;
	return (ptr);
}
