/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:04:53 by aneitenb          #+#    #+#             */
/*   Updated: 2024/01/29 13:20:42 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second_last;
	t_stack	*last;

	first = *stack;
	second_last = *stack;
	last = *stack;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = first;
	second_last->next = NULL;
	*stack = last;
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second_last;
	t_stack	*last;

	first = *stack;
	second_last = *stack;
	last = *stack;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = first;
	second_last->next = NULL;
	*stack = last;
	write(1, "rrb\n", 4);
}
void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	write(1, "rrr\n", 4);
}