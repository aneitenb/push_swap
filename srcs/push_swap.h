/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:12:33 by aneitenb          #+#    #+#             */
/*   Updated: 2024/01/12 14:21:59 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include ".././libft/libft.h"
# include <stdio.h>
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

t_stack	*make_stack(t_stack *a, char **array);
int		ft_atol(const char *str);
char	**ft_split(char const *s, char c);
//void	error_exit(int e);

#endif