/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_replace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:57:00 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/23 00:57:01 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"
#include "optimize.h"
#include "stacks/stacks.h"
#include "util/util.h"
#include "util.h"

void	replace_ra_pb_rra(char **array)
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

void	replace_rb_pa_rrb(char **array)
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

void	replace_pb_rra_pa(char **array)
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

void	replace_rb_ra(char **array)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (array[i])
	{
		if (j > 0 && ((streq(array[i], INST_RA) && streq(array[j - 1], INST_RB))
				|| (streq(array[i], INST_RB) && streq(array[j - 1], INST_RA))))
		{
			safe_free((void **)(array + i));
			safe_free((void **)(array + j - 1));
			array[j - 1] = must_strdup(INST_RR);
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
