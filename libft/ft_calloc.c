/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 09:32:59 by okim              #+#    #+#             */
/*   Updated: 2020/11/23 19:57:01 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	int		i;

	if (!(ptr = malloc(count * size)))
		return (0);
	i = 0;
	while (i < count)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
