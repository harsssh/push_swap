/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 05:55:02 by kemizuki          #+#    #+#             */
/*   Updated: 2023/07/08 23:05:23 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error/error.h"
#include "libft.h"
#include "stacks/stacks.h"
#include "util.h"
#include <stdlib.h>

char	*join(char *s1, const char *s2)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	if (result == NULL)
		exit_with_message();
	free(s1);
	return (result);
}

char	*join_all(char **array, const char *sep)
{
	char	*result;

	result = ft_strdup("");
	if (result == NULL)
		exit_with_message();
	while (*array)
	{
		result = join(result, *array);
		result = join(result, sep);
		++array;
	}
	return (result);
}

bool	streq(const char *s, const char *t)
{
	return (ft_strcmp(s, t) == 0);
}

char	*must_strdup(const char *s)
{
	char	*res;

	res = ft_strdup(s);
	if (res == NULL)
		exit_with_message();
	return (res);
}
