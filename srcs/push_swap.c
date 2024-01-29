/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:48:51 by aneitenb          #+#    #+#             */
/*   Updated: 2024/01/29 11:36:16 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	check_input(argc, argv);
	if (argc == 2)
		stack_a = make_stack(stack_a, ft_split(argv[1], ' '));
	if (argc > 2)
		stack_a = make_stack(stack_a, argv + 1);
	if (!stack_ordered(stack_a))
		return (0);
	stack_a = sort_stack(stack_a);
	while (stack_a)							//delete when done with checks
	{
		ft_printf("%d |", stack_a->data);
		ft_printf(" %d\n", stack_a->order);
		stack_a = stack_a->next;
	}
	// // ft_printf("stack_b\n");
	// while (stack_b)							//delete when done with checks
	// {
	// 	ft_printf("%d\n", stack_b->data);
	// 	ft_printf(" %d\n", stack_b->index);
	// 	stack_b = stack_b->next;
	// }
	return (0);
}
