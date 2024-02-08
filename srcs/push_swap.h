/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:12:33 by aneitenb          #+#    #+#             */
/*   Updated: 2024/02/02 18:51:46 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include ".././libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				data;
	int				order;
	struct s_stack	*next;
}	t_stack;

t_stack	*make_stack(t_stack *stack_a, char **array);
void	check_input(int count, char **input);
void	error_exit(int status);
void	error_exit_free(t_stack *stack);
void	ft_free_stack(t_stack *stack);
void	free_array(char **input);
void	free_array_exit(char **input);
int		stack_ordered(t_stack *stack);
t_stack	*sort_stack(t_stack *stack_a);
int		stack_length(t_stack *stack);
t_stack	*get_last(t_stack **stack);
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
t_stack	*radix_sort(t_stack *stack_a, t_stack *stack_b);

#endif