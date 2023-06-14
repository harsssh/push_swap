/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:18:36 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/15 03:36:59 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

# define INST_SA "sa\n"
# define INST_SB "sb\n"
# define INST_SS "ss\n"
# define INST_PA "pa\n"
# define INST_PB "pb\n"
# define INST_RA "ra\n"
# define INST_RB "rb\n"
# define INST_RR "rr\n"
# define INST_RRA "rra\n"
# define INST_RRB "rrb\n"
# define INST_RRR "rrr\n"

# include "deque/deque.h"

typedef struct s_stacks
{
	t_deque	*a;
	t_deque	*b;
	char	*instructions;
}			t_stacks;

void		stacks_init(t_stacks *stacks, size_t capacity);
void		stacks_destroy(t_stacks *stacks);

void		stacks_add_instruction(t_stacks *stacks, const char *inst);

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
