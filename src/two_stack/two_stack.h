/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_stack.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:18:36 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/13 15:18:37 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWO_STACK_H
# define TWO_STACK_H

# include "deque/deque.h"

struct						s_two_stack
{
	t_deque					*a;
	t_deque					*b;
};
typedef struct s_two_stack	t_two_stack;

// swap two elements at the top of stack a
void						two_stack_sa(t_two_stack *two_stack);
// swap two elements at the top of stack b
void						two_stack_sb(t_two_stack *two_stack);
void						two_stack_ss(t_two_stack *two_stack);

// push the top of stack b to stack a
void						two_stack_pa(t_two_stack *two_stack);
// push the top of stack a to stack b
void						two_stack_pb(t_two_stack *two_stack);

// rotate stack a (the first element becomes the last one)
void						two_stack_ra(t_two_stack *two_stack);
// rotate stack b (the first element becomes the last one)
void						two_stack_rb(t_two_stack *two_stack);
void						two_stack_rr(t_two_stack *two_stack);

// reverse rotate stack a
void						two_stack_rra(t_two_stack *two_stack);
// reverse rotate stack b
void						two_stack_rrb(t_two_stack *two_stack);
void						two_stack_rrr(t_two_stack *two_stack);

#endif
