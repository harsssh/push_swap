/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:18:36 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/15 02:00:33 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

# include "deque/deque.h"

typedef struct s_stacks
{
	t_deque	*a;
	t_deque	*b;
	char	*instructions;
}			t_stacks;

void		stacks_init(t_stacks *stacks, t_deque *a, t_deque *b);

// swap two elements at the top of stack a
void		stacks_sa(t_stacks *stacks);
// swap two elements at the top of stack b
void		stacks_sb(t_stacks *stacks);
void		stacks_ss(t_stacks *stacks);

// push the top of stack b to stack a
void		stacks_pa(t_stacks *stacks);
// push the top of stack a to stack b
void		stacks_pb(t_stacks *stacks);

// rotate stack a (the first element becomes the last one)
void		stacks_ra(t_stacks *stacks);
// rotate stack b (the first element becomes the last one)
void		stacks_rb(t_stacks *stacks);
void		stacks_rr(t_stacks *stacks);

// reverse rotate stack a
void		stacks_rra(t_stacks *stacks);
// reverse rotate stack b
void		stacks_rrb(t_stacks *stacks);
void		stacks_rrr(t_stacks *stacks);

#endif
