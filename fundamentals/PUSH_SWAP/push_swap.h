/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 23:20:15 by aaboudra          #+#    #+#             */
/*   Updated: 2025/03/05 15:24:56 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct node
{
	int			num;
	int			index;
	struct node	*next;
}	t_stack;

char	**ft_split(char	const *s, char c);
void	init_stack(char **str, t_stack **a, int size);
char	*ft_strjoin(char **st, int count);
char	*ft_strcat(char *dest, char *src);
long	ft_atoi(char *str_nb, char **str, t_stack **a);
int		error_syntax(char *str);
int		ft_strlen(char *str);
void	into_stack(t_stack **stack, t_stack *new);
t_stack	*new_node(int nb);
int		error_repetition(t_stack **a, int nb);
void	error_detect(t_stack **a, char **st);
void	free_stack(t_stack **stack);
void	free_st(char **str);

int		args_len(t_stack **stack);
int		sorted(t_stack **stack);

void	swap(t_stack **stack, char c);
void	ss(t_stack **stacka, t_stack **stackb);
void	push(t_stack	**dest, t_stack **src, char c);
void	rotate(t_stack	**stack, char c);
void	rr(t_stack **stacka, t_stack **stackb);
void	r_rotate(t_stack	**stack, char c);
void	rrr(t_stack **stacka, t_stack **stackb);

void	sort_three(t_stack **stack);
t_stack	*finde_highest(t_stack *st);
void	sort_five(t_stack **stacka, t_stack **stackb);
t_stack	*finde_min(t_stack **stack);
int		get_index(t_stack *stack, int value);

void	give_index(t_stack **stack);
void	push_swap(t_stack	**a, t_stack	**b);
void	sort_index(t_stack **stack);
void	first_sort(t_stack **stacka, t_stack **satckb, int range);

void	secend_sort(t_stack	**stacka, t_stack	**stackb);
int		get_position(t_stack *stack, t_stack *target);

#endif
