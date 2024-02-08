/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:31:43 by aneitenb          #+#    #+#             */
/*   Updated: 2024/02/02 15:17:10 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_last_node(t_stack *stack_a)
{
	while (stack_a->next)
		stack_a = stack_a->next;
	return (stack_a);
}

t_stack	*add_at_end(t_stack *stack_a, int data)
{
	t_stack	*temp;
	t_stack	*last_node;

	temp = malloc(sizeof(t_stack));
	if (!temp)
		error_exit_free(stack_a);
	temp->data = data;
	temp->next = NULL;
	temp->order = -1;
	if (!stack_a)
		stack_a = temp;
	else
	{
		last_node = get_last_node(stack_a);
		last_node->next = temp;
	}
	return (stack_a);
}

t_stack	*init_min(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*min;
	int		flag;

	temp = *stack;
	flag = 0;
	while (temp)
	{
		if (temp->order == -1 && (flag == 0 || min->data > temp->data))
		{
			min = temp;
			flag = 1;
		}
		temp = temp->next;
	}
	return (min);
}

void	init_order(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*min;
	int		index;
	int		length;

	temp = stack;
	length = stack_length(stack);
	index = 0;
	while (temp && index < length)
	{
		min = init_min(&temp);
		min->order = index;
		index++;
	}
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
	init_order(stack_a);
	return (stack_a);
}
