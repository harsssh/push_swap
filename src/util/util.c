/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 05:55:02 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/22 17:56:38 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error/error.h"
#include "libft.h"
#include "stacks/stacks.h"
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

void	repeat_inst(t_stacks *stacks, void (*inst)(t_stacks *), size_t n)
{
	while (n--)
		inst(stacks);
}

void	free_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		++i;
	}
	free(array);
}

void	safe_free(void **ptr)
{
	if (ptr == NULL)
		return ;
	free(*ptr);
	*ptr = NULL;
}
