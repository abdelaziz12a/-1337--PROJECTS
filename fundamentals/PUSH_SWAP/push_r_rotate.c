/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_r_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 23:01:54 by aaboudra          #+#    #+#             */
/*   Updated: 2025/03/04 09:17:15 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position(t_stack *stack, t_stack *target)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack == target)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (0);
}

void	push(t_stack	**dest, t_stack	**src, char c)
{
	t_stack	*tmp;

	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
}

void	r_rotate(t_stack	**stack, char c)
{
	t_stack	*prev;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}

void	rrr(t_stack	**stacka, t_stack	**stackb)
{
	r_rotate(stacka, 'g');
	r_rotate(stackb, 'g');
	write(1, "rrr\n", 4);
}
