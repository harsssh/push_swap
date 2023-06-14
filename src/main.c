/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:02:29 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/14 12:09:33 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm/algorithm.h"
#include "args/parse_args.h"
#include "deque/deque.h"
#include "stacks/stacks.h"
#include <stdlib.h>

static void	fill_deque(t_deque *deque, int *array, size_t size)
{
	while (size--)
		deque_push_back(deque, array[size]);
}

int	main(int argc, char **argv)
{
	int			*args;
	t_deque		*a;
	t_deque		*b;
	t_stacks	stacks;

	args = parse_args(argc, argv);
	if (args == NULL)
		return (1);
	a = deque_init(argc - 1);
	b = deque_init(argc - 1);
	if (a == NULL || b == NULL)
		return (1);
	fill_deque(a, args, argc - 1);
	free(args);
	stacks.a = a;
	stacks.b = b;
	sort_stacks(&stacks, argc - 1);
	deque_destroy(a);
	deque_destroy(b);
}
