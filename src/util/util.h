/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 05:55:06 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/22 18:23:29 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "stacks/stacks.h"

char	*join(char *s1, const char *s2);
char	*join_all(char **array, const char *sep);
void	free_array(char **array);
void	safe_free(void **ptr);
bool	streq(const char *s, const char *t);

#endif
