/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:02:29 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/15 03:38:18 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm/algorithm.h"
#include "args/parse_args.h"
#include "deque/deque.h"
#include "libft.h"
#include "stacks/stacks.h"
#include <stdlib.h>
#include <unistd.h>

static void	fill_deque(t_deque *deque, int *array, size_t size)
{
	while (size--)
		deque_push_back(deque, array[size]);
}

int	main(int argc, char **argv)
{
	int			*args;
	t_stacks	stacks;

	args = parse_args(argc, argv);
	if (args == NULL)
		return (1);
	stacks_init(&stacks, argc - 1);
	fill_deque(stacks.a, args, argc - 1);
	free(args);
	sort_stacks(&stacks, argc - 1);
	ft_putstr_fd(stacks.instructions, STDOUT_FILENO);
	stacks_destroy(&stacks);
}
