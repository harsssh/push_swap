/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:08:28 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/15 18:38:46 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include "error/error.h"
#include "util/util.h"
#include <libc.h>
#include <stdbool.h>
#include <stdlib.h>

static bool	is_sorted(t_stacks *stacks, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n - 1)
	{
		if (deque_at_back(stacks->a, i) > deque_at_back(stacks->a, i + 1))
			return (false);
		i++;
	}
	return (true);
}

static int	get_pivot(t_stacks *stack, size_t n)
{
	size_t	i;
	int		*array;
	int		pivot;

	array = malloc(sizeof(int) * n);
	if (!array)
		exit_with_message();
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
	size_t	push_count;
	size_t	rotate_count;
	size_t	i;

	i = n;
	push_count = 0;
	rotate_count = 0;
	while (i--)
	{
		if (deque_at_back(stacks->a, 0) < pivot)
		{
			stacks_pb(stacks);
			++push_count;
		}
		else
		{
			stacks_ra(stacks);
			++rotate_count;
		}
		if (push_count >= n / 2)
			break ;
	}
	if (n - push_count != deque_size(stacks->a))
		repeat_inst(stacks, stacks_rra, rotate_count);
	return (n - push_count);
}

// sort the first n elements of stack a in ascending order
static void	do_sort_stacks(t_stacks *stacks, size_t n)
{
	size_t	remain;

	if (n == 1)
		return ;
	if (n == 2)
	{
		if (deque_at_back(stacks->a, 0) > deque_at_back(stacks->a, 1))
			stacks_sa(stacks);
		return ;
	}
	if (n == 3 && deque_size(stacks->a) == 3)
	{
		if (deque_at_back(stacks->a, 0) > deque_at_back(stacks->a, 1))
			stacks_sa(stacks);
		if (deque_at_back(stacks->a, 1) > deque_at_back(stacks->a, 2))
			stacks_rra(stacks);
		if (deque_at_back(stacks->a, 0) > deque_at_back(stacks->a, 1))
			stacks_sa(stacks);
		return ;
	}
	if (is_sorted(stacks, n))
		return ;
	remain = separate_by_pivot(stacks, n, get_pivot(stacks, n));
	do_sort_stacks(stacks, remain);
	repeat_inst(stacks, stacks_pa, n - remain);
	do_sort_stacks(stacks, n - remain);
}

void	sort_stacks(t_stacks *stacks, size_t n)
{
	do_sort_stacks(stacks, n);
	optimize_instructions(stacks);
}
