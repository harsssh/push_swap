/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 23:05:15 by kemizuki          #+#    #+#             */
/*   Updated: 2023/07/08 23:05:16 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks/stacks.h"
#include <stdlib.h>

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
