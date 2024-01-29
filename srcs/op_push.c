/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:29:24 by aneitenb          #+#    #+#             */
/*   Updated: 2024/01/29 17:27:41 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	temp = malloc(sizeof(t_stack));
	if (!temp)
		error_exit_free(*stack_a);
	temp->data = (*stack_b)->data;
	temp->order = (*stack_b)->order;
	temp->next = *stack_a;
	*stack_a = temp;
	*stack_b = (*stack_b)->next;
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	temp = malloc(sizeof(t_stack));
	if (!temp)
		error_exit_free(*stack_a);
	temp->data = (*stack_a)->data;
	temp->order = (*stack_a)->order;
	temp->next = NULL;
	if (!(*stack_b))
		*stack_b = temp;
	else
		temp->next = *stack_b;
	*stack_b = temp;
	*stack_a = (*stack_a)->next;
	write(1, "pb\n", 3);
}
