/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 05:55:06 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/15 06:08:46 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

char	*join(char *s1, const char *s2);
char	*join_all(char **array, const char *sep);
void	repeat_inst(t_stacks *stacks, void (*inst)(t_stacks *), size_t n);

#endif
