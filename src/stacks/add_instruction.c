/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 03:37:34 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/15 18:38:58 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"
#include "util/util.h"

void	stacks_add_inst(t_stacks *stacks, const char *inst)
{
	stacks->instructions = join(stacks->instructions, inst);
	stacks->instructions = join(stacks->instructions, "\n");
}
