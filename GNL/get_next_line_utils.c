/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 09:42:49 by okim              #+#    #+#             */
/*   Updated: 2021/01/31 22:05:08 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy_slice(char *buf, char *str, size_t start, size_t end)
{
	size_t	size;

	size = end - start + 1;
	if (ft_strlen(str) > start && size >= 0)
	{
		str += start;
		while (size-- && *str != '\0')
			*(buf++) = *(str++);
		*buf = '\0';
	}
	return buf;
}

size_t	have_end(const char	*str, size_t size)
{
	size_t	len;

	len = ft_strlen(str);
	if (len < size)
		return (len);
	else
		return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}
