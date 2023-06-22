/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 05:54:35 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/22 18:06:21 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include "error/error.h"
#include "libft.h"
#include "stacks/stacks.h"
#include "util/util.h"
#include "helper.h"
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

static void	replace_ra_pb_rra(char **array)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (array[i])
	{
		if (j > 1 && streq(array[j - 2], INST_RA) && streq(array[j - 1],
				INST_PB) && streq(array[i], INST_RRA))
		{
			safe_free((void **)(array + i));
			safe_free((void **)(array + j - 2));
			array[j - 2] = must_strdup(INST_SA);
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

static void	replace_rb_pa_rrb(char **array)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (array[i])
	{
		if (j > 1 && streq(array[j - 2], INST_RB) && streq(array[j - 1],
				INST_PA) && streq(array[i], INST_RRB))
		{
			safe_free((void **)(array + i));
			safe_free((void **)(array + j - 2));
			array[j - 2] = must_strdup(INST_SB);
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

static void	replace_pb_rra_pa(char **array)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (array[i])
	{
		if (j > 1 && streq(array[j - 2], INST_PB) && streq(array[j - 1],
				INST_RRA) && streq(array[i], INST_PA))
		{
			safe_free((void **)(array + i));
			safe_free((void **)(array + j - 2));
			array[j - 2] = array[j - 1];
			array[j - 1] = must_strdup(INST_SA);
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
	remove_adjacent(array, INST_RA, INST_RRA);
	remove_adjacent(array, INST_RB, INST_RRB);
	remove_adjacent(array, INST_PA, INST_PB);
	stacks->instructions = join_all(array, "\n");
	free_array(array);
}
