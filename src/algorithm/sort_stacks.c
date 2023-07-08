/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:08:28 by kemizuki          #+#    #+#             */
/*   Updated: 2023/07/08 19:09:05 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include "deque/deque.h"
#include "helper.h"
#include "optimize.h"
#include "stacks/stacks.h"
#include <stdbool.h>

static size_t	partition(t_stacks *stacks, size_t n)
{
	int		lower;
	int		upper;
	size_t	push_count;
	size_t	rotate_count;

	get_boundaries(stacks->a, n, &lower, &upper);
	push_count = 0;
	rotate_count = 0;
	while (push_count < n / 2)
	{
		if (deque_at_back(stacks->a, 0) < upper)
		{
			stacks_pb(stacks);
			++push_count;
			if (stacks->partitions == 1 && deque_at_back(stacks->b, 0) < lower)
				stacks_rb(stacks);
		}
		else
		{
			stacks_ra(stacks);
			++rotate_count;
		}
	}
	if (n - push_count != deque_size(stacks->a))
		repeat_inst(stacks, stacks_rra, rotate_count);
	++stacks->partitions;
	return (push_count);
}

static size_t	restore_half(t_stacks *stacks, size_t n)
{
	int		pivot;
	size_t	push_count;
	size_t	rotate_count;

	pivot = get_median(stacks->b, n);
	push_count = 0;
	rotate_count = 0;
	while (push_count < (n + 1) / 2)
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
	if (stacks->partitions > 2)
		repeat_inst(stacks, stacks_rrb, rotate_count);
	return (push_count);
}

static bool	should_terminate(t_stacks *stacks, size_t n)
{
	if (n == 1)
		return (true);
	if (n == 2)
	{
		if (deque_at_back(stacks->a, 0) > deque_at_back(stacks->a, 1))
			stacks_sa(stacks);
		return (true);
	}
	if (n == 3 && deque_size(stacks->a) == 3)
	{
		if (deque_at_back(stacks->a, 0) > deque_at_back(stacks->a, 1))
			stacks_sa(stacks);
		if (deque_at_back(stacks->a, 1) > deque_at_back(stacks->a, 2))
			stacks_rra(stacks);
		if (deque_at_back(stacks->a, 0) > deque_at_back(stacks->a, 1))
			stacks_sa(stacks);
		return (true);
	}
	if (is_sorted(stacks, n))
		return (true);
	return (false);
}

#include "error/error.h"
#include <stdlib.h>
void get_min_max(t_deque *deque, int *min, int *max)
{
	size_t	i;
	int		*array;
	size_t n = deque_size(deque);

	array = malloc(sizeof(int) * n);
	if (!array)
		exit_with_message();
	i = 0;
	while (i < n)
	{
		array[i] = deque_at_back(deque, i);
		i++;
	}
	*min = quick_select(array, n, 0);
	*max = quick_select(array, n, n - 1);
	free(array);
}

static void f(t_stacks *stacks)
{
	int min, max;
	size_t count = 0;
	while (!stacks->b->is_empty)
	{
		get_min_max(stacks->b, &min, &max);
		size_t n = deque_size(stacks->b);
		size_t i = 0;
		if (n == 1)
		{
			stacks_pa(stacks);
			break;
		}
		while (deque_at_back(stacks->b, i) != max)
			i++;
		void (*rotate)(t_stacks *);
		if (i < n / 2)
			rotate = stacks_rb;
		else
			rotate = stacks_rrb;
		while (true)
		{
			int top = deque_at_back(stacks->b, 0);
			if (top == min)
			{
				stacks_pa(stacks);
				stacks_ra(stacks);
				++count;
			} else if (top == max)
			{
				stacks_pa(stacks);
				break;
			} else {
				rotate(stacks);
			}
		}
	}
	while (count--)
		stacks_rra(stacks);
}

// sort the first n elements of stack a in ascending order
static void	do_sort_stacks(t_stacks *stacks, size_t n)
{
	size_t	pushed;
	size_t	restored;

	if (should_terminate(stacks, n))
		return ;
	pushed = partition(stacks, n);
	do_sort_stacks(stacks, n - pushed);
	while (pushed > 0)
	{
		if (deque_size(stacks->b) <= 25)
		{
			f(stacks);
			break;
		}
		if (pushed > 2)
			restored = restore_half(stacks, pushed);
		else
		{
			repeat_inst(stacks, stacks_pa, pushed);
			restored = pushed;
		}
		pushed -= restored;
		do_sort_stacks(stacks, restored);
	}
	--stacks->partitions;
}

void	sort_stacks(t_stacks *stacks, size_t n)
{
	do_sort_stacks(stacks, n);
	optimize_instructions(stacks);
}
