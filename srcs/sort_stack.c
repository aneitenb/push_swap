/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:46:31 by aneitenb          #+#    #+#             */
/*   Updated: 2024/01/29 17:58:05 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*sort_three(t_stack *stack)
{
	int	first;
	int	mid;
	int	last;
	
	first = stack->data;
	mid = stack->next->data;
	last = (get_last_node(stack))->data;
	if (first < mid && first < last && mid > last)
	{
		sa(&stack);
		ra(&stack);
	}
	else if (first > mid && first < last && mid < last)
		sa(&stack);
	else if (first < mid && first > last && mid > last)
		rra(&stack);
	else if (first > mid && first > last && mid < last)
		ra(&stack);
	else if (first > mid && first > last && mid > last)
	{
		sa(&stack);
		rra(&stack);
	}
	return (stack);
}
t_stack	*sort_small(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_length(stack_a) == 4)
	{
		stack_a = min_to_top(stack_a);
		pb(&stack_a, &stack_b);
		stack_a = sort_three(stack_a);
		pa(&stack_a, &stack_b);
	}
	if (stack_length(stack_a) == 5)
	{
		stack_a = min_to_top(stack_a);
		pb(&stack_a, &stack_b);
		stack_a = min_to_top(stack_a);
		pb(&stack_a, &stack_b);
		stack_a = sort_three(stack_a);
		pa(&stack_a, &stack_b);
		pa(&stack_a, &stack_b);
	}
	return (stack_a);
}

t_stack	*radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	max_num;
	int	max_bits;
	int	i;

	max_num = stack_length(stack_a) - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	i = 0;
	while ((i < max_bits) && stack_a)
	{
		if ((((stack_a->order)>>i)&1) == 1)
			ra(&stack_a);
		else
			pb(&stack_a, &stack_b);
			i++;
	}
	while (stack_b)
		pa(&stack_a, &stack_b);
	return (stack_a);
	}

t_stack	*sort_stack(t_stack *stack_a)
{
	t_stack	*stack_b;
	int	i;

	i = 0;
	stack_b = NULL;
	if (stack_length(stack_a) == 2)
		sa(&stack_a);
	if (stack_length(stack_a) == 3)
		stack_a = sort_three(stack_a);
	if (stack_length(stack_a) == 4 || stack_length(stack_a) == 5)
		stack_a = sort_small(stack_a, stack_b);
	// if (stack_length(stack_a) > 5 )
	// 	stack_a = radix_sort(stack_a, stack_b);
	return (stack_a);
}
	