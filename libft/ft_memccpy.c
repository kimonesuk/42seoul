/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 12:25:46 by okim              #+#    #+#             */
/*   Updated: 2020/11/29 09:33:32 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*srce;

	dest = (unsigned char *)dst;
	srce = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest[i] = srce[i];
		if (srce[i] == (unsigned char)c)
			return ((void *)(&dest[i + 1]));
		i++;
	}
	return (0);
}
