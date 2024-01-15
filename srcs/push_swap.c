/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:48:51 by aneitenb          #+#    #+#             */
/*   Updated: 2024/01/15 16:57:20 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return(0); 
	check_input(argc, argv);
	if (argc == 2)
		stack_a = make_stack(stack_a, ft_split(argv[1], ' '));
	if (argc > 2)
		stack_a = make_stack(stack_a, argv + 1);
	if (!stack_ordered(stack_a))
		return(0);
	write(1, "not ordered", 12);
	return (0);
}
