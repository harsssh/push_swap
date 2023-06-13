/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:18:28 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/13 15:18:29 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "two_stack.h"
#include <unistd.h>

static void	rotate_impl(t_deque *deque)
{
	int	top;

	if (deque_size(deque) < 2)
		return ;
	top = deque_pop_back(deque);
	deque_push_front(deque, top);
}

// rotate stack a (the first element becomes the last one)
void	two_stack_ra(t_two_stack *two_stack)
{
	ft_putstr_fd("ra\n", STDOUT_FILENO);
	rotate_impl(two_stack->a);
}

// rotate stack b (the first element becomes the last one)
void	two_stack_rb(t_two_stack *two_stack)
{
	ft_putstr_fd("rb\n", STDOUT_FILENO);
	rotate_impl(two_stack->b);
}

void	two_stack_rr(t_two_stack *two_stack)
{
	ft_putstr_fd("rr\n", STDOUT_FILENO);
	rotate_impl(two_stack->a);
	rotate_impl(two_stack->b);
}
