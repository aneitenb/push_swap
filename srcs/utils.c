/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:30:56 by aneitenb          #+#    #+#             */
/*   Updated: 2024/01/29 17:41:02 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_length(t_stack *stack)
{
	int	length;

	length = 0;
	while (stack)
	{
		length++;
		stack = stack->next;
	}
	return (length);
}

int	min_order(t_stack *stack)
{
	t_stack	*temp;
	int		min;

	temp = stack;
	min = temp->order;
	while (temp)
	{
		if (min > temp->order)
			min = temp->order;
		temp = temp->next;
	}
	return (min);
}

int	max_order(t_stack *stack)
{
	t_stack	*temp;
	int		max;

	temp = stack;
	max = stack->order;
	while (temp)
	{
		if (max < temp->order)
			max = temp->order;
		temp = temp->next;
	}
	return (max);
}

int	find_min(t_stack *stack)
{
	t_stack	*temp;
	int	min;

	temp = stack;
	min = stack->data;
	while (stack)
	{
		if (min > stack->data)
			min = stack->data;
		stack = stack->next;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	int	max;

	max = stack->data;
	while (stack)
	{
		if (max < stack->data)
			max = stack->data;
		stack = stack->next;
	}
	return (max);
}

t_stack	*get_last(t_stack **stack)
{
	while ((*stack)->next)
		*stack = (*stack)->next;
	return (*stack);
}

int	find_index(t_stack *stack, int number)
{
	int	i;

	i = 0;
	while(stack->order != number)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

t_stack	*min_to_top(t_stack *stack)
{
	int	i;

	if (!stack_ordered(stack))
		return (stack);
	i = find_index(stack, min_order(stack));
	if (i <= (stack_length(stack) / 2))
	{
		while(stack->order != min_order(stack))
			ra(&stack);
	}
	else
	{
		while(stack->order != min_order(stack))
			rra(&stack);
	}
	return (stack);
}