/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:29:01 by aaboudra          #+#    #+#             */
/*   Updated: 2025/03/03 18:09:18 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, char c)
{
	int	tmp;

	tmp = (*stack)->num;
	(*stack)->num = (*stack)->next->num;
	(*stack)->next->num = tmp;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	ss(t_stack	**stacka, t_stack	**stackb)
{
	swap(stacka, 'g');
	swap(stackb, 'g');
	write(1, "ss\n", 3);
}

void	rotate(t_stack	**stack, char c)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = tmp;
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	rr(t_stack	**stacka, t_stack	**stackb)
{
	rotate(stacka, 'g');
	rotate(stackb, 'g');
	write(1, "rr\n", 3);
}
