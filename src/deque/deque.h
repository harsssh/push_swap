/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 01:02:43 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/15 05:54:23 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H

# include <stdbool.h>
# include <stddef.h>

typedef struct s_deque
{
	int		*data;
	size_t	begin;
	size_t	end;
	size_t	capacity;
	bool	is_empty;
}			t_deque;

t_deque		*deque_init(size_t capacity);
void		deque_destroy(t_deque *deque);
size_t		deque_size(t_deque *deque);
void		deque_push_front(t_deque *deque, int value);
void		deque_push_back(t_deque *deque, int value);
int			deque_pop_front(t_deque *deque);
int			deque_pop_back(t_deque *deque);
int			deque_at(t_deque *deque, size_t index);
int			deque_at_back(t_deque *deque, size_t index);

#endif
