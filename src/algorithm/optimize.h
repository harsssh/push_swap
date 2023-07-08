/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:56:39 by kemizuki          #+#    #+#             */
/*   Updated: 2023/07/08 23:05:48 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIMIZE_H
# define OPTIMIZE_H

# include "deque/deque.h"
# include "stacks/stacks.h"
# include <stdbool.h>

void	local_optimized_sort(t_stacks *stacks);

void	optimize_instructions(t_stacks *stacks);

void	replace_ra_pb_rra(char **array);
void	replace_rb_pa_rrb(char **array);
void	replace_pb_rra_pa(char **array);
void	replace_rb_ra(char **array);

#endif
