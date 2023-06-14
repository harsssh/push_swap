/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:08:28 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/15 01:11:24 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include <libc.h>
#include <stdlib.h>

static int	get_pivot(t_stacks *stack, size_t n)
{
	size_t	i;
	int		*array;
	int		pivot;

	array = malloc(sizeof(int) * n);
	if (!array)
		exit(1);
	i = 0;
	while (i < n)
	{
		array[i] = deque_at_back(stack->a, i);
		i++;
	}
	pivot = quick_select(array, n, n / 2);
	free(array);
	return (pivot);
}

static size_t	separate_by_pivot(t_stacks *stacks, size_t n, int pivot)
{
	size_t	remain;
	size_t	i;

	remain = 0;
	while (n--)
	{
		if (deque_at_back(stacks->a, 0) < pivot)
			stacks_pb(stacks);
		else
		{
			stacks_ra(stacks);
			remain++;
		}
	}
	if (remain != deque_size(stacks->a))
	{
		i = 0;
		while (i < remain)
		{
			stacks_rra(stacks);
			i++;
		}
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
	remain = separate_by_pivot(stacks, n, get_pivot(stacks, n));
	sort_stacks(stacks, remain);
	revert_separation(stacks, n - remain);
	sort_stacks(stacks, n - remain);
}
