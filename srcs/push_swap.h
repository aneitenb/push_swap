/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:12:33 by aneitenb          #+#    #+#             */
/*   Updated: 2024/01/29 17:38:03 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include ".././libft/libft.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				data;
	int				order;
	struct s_stack	*next;
}	t_stack;

t_stack	*make_stack(t_stack *stack_a, char **array);
char	**ft_split(char const *s, char c);
void	check_input(int count, char **input);
t_stack	*final_check(t_stack *stack);
void	error_exit(int status);
void	error_exit_free(t_stack *stack);
int		stack_ordered(t_stack *stack);
t_stack	*sort_stack(t_stack *stack_a);
int		stack_length(t_stack *stack);
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		max_order(t_stack *stack);
int		min_order(t_stack *stack);
t_stack	*get_last_node(t_stack *stack_a);
t_stack	*min_to_top(t_stack *stack);
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
t_stack	*get_last(t_stack **stack);
// void	init_index(t_stack *stack);
// int		target_movetb(t_stack *stack_a, t_stack *stack_b, int index);
// void	apply_rr(t_stack *stack_a, t_stack *stack_b, int index);
// void	apply_rrr(t_stack *stack_a, t_stack *stack_b, int index);
// void	apply_ra_rrb(t_stack *stack_a, t_stack *stack_b, int index);
// void	apply_rra_rb(t_stack *stack_a, t_stack *stack_b, int index);
// void	init_order(t_stack *stack);
// t_stack	*init_min(t_stack **stack);
// void	init_index(t_stack *stack);
// t_stack	*final_check(t_stack *stack);

#endif