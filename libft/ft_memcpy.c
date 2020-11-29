/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:22:55 by okim              #+#    #+#             */
/*   Updated: 2020/11/29 09:34:31 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	if (!dst && !src)
		return (dst);
	i = 0;
	while (i < n)
	{
		*((char *)dst + sizeof(char) * i) = *((char *)src + sizeof(char) * i);
		i++;
	}
	return (dst);
}
