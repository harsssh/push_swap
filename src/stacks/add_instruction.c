/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 03:37:34 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/15 03:55:18 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error/error.h"
#include "libft.h"
#include "stacks.h"
#include <stdlib.h>

static void	append_string(t_stacks *stacks, const char *s)
{
	char	*tmp;

	tmp = stacks->instructions;
	stacks->instructions = ft_strjoin(stacks->instructions, s);
	if (stacks->instructions == NULL)
		exit_with_message();
	free(tmp);
}

void	stacks_add_instruction(t_stacks *stacks, const char *inst)
{
	append_string(stacks, "\n");
	append_string(stacks, inst);
}
