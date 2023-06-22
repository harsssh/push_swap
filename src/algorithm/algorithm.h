/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:09:18 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/15 05:55:53 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include "stacks/stacks.h"

void	sort_stacks(t_stacks *stacks, size_t n);
int		quick_select(int *array, size_t n, size_t k);

#endif
