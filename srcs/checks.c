/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:43:28 by aneitenb          #+#    #+#             */
/*   Updated: 2024/01/29 17:38:12 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_number(const char *str)
{
	int		index;
	int		sign;
	long	res;

	index = 0;
	sign = 1;
	res = 0;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign *= -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		res = res * 10 + str[index] - '0';
		index++;
	}
	if (str[index])
		error_exit(0);
	if (res > INT_MAX || res < INT_MIN)
		error_exit(0);
	return (res * sign);
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

int	stack_ordered(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next != NULL)
	{
		if (temp->data > temp->next->data)
			return (1);
		temp = temp->next;
	}
	while (stack)						//delete when done with project
	{
		ft_printf("%d\n", stack->data);
		stack = stack->next;
	}
	return (0);
}

// t_stack	*final_check(t_stack *stack)
// {
// 	int	i;

// 	if (!stack_ordered(stack))
// 		return (stack);
// 	i = find_index(stack, min_order(stack));
// 	if (i < stack_length(stack) -  i)
// 	{
// 		while(stack->order != min_order(stack))
// 			ra(&stack);
// 	}
// 	else
// 	{
// 		while(stack->order != min_order(stack))
// 			rra(&stack);
// 	}
// 	return (stack);
// }
