/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:25:41 by aneitenb          #+#    #+#             */
/*   Updated: 2024/01/29 16:20:20 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack *third;
	
	first = *stack;
	second = (*stack)->next;
	third = second->next;
	*stack = second;
	(*stack)->next = first;
	first->next = third;
	write (1, "sa\n", 3);
}

void	sb(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack *third;
	
	first = *stack;
	second = (*stack)->next;
	third = second->next;
	*stack = second;
	(*stack)->next = first;
	first->next = third;
	write (1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b) 
{
	sa(&stack_a);
	sb(&stack_b);
	write (1, "ss\n", 3);
}