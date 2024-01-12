/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:48:51 by aneitenb          #+#    #+#             */
/*   Updated: 2024/01/12 15:13:17 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	
	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (printf("Error\n")); 
	check_input(argc, argv + 1); //add checks for everything beforehand, void for exit
	if (argc == 2)
		a = make_stack(a, ft_split(argv[1], ' '));
	if (argc > 2)
		a = make_stack(a, argv + 1);
	while (a)
	{
		printf("%d\n", a->data);
		a = a->next;
	}
}
