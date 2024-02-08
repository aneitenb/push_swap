/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:31:59 by aneitenb          #+#    #+#             */
/*   Updated: 2024/02/08 11:52:44 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*sort_final(t_stack *stack_a, t_stack *stack_b)
{
	int	target;

	while (stack_b)
	{
		target = (stack_b->order) + 1;
		if (stack_a->order != target)
		{
			rra(&stack_a);
			pa(&stack_a, &stack_b);
			ra(&stack_a);
			ra(&stack_a);
		}
		else
			pa(&stack_a, &stack_b);
	}
	return (stack_a);
}

t_stack	*sort_radix(t_stack *stack_a, t_stack *stack_b, int max_bits, int i)
{
	int	length;

	while (i < max_bits && stack_ordered(stack_a))
	{
		length = stack_length(stack_a);
		while (length-- > 0 && stack_ordered(stack_a))
		{
			if ((((stack_a->order) >> i) & 1) == 1)
				ra(&stack_a);
			else
				pb(&stack_a, &stack_b);
		}
		i++;
		length = stack_length(stack_b);
		while (length-- > 0)
		{
			if ((((stack_b->order) >> i) & 1) == 1)
				pa(&stack_a, &stack_b);
			else
				rb(&stack_b);
		}
	}
	stack_a = sort_final(stack_a, stack_b);
	return (stack_a);
}

t_stack	*radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	max_bits;
	int	max_num;

	max_bits = 0;
	max_num = stack_length(stack_a) - 1;
	while (max_num >> max_bits != 0)
		max_bits++;
	i = 0;
	stack_a = sort_radix(stack_a, stack_b, max_bits, i);
	return (stack_a);
}
