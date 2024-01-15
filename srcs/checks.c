/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:43:28 by aneitenb          #+#    #+#             */
/*   Updated: 2024/01/15 17:26:00 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_number(const char *str)
{
	int		index;
	long	res;

	index = 0;
	res = 0;
	if (str[index] == '-' || str[index] == '+')
		index++;
	while (str[index] >= '0' && str[index] <= '9')
	{
		res = res * 10 + str[index] - '0';
		index++;
	}
	if (str[index])
		error_exit(0);
	if (res > INT_MAX || res < INT_MIN)
		error_exit(0);
	return (res);
}

void	check_errors(int count, char **input)
{
	int		index;
	int		index_save;
	int		check;
	
	index = 0;
	while (index < count)
	{
		while (input[index])
		{
			check = check_number(input[index]);
			index_save = index;
			while (input[index + 1])
			{
				if (check == check_number(input[index + 1]))
					error_exit(0);
				index++;
			}
			index = index_save;
			index++;
		}
		index++;
	}
}

void	check_input(int count, char **input)
{	
	if (count == 2)
		check_errors(count, ft_split(input[1], ' '));
	else
		check_errors(count, input + 1);
}

int	stack_ordered(t_stack *stack_a)
{
	t_stack	*temp;

	temp = stack_a;
	while (temp->next != NULL)
	{
		if (temp->data > temp->next->data)
			return(1);
		temp = temp->next;
	}
	while (stack_a)
	{
		ft_printf("%d\n", stack_a->data);
		stack_a = stack_a->next;
	}
	return (0);
}
