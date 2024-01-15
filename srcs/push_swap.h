/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:12:33 by aneitenb          #+#    #+#             */
/*   Updated: 2024/01/15 16:41:43 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include ".././libft/libft.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				data;
	int				index;
	int				push_cost;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

t_stack	*make_stack(t_stack *stack_a, char **array);
char	**ft_split(char const *s, char c);
void	check_input(int count, char **input);
void	error_exit(int status);
int		stack_ordered(t_stack *stack_a);

#endif