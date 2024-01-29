/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:27:13 by aneitenb          #+#    #+#             */
/*   Updated: 2024/01/17 10:42:49 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(int status)
{
	ft_printf("Error\n");
	status = 0;
	exit(0);
}

void	error_exit_free(t_stack *stack)
{
	if (stack)
		free (stack);
	ft_printf("Error\n");
	exit(0);
}
