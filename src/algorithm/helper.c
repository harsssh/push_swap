/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:31:07 by kemizuki          #+#    #+#             */
/*   Updated: 2023/07/08 23:05:59 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include "error/error.h"
#include <stdlib.h>

bool	is_sorted(t_stacks *stacks, size_t n)
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

int	get_median(t_deque *deque, size_t n)
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

void	get_boundaries(t_deque *deque, size_t n, int *lower, int *upper)
{
	size_t	i;
	int		*array;

	array = malloc(sizeof(int) * n);
	if (!array)
		exit_with_message();
	i = 0;
	while (i < n)
	{
		array[i] = deque_at_back(deque, i);
		i++;
	}
	*lower = quick_select(array, n, n / 4);
	*upper = quick_select(array, n, n / 2);
	free(array);
}

void	repeat_inst(t_stacks *stacks, void (*inst)(t_stacks *), size_t n)
{
	while (n--)
		inst(stacks);
}
