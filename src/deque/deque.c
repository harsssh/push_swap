/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 01:03:05 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/12 01:38:28 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include <stdlib.h>

t_deque	*new_deque(size_t capacity)
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

void	free_deque(t_deque *deque)
{
	free(deque->data);
	free(deque);
}