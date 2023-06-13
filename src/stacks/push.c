/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:18:26 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/13 15:18:27 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stacks.h"
#include <unistd.h>

// push the top of stack b to stack a
void	stacks_pa(t_stacks *stacks)
{
	ft_putstr_fd("pa\n", STDOUT_FILENO);
	if (stacks->b->is_empty)
		return ;
	deque_push_back(stacks->a, deque_pop_back(stacks->b));
}

// push the top of stack a to stack b
void	stacks_pb(t_stacks *stacks)
{
	ft_putstr_fd("pb\n", STDOUT_FILENO);
	if (stacks->a->is_empty)
		return ;
	deque_push_back(stacks->b, deque_pop_back(stacks->a));
}
