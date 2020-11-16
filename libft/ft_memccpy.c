/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 12:25:46 by okim              #+#    #+#             */
/*   Updated: 2020/11/16 17:12:55 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c ,size_t n)
{
	size_t	i;
	int *ptr = 0;

	i = 0;
	while (i < n)
	{
		*((char *)dst + sizeof(char) * i) = *((char *)src + sizeof(char) * i);
		if (*((char *)src + sizeof(char) * i) == c)
			return ((void *)((char *)dst + sizeof(char) * (i + 1)));
		i++;
	}
	return (ptr);
}
