/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:18:31 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/15 03:37:17 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

static void	rotate_reverse_impl(t_deque *deque)
{
	int	bottom;

	if (deque_size(deque) < 2)
		return ;
	bottom = deque_pop_front(deque);
	deque_push_back(deque, bottom);
}

// reverse rotate stack a
void	stacks_rra(t_stacks *stacks)
{
	stacks_add_instruction(stacks, INST_RRA);
	rotate_reverse_impl(stacks->a);
}

// reverse rotate stack b
void	stacks_rrb(t_stacks *stacks)
{
	stacks_add_instruction(stacks, INST_RRB);
	rotate_reverse_impl(stacks->b);
}

void	stacks_rrr(t_stacks *stacks)
{
	stacks_add_instruction(stacks, INST_RRR);
	rotate_reverse_impl(stacks->a);
	rotate_reverse_impl(stacks->b);
}
