/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@stundent.42seoul.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 20:35:38 by okim              #+#    #+#             */
/*   Updated: 2020/11/21 21:06:52 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	unsigned int	i;

	substr = (char *)malloc(sizeof(char) * len);
	i = 0;
	while (i < len)
	{
		substr[i] = *((char *)s + start + i);
	}
	return (substr);
}
