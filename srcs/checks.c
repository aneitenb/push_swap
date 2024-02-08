/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:43:28 by aneitenb          #+#    #+#             */
/*   Updated: 2024/02/02 18:50:35 by aneitenb         ###   ########.fr       */
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
	if (str[index] == '\0')
		error_exit(1);
	while (str[index] >= '0' && str[index] <= '9')
	{
		res = res * 10 + str[index] - '0';
		index++;
	}
	if (str[index])
		error_exit(1);
	if ((res * sign) > INT_MAX || (res * sign) < INT_MIN)
		error_exit(1);
	return (res * sign);
}

void	check_duplicate(char **input, int index, int flag)
{
	int	check;

	check = check_number(input[index]);
	while (input[index + 1])
	{
		if (check == check_number(input[index + 1]))
		{
			if (flag == 1)
				free_array(input);
			error_exit(1);
		}
		index++;
	}
}

void	check_errors(int count, char **input, int flag)
{
	int		index;
	int		check;

	index = 0;
	if (!input[0])
		free_array_exit(input);
	while (index < count)
	{
		while (input[index])
		{
			check = check_number(input[index]);
			check_duplicate(input, index, flag);
			index++;
		}
		index++;
	}
	if (input[1] == NULL)
	{
		free_array(input);
		exit(0);
	}
	if (flag == 1)
		free_array(input);
}

void	check_input(int count, char **input)
{
	static char	**temp;

	temp = ft_split(input[1], ' ');
	if (count == 2)
		check_errors(count, temp, 1);
	else
		check_errors(count, input + 1, 0);
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
	return (0);
}
