/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_optimized_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 23:02:29 by kemizuki          #+#    #+#             */
/*   Updated: 2023/07/08 23:13:19 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include "error/error.h"
#include "optimize.h"
#include "stacks/stacks.h"
#include <stdlib.h>

typedef void		(*t_inst_func)(t_stacks *);

static t_inst_func	get_rotate_func(t_deque *deque, int max)
{
	size_t	n;
	size_t	i;

	n = deque_size(deque);
	i = 0;
	while (deque_at_back(deque, i) != max)
		i++;
	if (i < n / 2)
		return (stacks_rb);
	else
		return (stacks_rrb);
}

static void	get_min_max(t_deque *deque, int *min, int *max)
{
	size_t	i;
	size_t	n;
	int		*array;

	n = deque_size(deque);
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

static size_t	push_min_max(t_stacks *stacks)
{
	int		min;
	int		max;
	size_t	ra_count;
	void	(*rotate)(t_stacks *);

	ra_count = 0;
	get_min_max(stacks->b, &min, &max);
	rotate = get_rotate_func(stacks->b, max);
	while (true)
	{
		if (deque_at_back(stacks->b, 0) == min)
		{
			stacks_pa(stacks);
			stacks_ra(stacks);
			++ra_count;
		}
		else if (deque_at_back(stacks->b, 0) == max)
		{
			stacks_pa(stacks);
			break ;
		}
		else
			rotate(stacks);
	}
	return (ra_count);
}

// If there are unsorted elements only in stack b, sort them straightforwardly
void	local_optimized_sort(t_stacks *stacks)
{
	size_t	ra_count;

	ra_count = 0;
	while (!stacks->b->is_empty)
	{
		if (deque_size(stacks->b) == 1)
		{
			stacks_pa(stacks);
			break ;
		}
		ra_count += push_min_max(stacks);
	}
	while (ra_count--)
		stacks_rra(stacks);
}
