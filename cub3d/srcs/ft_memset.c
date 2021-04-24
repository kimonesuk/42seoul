/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 09:57:06 by okim              #+#    #+#             */
/*   Updated: 2021/04/25 00:56:19 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	*ft_memset(char *b, int c, size_t len)
{
	b = (char *)malloc(sizeof(char) * len);
	while (len--)
		*((char *)b + (sizeof(char) * len)) = c;
	return (b);
}
