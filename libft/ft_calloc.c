/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 09:32:59 by okim              #+#    #+#             */
/*   Updated: 2020/11/19 09:59:59 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	*ptr;

	if (!(ptr = (size_t *)malloc(count * size)))
		return (NULL);
	for(size_t i = 0; i < count; i++)
		ptr[i] = 0;
	return ((void *)ptr);
}
