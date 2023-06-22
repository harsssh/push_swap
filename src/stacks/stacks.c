/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 02:00:23 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/22 17:49:51 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque/deque.h"
#include "error/error.h"
#include "stacks.h"
#include <stdlib.h>

void	stacks_init(t_stacks *stacks, size_t capacity)
{
	stacks->a = deque_init(capacity);
	stacks->b = deque_init(capacity);
	if (stacks->a == NULL || stacks->b == NULL)
		exit_with_message();
	stacks->instructions = NULL;
	stacks->partitions = 1;
}

void	stacks_destroy(t_stacks *stacks)
{
	deque_destroy(stacks->a);
	deque_destroy(stacks->b);
	free(stacks->instructions);
}
