/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:18:31 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/13 15:18:31 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "two_stack.h"
#include <unistd.h>

static void	rotate_reverse_impl(t_deque *deque)
{
	int	bottom;

	if (deque_size(deque) < 2)
		return ;
	bottom = deque_pop_front(deque);
	deque_push_back(deque, bottom);
}

// reverse rotate stack a
void	two_stack_rra(t_two_stack *two_stack)
{
	ft_putstr_fd("rra\n", STDOUT_FILENO);
	rotate_reverse_impl(two_stack->a);
}

// reverse rotate stack b
void	two_stack_rrb(t_two_stack *two_stack)
{
	ft_putstr_fd("rrb\n", STDOUT_FILENO);
	rotate_reverse_impl(two_stack->b);
}

void	two_stack_rrr(t_two_stack *two_stack)
{
	ft_putstr_fd("rrr\n", STDOUT_FILENO);
	rotate_reverse_impl(two_stack->a);
	rotate_reverse_impl(two_stack->b);
}
