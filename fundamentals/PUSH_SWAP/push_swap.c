/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:51:04 by aaboudra          #+#    #+#             */
/*   Updated: 2025/03/04 09:12:08 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	secend_sort(t_stack	**stacka, t_stack	**stackb)
{
	int		max_pos;
	int		size;
	t_stack	*max_node;

	while (*stackb)
	{
		max_node = finde_highest(*stackb);
		max_pos = get_position(*stackb, max_node);
		size = args_len(stackb);
		if (max_pos <= size / 2)
		{
			while (*stackb != max_node)
				rotate(stackb, 'b');
		}
		else
		{
			while (*stackb != max_node)
				r_rotate(stackb, 'b');
		}
		push(stacka, stackb, 'a');
	}
}

void	first_sort(t_stack **stacka, t_stack **stackb, int range)
{
	int	ind;

	ind = 0;
	while (*stacka)
	{
		if ((*stacka)->index <= ind)
		{
			push(stackb, stacka, 'b');
			ind++;
		}
		else if ((*stacka)->index <= range + ind)
		{
			push(stackb, stacka, 'b');
			rotate(stackb, 'b');
			ind++;
		}
		else
			rotate(stacka, 'a');
	}
}

void	sort_index(t_stack	**stack)
{
	int		index;
	int		min_value;
	t_stack	*tmp;
	t_stack	*min_node;

	index = 0;
	while (1)
	{
		tmp = *stack;
		min_node = NULL;
		min_value = INT_MAX;
		while (tmp)
		{
			if (tmp->index == -1 && tmp->num < min_value)
			{
				min_value = tmp->num;
				min_node = tmp;
			}
			tmp = tmp->next;
		}
		if (!min_node)
			break ;
		min_node->index = index++;
	}
}

void	give_index(t_stack	**stacka)
{
	t_stack	*stack;

	stack = *stacka;
	while (stack)
	{
		stack->index = -1;
		stack = stack->next;
	}
}

void	push_swap(t_stack	**a, t_stack	**b)
{
	int	range;

	give_index(a);
	sort_index(a);
	if (args_len(a) <= 100)
		range = 11;
	else
		range = 35;
	first_sort(a, b, range);
	secend_sort(a, b);
}
