/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@stundent.42seoul.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 20:35:38 by okim              #+#    #+#             */
/*   Updated: 2020/11/22 21:03:59 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (0);
	if (!(substr = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
