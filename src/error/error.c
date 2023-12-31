/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 03:36:19 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/15 03:36:20 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void	exit_with_message(void)
{
	ft_putstr_fd(ERR_MSG, STDERR_FILENO);
	exit(1);
}
