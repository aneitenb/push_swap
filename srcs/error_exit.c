/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:27:13 by aneitenb          #+#    #+#             */
/*   Updated: 2024/02/05 12:58:59 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(int status)
{
	write(2, "Error\n", 6);
	status = 0;
	exit(1);
}

void	error_exit_free(t_stack *stack)
{
	t_stack	*temp;

	temp = NULL;
	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	free (stack);
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = NULL;
		stack = temp;
	}
}

void	free_array(char **input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		free(input[i]);
		i++;
	}
	free (input);
}

void	free_array_exit(char **input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		free(input[i]);
		i++;
	}
	free (input);
	write(2, "Error\n", 6);
	exit(1);
}
