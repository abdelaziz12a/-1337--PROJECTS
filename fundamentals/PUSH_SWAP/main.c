/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:43:26 by aaboudra          #+#    #+#             */
/*   Updated: 2025/03/04 09:18:47 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	args_len(t_stack **stack)
{
	int			ct;
	t_stack		*p;

	p = *stack;
	ct = 0;
	while (p)
	{
		ct += 1;
		p = (p)-> next;
	}
	return (ct);
}

void	shorts_sort(t_stack	**sa, t_stack	**sb)
{
	if (args_len(sa) == 2)
		swap(sa, 'a');
	else if (args_len(sa) == 3)
		sort_three(sa);
	else
		sort_five(sa, sb);
}

int	sorted(t_stack	**stack)
{
	t_stack	*p;

	p = *stack;
	while (p->next)
	{
		if (p->num > p->next->num)
			return (0);
		p = p->next;
	}
	return (1);
}

void	is_emty(int ac, char	**av)
{
	int	i;
	int	j;

	i = 1;
	while (i <= ac - 1)
	{
		j = 0;
		while (av[i][j] == ' ' || (av[i][j] >= 9 && av[i][j] <= 13))
			j++;
		if (av[i][j] == '\0')
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

int	main(int ac, char	**av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	is_emty(ac, av);
	init_stack(av + 1, &a, ac -1);
	if (!sorted(&a))
	{
		if (args_len(&a) == 2 || args_len(&a) == 3 || args_len(&a) == 5)
			shorts_sort(&a, &b);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
}
