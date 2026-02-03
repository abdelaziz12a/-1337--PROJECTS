/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 23:19:46 by aaboudra          #+#    #+#             */
/*   Updated: 2025/03/03 18:02:32 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_st(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (NULL == stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	error_detect(t_stack **a, char **st)
{
	free_stack(a);
	free_st(st);
	write(2, "Error\n", 6);
	exit(1);
}

int	error_repetition(t_stack **a, int nb)
{
	t_stack	*tmp;

	if (NULL == a)
		return (0);
	tmp = *a;
	while (tmp)
	{
		if (tmp->num == nb)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
