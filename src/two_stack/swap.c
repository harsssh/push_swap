/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:18:33 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/13 15:18:34 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "two_stack.h"
#include <unistd.h>

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
void	two_stack_sa(t_two_stack *two_stack)
{
	ft_putstr_fd("sa\n", STDOUT_FILENO);
	swap_impl(two_stack->a);
}

// swap two elements at the top of stack b
void	two_stack_sb(t_two_stack *two_stack)
{
	ft_putstr_fd("sb\n", STDOUT_FILENO);
	swap_impl(two_stack->b);
}

void	two_stack_ss(t_two_stack *two_stack)
{
	ft_putstr_fd("ss\n", STDOUT_FILENO);
	swap_impl(two_stack->a);
	swap_impl(two_stack->b);
}
