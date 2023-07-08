/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:31:12 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/23 00:32:48 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H

# include "deque/deque.h"
# include "stacks/stacks.h"
# include <stdbool.h>

bool	is_sorted(t_stacks *stacks, size_t n);
int		get_median(t_deque *deque, size_t n);
void	get_boundaries(t_deque *deque, size_t n, int *lower, int *upper);
void	repeat_inst(t_stacks *stacks, void (*inst)(t_stacks *), size_t n);

#endif
