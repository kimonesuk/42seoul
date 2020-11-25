/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 20:19:35 by okim              #+#    #+#             */
/*   Updated: 2020/11/25 21:18:48 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if ((s1 == 0 && s2 == 0) || n == 0)
		return (0);
	i = 0;
	while (n--)
	{
		if (*((char *)s1 + i) != *((char *)s2 + i))
			return (*((char *)s1 + i) - *((char *)s2 + i));
		i++;
	}
	return (0);
}
