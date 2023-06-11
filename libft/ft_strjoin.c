/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 09:33:56 by kemizuki          #+#    #+#             */
/*   Updated: 2023/05/21 21:53:57 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	joined_len(const char *s1, char const *s2)
{
	size_t	len;

	len = 0;
	if (s1 != NULL)
		len += ft_strlen(s1);
	if (s2 != NULL)
		len += ft_strlen(s2);
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buf;
	size_t	buf_len;

	buf_len = joined_len(s1, s2) + 1;
	buf = ft_calloc(buf_len, sizeof(char));
	if (buf == NULL)
		return (NULL);
	if (s1 != NULL)
		ft_strlcat(buf, s1, buf_len);
	if (s2 != NULL)
		ft_strlcat(buf, s2, buf_len);
	return (buf);
}
