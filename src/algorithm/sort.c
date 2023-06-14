/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:08:28 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/14 12:09:00 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include <libc.h>

static int	compare_int(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

static int	get_pivot(t_stacks *stack, size_t n)
{
	int	*array;
	int	pivot;

	array = malloc(sizeof(int) * n);
	for (size_t i = 0; i < n; i++)
		array[i] = deque_at_back(stack->a, i);
	qsort(array, n, sizeof(int), compare_int);
	pivot = array[n / 2];
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
	remain = separate_by_pivot(stacks, n, get_pivot(stacks, n));
	sort_stacks(stacks, remain);
	revert_separation(stacks, n - remain);
	sort_stacks(stacks, n - remain);
}
