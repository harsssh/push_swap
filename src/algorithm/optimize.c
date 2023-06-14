/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 05:54:35 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/15 06:47:38 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include "error/error.h"
#include "libft.h"
#include "stacks/stacks.h"
#include "util/util.h"
#include <stdlib.h>

static bool	streq(const char *s, const char *t)
{
	return (ft_strcmp(s, t) == 0);
}

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
			free(array[i]);
			free(array[j - 1]);
			array[i] = NULL;
			array[j - 1] = NULL;
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

static void	replace_sequence(char **array, const char *s, const char *t,
		const char *u)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (array[i])
	{
		if (j > 1 && streq(array[j - 2], s) && streq(array[j - 1], t)
			&& streq(array[i], u))
		{
			free(array[i]);
			free(array[j - 2]);
			array[i] = NULL;
			array[j - 2] = ft_strdup(INST_SA);
			if (array[j - 2] == NULL)
				exit_with_message();
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

static void	free_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		++i;
	}
	free(array);
}

void	optimize_instructions(t_stacks *stacks)
{
	char	**array;

	array = ft_split(stacks->instructions, '\n');
	if (array == NULL)
		exit_with_message();
	free(stacks->instructions);
	remove_adjacent(array, INST_PA, INST_PB);
	remove_adjacent(array, INST_RA, INST_RRA);
	replace_sequence(array, INST_RA, INST_PB, INST_RRA);
	stacks->instructions = join_all(array, "\n");
	free_array(array);
}
