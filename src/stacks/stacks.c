/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 02:00:23 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/15 02:00:24 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

void	stacks_init(t_stacks *stacks, t_deque *a, t_deque *b)
{
	stacks->a = a;
	stacks->b = b;
	stacks->instructions = NULL;
}
