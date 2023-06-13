/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 01:03:23 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/13 16:49:56 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	deque_push_front(t_deque *deque, int value)
{
	if (deque_size(deque) == deque->capacity)
		return ;
	deque->begin = (deque->begin + deque->capacity - 1) % deque->capacity;
	deque->data[deque->begin] = value;
	deque->is_empty = false;
}

void	deque_push_back(t_deque *deque, int value)
{
	if (deque_size(deque) == deque->capacity)
		return ;
	deque->data[deque->end] = value;
	deque->end = (deque->end + 1) % deque->capacity;
	deque->is_empty = false;
}

int	deque_pop_front(t_deque *deque)
{
	int	value;

	if (deque_size(deque) == 0)
		return (0);
	value = deque->data[deque->begin];
	deque->begin = (deque->begin + 1) % deque->capacity;
	if (deque->begin == deque->end)
		deque->is_empty = true;
	return (value);
}

int	deque_pop_back(t_deque *deque)
{
	int	value;

	if (deque_size(deque) == 0)
		return (0);
	deque->end = (deque->end + deque->capacity - 1) % deque->capacity;
	value = deque->data[deque->end];
	if (deque->begin == deque->end)
		deque->is_empty = true;
	return (value);
}
