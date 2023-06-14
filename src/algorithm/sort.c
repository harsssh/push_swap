/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:08:28 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/14 17:35:55 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

static int	get_pivot(t_stacks *stack)
{
	int			top[3];
	long long	diff[3];

	top[0] = deque_at_back(stack->a, 0);
	top[1] = deque_at_back(stack->a, 1);
	top[2] = deque_at_back(stack->a, 2);
	diff[0] = top[0] - top[1];
	diff[1] = top[1] - top[2];
	diff[2] = top[2] - top[0];
	if (diff[0] * diff[1] > 0)
		return (top[1]);
	else if (diff[1] * diff[2] > 0)
		return (top[2]);
	else
		return (top[0]);
}

static size_t	separate_by_pivot(t_stacks *stacks, size_t n, int pivot)
{
	size_t	remain;
	size_t	i;

	remain = 0;
	while (n--)
	{
		if (deque_at_back(stacks->a, 0) <= pivot)
			stacks_pb(stacks);
		else
		{
			stacks_ra(stacks);
			remain++;
		}
	}
	i = 0;
	while (i < remain)
	{
		stacks_rra(stacks);
		i++;
	}
	return (remain);
}

static void	revert_separation(t_stacks *stacks, size_t n)
{
	while (n--)
		stacks_pa(stacks);
}

void	sort_stacks(t_stacks *stacks, size_t n)
{
	size_t	remain;

	if (n <= 1)
		return ;
	if (n == 2)
	{
		if (deque_at_back(stacks->a, 0) > deque_at_back(stacks->a, 1))
			stacks_sa(stacks);
		return ;
	}
	remain = separate_by_pivot(stacks, n, get_pivot(stacks));
	sort_stacks(stacks, remain);
	revert_separation(stacks, n - remain);
	sort_stacks(stacks, n - remain);
}
