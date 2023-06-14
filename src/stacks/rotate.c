/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:18:28 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/15 06:16:23 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

static void	rotate_impl(t_deque *deque)
{
	int	top;

	if (deque_size(deque) < 2)
		return ;
	top = deque_pop_back(deque);
	deque_push_front(deque, top);
}

// rotate stack a (the first element becomes the last one)
void	stacks_ra(t_stacks *stacks)
{
	stacks_add_inst(stacks, INST_RA);
	rotate_impl(stacks->a);
}

// rotate stack b (the first element becomes the last one)
void	stacks_rb(t_stacks *stacks)
{
	stacks_add_inst(stacks, INST_RB);
	rotate_impl(stacks->b);
}

void	stacks_rr(t_stacks *stacks)
{
	stacks_add_inst(stacks, INST_RR);
	rotate_impl(stacks->a);
	rotate_impl(stacks->b);
}
