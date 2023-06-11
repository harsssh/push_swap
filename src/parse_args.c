/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:55:14 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/11 23:41:37 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse_args.h"
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

static void	exit_with_message(void)
{
	ft_putstr_fd(ERR_MSG, STDERR_FILENO);
	exit(1);
}

static bool	is_number(char *s)
{
	size_t	i;

	if (s == NULL || *s == '\0')
		return (false);
	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (false);
		i++;
	}
	if (i > 1 && *s == '0')
		return (false);
	return (true);
}

static int	parse_single_arg(char *arg)
{
	long long	num;

	if (!is_number(arg))
		exit_with_message();
	num = ft_atoll(arg);
	if (num < INT_MIN || num > INT_MAX)
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
		exit_with_message();
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
