/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:48:51 by aneitenb          #+#    #+#             */
/*   Updated: 2024/02/02 13:24:09 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;

	i = 1;
	stack_a = NULL;
	if (argc == 1)
		return (1);
	if (argc > 1)
	{
		while (!argv[i++][0])
			error_exit(1);
	}
	check_input(argc, argv);
	if (argc == 2)
		stack_a = make_stack(stack_a, ft_split(argv[1], ' '));
	if (argc > 2)
		stack_a = make_stack(stack_a, argv + 1);
	if (!stack_ordered(stack_a))
	{
		ft_free_stack(stack_a);
		return (0);
	}
	stack_a = sort_stack(stack_a);
	ft_free_stack(stack_a);
	return (0);
}
