/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 05:54:35 by kemizuki          #+#    #+#             */
/*   Updated: 2023/07/08 23:05:37 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error/error.h"
#include "libft.h"
#include "optimize.h"
#include "stacks/stacks.h"
#include "util/util.h"
#include <stdlib.h>

static void	remove_adjacent(char **array, const char *s, const char *t)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (array[i])
	{
		if (j > 0 && ((streq(array[i], s) && streq(array[j - 1], t))
				|| (streq(array[i], t) && streq(array[j - 1], s))))
		{
			safe_free((void **)(array + i));
			safe_free((void **)(array + j - 1));
			--j;
		}
		else
		{
			array[j] = array[i];
			if (i != j)
				array[i] = NULL;
			++j;
		}
		++i;
	}
}

void	optimize_instructions(t_stacks *stacks)
{
	char	**array;

	array = ft_split(stacks->instructions, '\n');
	if (array == NULL)
		exit_with_message();
	free(stacks->instructions);
	replace_ra_pb_rra(array);
	replace_rb_pa_rrb(array);
	replace_pb_rra_pa(array);
	replace_rb_ra(array);
	remove_adjacent(array, INST_RA, INST_RRA);
	remove_adjacent(array, INST_RB, INST_RRB);
	remove_adjacent(array, INST_PA, INST_PB);
	stacks->instructions = join_all(array, "\n");
	free_array(array);
}
