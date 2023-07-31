/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:55:14 by kemizuki          #+#    #+#             */
/*   Updated: 2023/07/31 19:51:58 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error/error.h"
#include "ft_ctype.h"
#include "ft_string.h"
#include "libft.h"
#include "parse_args.h"
#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

static bool	is_number(char *s)
{
	if (s == NULL || s[0] == '\0')
		return (false);
	if (s[0] == '+' || s[0] == '-')
	{
		if (s[1] == '\0')
			return (false);
		++s;
	}
	if (!ft_strall(s, ft_isdigit))
		return (false);
	return (true);
}

static int	parse_single_arg(char *arg)
{
	long	num;

	if (!is_number(arg))
		exit_with_message();
	num = ft_atol(arg);
	if (errno == ERANGE || num < INT_MIN || INT_MAX < num)
		exit_with_message();
	return ((int)num);
}

static bool	has_duplicate(const int *array, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

int	*parse_args(int argc, char **argv)
{
	int		*buf;
	size_t	i;

	if (argc < 2)
		exit(1);
	buf = (int *)ft_calloc(argc - 1, sizeof(int));
	if (buf == NULL)
		exit_with_message();
	i = 0;
	while (i < (size_t)argc - 1)
	{
		buf[i] = parse_single_arg(argv[i + 1]);
		i++;
	}
	if (has_duplicate(buf, argc - 1))
		exit_with_message();
	return (buf);
}
