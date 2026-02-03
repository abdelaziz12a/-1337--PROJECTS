/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 23:20:06 by aaboudra          #+#    #+#             */
/*   Updated: 2025/03/04 09:18:58 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int nb)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->num = nb;
	new->next = NULL;
	return (new);
}

void	into_stack(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (!*stack)
		*stack = new;
	else
	{
		temp = *stack;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = new;
	}
}

void	init_stack(char **str, t_stack **a, int size)
{
	long	nb;
	int		i;
	char	*st;
	char	**sp;

	i = 0;
	st = ft_strjoin(str, size);
	sp = ft_split(st, ' ');
	free(st);
	while (sp[i])
	{
		nb = ft_atoi(sp[i], sp, a);
		if ((nb > INT_MAX || nb < INT_MIN))
			error_detect(a, sp);
		if (error_repetition(a, (int)nb))
			error_detect(a, sp);
		into_stack(a, new_node((int)nb));
		i++;
	}
	free_st(sp);
}
