/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:18:33 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/15 06:16:09 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

static void	swap_impl(t_deque *deque)
{
	int	top;
	int	second;

	if (deque_size(deque) < 2)
		return ;
	top = deque_pop_back(deque);
	second = deque_pop_back(deque);
	deque_push_back(deque, top);
	deque_push_back(deque, second);
}

// swap two elements at the top of stack a
void	stacks_sa(t_stacks *stacks)
{
	stacks_add_inst(stacks, INST_SA);
	swap_impl(stacks->a);
}

// swap two elements at the top of stack b
void	stacks_sb(t_stacks *stacks)
{
	stacks_add_inst(stacks, INST_SB);
	swap_impl(stacks->b);
}

void	stacks_ss(t_stacks *stacks)
{
	stacks_add_inst(stacks, INST_SS);
	swap_impl(stacks->a);
	swap_impl(stacks->b);
}
