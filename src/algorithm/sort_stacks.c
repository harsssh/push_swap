/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:08:28 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/22 08:14:43 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include "deque/deque.h"
#include "error/error.h"
#include "util/util.h"
#include <libc.h>
#include <stdbool.h>
#include <stdio.h>
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

static int	get_pivot(t_deque *deque, size_t n)
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
		array[i] = deque_at_back(deque, i);
		i++;
	}
	pivot = quick_select(array, n, n / 2);
	free(array);
	return (pivot);
}

static size_t	separate_by_pivot(t_stacks *stacks, size_t n)
{
	int		pivot;
	size_t	push_count;
	size_t	rotate_count;

	pivot = get_pivot(stacks->a, n);
	push_count = 0;
	rotate_count = 0;
	while (push_count < n / 2)
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
	}
	if (n - push_count != deque_size(stacks->a))
		repeat_inst(stacks, stacks_rra, rotate_count);
	return (push_count);
}

static size_t	merge_back_to_a(t_stacks *stacks, size_t n)
{
	int		pivot;
	size_t	push_count;
	size_t	rotate_count;

	if (n <= 3)
	{
		repeat_inst(stacks, stacks_pa, n);
		return n;
	}
	pivot = get_pivot(stacks->b, n);
	push_count = 0;
	rotate_count = 0;
	while (push_count < (n+1) / 2)
	{
		if (deque_at_back(stacks->b, 0) >= pivot)
		{
			stacks_pa(stacks);
			++push_count;
		}
		else
		{
			stacks_rb(stacks);
			++rotate_count;
		}
	}
	repeat_inst(stacks, stacks_rrb, rotate_count);
	return (push_count);
}

// sort the first n elements of stack a in ascending order
static void	do_sort_stacks(t_stacks *stacks, size_t n)
{
	size_t	pushed;

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
	pushed = separate_by_pivot(stacks, n);
	do_sort_stacks(stacks, n - pushed);
	while (pushed > 0)
	{
		size_t k = merge_back_to_a(stacks, pushed);
		pushed -= k;
		do_sort_stacks(stacks, k);
	}
}

void	sort_stacks(t_stacks *stacks, size_t n)
{
	do_sort_stacks(stacks, n);
	optimize_instructions(stacks);
}
