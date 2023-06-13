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
#include "stacks.h"
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
void	stacks_rra(t_stacks *stacks)
{
	ft_putstr_fd("rra\n", STDOUT_FILENO);
	rotate_reverse_impl(stacks->a);
}

// reverse rotate stack b
void	stacks_rrb(t_stacks *stacks)
{
	ft_putstr_fd("rrb\n", STDOUT_FILENO);
	rotate_reverse_impl(stacks->b);
}

void	stacks_rrr(t_stacks *stacks)
{
	ft_putstr_fd("rrr\n", STDOUT_FILENO);
	rotate_reverse_impl(stacks->a);
	rotate_reverse_impl(stacks->b);
}
