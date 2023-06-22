/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:31:12 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/22 18:23:34 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H

# include "deque/deque.h"
# include "stacks/stacks.h"
# include <stdbool.h>

bool	is_sorted(t_stacks *stacks, size_t n);
int		get_median(t_deque *deque, size_t n);
void	repeat_inst(t_stacks *stacks, void (*inst)(t_stacks *), size_t n);
char	*must_strdup(const char *s);

#endif
