/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:31:43 by aneitenb          #+#    #+#             */
/*   Updated: 2024/01/12 13:58:51 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_last_node(t_stack *a)
{
	while (a->next)
		a = a->next;
	return(a);
}

t_stack	*add_at_end(t_stack *a, int data)
{
	t_stack	*temp;
	t_stack	*prev_node;
	
	temp = malloc(sizeof(t_stack));
	if (!temp)
		exit(0); //error_exit? do I need to free anything?
	temp->data = data;
	temp->next = NULL;
	if (!a)
	{
		a  = temp;
		temp->previous = NULL;
	}
	else
	{
		prev_node = get_last_node(a);
		prev_node->next = temp;
		temp->next = NULL;
	}
	return(a);
}

t_stack	*make_stack(t_stack *a, char **array)
{
	int	data;
	
	// add check for non-number characters, overflow, or repeats
	while (*array)
	{
		 data = ft_atol(*array);
		 a = add_at_end(a, data);
		 array++;
	}
	return(a);
}
