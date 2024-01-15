/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:31:43 by aneitenb          #+#    #+#             */
/*   Updated: 2024/01/15 16:36:24 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_last_node(t_stack *stack_a)
{
	while (stack_a->next)
		stack_a = stack_a->next;
	return(stack_a);
}

t_stack	*add_at_end(t_stack *stack_a, int data)
{
	t_stack	*temp;
	t_stack	*prev_node;
	
	temp = malloc(sizeof(t_stack));
	if (!temp)
		exit(0); //error_exit_free? do I need to free anything?
	temp->data = data;
	temp->next = NULL;
	if (!stack_a)
	{
		stack_a  = temp;
		temp->previous = NULL;
	}
	else
	{
		prev_node = get_last_node(stack_a);
		prev_node->next = temp;
		temp->next = NULL;
	}
	return(stack_a);
}

t_stack	*make_stack(t_stack *stack_a, char **array)
{
	int	data;
	
	while (*array)
	{
		 data = ft_atoi(*array);
		 stack_a = add_at_end(stack_a, data);
		 array++;
	}
	return(stack_a);
}
