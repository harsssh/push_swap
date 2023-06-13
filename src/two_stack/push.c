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
#include "two_stack.h"
#include <unistd.h>

// push the top of stack b to stack a
void	two_stack_pa(t_two_stack *two_stack)
{
	ft_putstr_fd("pa\n", STDOUT_FILENO);
	if (two_stack->b->is_empty)
		return ;
	deque_push_back(two_stack->a, deque_pop_back(two_stack->b));
}

// push the top of stack a to stack b
void	two_stack_pb(t_two_stack *two_stack)
{
	ft_putstr_fd("pb\n", STDOUT_FILENO);
	if (two_stack->a->is_empty)
		return ;
	deque_push_back(two_stack->b, deque_pop_back(two_stack->a));
}
