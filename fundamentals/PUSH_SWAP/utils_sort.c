/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 23:47:45 by aaboudra          #+#    #+#             */
/*   Updated: 2025/03/05 15:23:41 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_stack	*finde_highest(t_stack *st)
{
	t_stack	*tmp;
	int		highest;
	t_stack	*highest_node;

	highest_node = NULL;
	tmp = st;
	highest = INT_MIN;
	while (tmp)
	{
		if (tmp->num > highest)
		{
			highest = tmp->num;
			highest_node = tmp;
		}
		tmp = tmp->next;
	}
	return (highest_node);
}

void	sort_three(t_stack **stack)
{
	t_stack	*highest_node;

	highest_node = finde_highest(*stack);
	if (*stack == highest_node)
		rotate(stack, 'a');
	else if ((*stack)->next == highest_node)
		r_rotate(stack, 'a');
	if ((*stack)->num > (*stack)->next->num)
		swap(stack, 'a');
}

int	get_index(t_stack *stack, int value)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack->num == value)
			return (index);
		stack = stack->next;
		index++;
	}
	return (0);
}

t_stack	*finde_min(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*min;

	tmp = *stack;
	min = *stack;
	while (tmp)
	{
		if (tmp->num < min->num)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

void	sort_five(t_stack **stacka, t_stack **stackb)
{
	int		i;
	t_stack	*min;

	i = 0;
	while (i < 2)
	{
		min = finde_min(stacka);
		while (*stacka != min)
		{
			if (get_index(*stacka, min->num) <= 2)
				rotate(stacka, 'a');
			else
				r_rotate(stacka, 'a');
		}
		push(stackb, stacka, 'b');
		i++;
	}
	sort_three(stacka);
	push(stacka, stackb, 'a');
	push(stacka, stackb, 'a');
}
