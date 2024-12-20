/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:07:38 by aneitenb          #+#    #+#             */
/*   Updated: 2024/02/01 13:07:10 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	first = *stack;
	second = (*stack)->next;
	last = get_last(stack);
	last->next = first;
	first->next = NULL;
	*stack = second;
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (stack_length(*stack) == 1)
		return ;
	if (stack_length(*stack) == 2)
	{
		first = *stack;
		*stack = (*stack)->next;
		last = get_last(stack);
		last->next = first;
		first->next = NULL;
		*stack = last;
		write(1, "rb\n", 3);
		return ;
	}
	first = *stack;
	second = (*stack)->next;
	last = get_last(stack);
	last->next = first;
	first->next = NULL;
	*stack = second;
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
}
