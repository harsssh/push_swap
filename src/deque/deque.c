/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 01:03:05 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/14 12:08:46 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include <stdlib.h>

t_deque	*deque_init(size_t capacity)
{
	t_deque	*stack;

	stack = malloc(sizeof(t_deque));
	if (stack == NULL)
		return (NULL);
	stack->data = malloc(capacity * sizeof(int));
	if (stack->data == NULL)
	{
		free(stack);
		return (NULL);
	}
	stack->begin = 0;
	stack->end = 0;
	stack->is_empty = true;
	stack->capacity = capacity;
	return (stack);
}

void	deque_destroy(t_deque *deque)
{
	free(deque->data);
	free(deque);
}

size_t	deque_size(t_deque *deque)
{
	if (deque->is_empty)
		return (0);
	if (deque->begin < deque->end)
		return (deque->end - deque->begin);
	else
		return (deque->capacity - deque->begin + deque->end);
}

int	deque_at(t_deque *deque, unsigned int index)
{
	return (deque->data[(deque->begin + index) % deque->capacity]);
}

int	deque_at_back(t_deque *deque, unsigned int index)
{
	return (deque_at(deque, deque_size(deque) - index - 1));
}
