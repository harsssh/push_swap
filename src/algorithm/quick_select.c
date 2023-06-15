/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_select.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 01:11:07 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/15 18:38:36 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

static void	swap(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

static int	get_pivot(int *array, size_t left, size_t right)
{
	size_t	mid;
	bool	diff[3];

	mid = (left + right) / 2;
	diff[0] = array[left] > array[mid];
	diff[1] = array[mid] > array[right];
	diff[2] = array[right] > array[left];
	if (!(diff[0] ^ diff[1]))
		return (array[mid]);
	else if (!(diff[1] ^ diff[2]))
		return (array[right]);
	return (array[left]);
}

static size_t	partition(int *array, size_t left, size_t right)
{
	int	pivot;

	pivot = get_pivot(array, left, right);
	while (left < right)
	{
		while (array[left] < pivot)
			++left;
		while (array[right] > pivot)
			--right;
		if (left < right)
			swap(array + left, array + right);
	}
	return (left);
}

static int	do_quick_select(int *array, size_t left, size_t right, size_t k)
{
	size_t	mid;

	if (left == right)
		return (array[left]);
	mid = partition(array, left, right);
	if (k == mid)
		return (array[k]);
	else if (k < mid)
		return (do_quick_select(array, left, mid - 1, k));
	else
		return (do_quick_select(array, mid + 1, right, k));
}

int	quick_select(int *array, size_t n, size_t k)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (array[0]);
	return (do_quick_select(array, 0, n - 1, k));
}
