/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:18:26 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/15 03:38:11 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

// push the top of stack b to stack a
void	stacks_pa(t_stacks *stacks)
{
	stacks_add_instruction(stacks, INST_PA);
	if (stacks->b->is_empty)
		return ;
	deque_push_back(stacks->a, deque_pop_back(stacks->b));
}

// push the top of stack a to stack b
void	stacks_pb(t_stacks *stacks)
{
	stacks_add_instruction(stacks, INST_PB);
	if (stacks->a->is_empty)
		return ;
	deque_push_back(stacks->b, deque_pop_back(stacks->a));
}
