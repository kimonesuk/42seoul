/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 22:23:11 by okim              #+#    #+#             */
/*   Updated: 2020/11/26 10:43:40 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	s_len;

	s_len = ft_strlen(s);
	while (s_len)
	{
		if (s[s_len] == c)
			return ((char *)s + sizeof(char) * s_len);
		s_len--;
	}
	if (s[0] == c)
		return ((char *)s);
	return (0);
}
