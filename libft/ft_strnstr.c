/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 22:41:39 by okim              #+#    #+#             */
/*   Updated: 2020/11/17 23:12:33 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h_len;
	size_t	n_len;
	size_t	i;

	if (*needle == 0)
		return ((char *)haystack);
	h_len = ft_strlen(haystack);
	n_len = ft_strlen(needle);
	if (h_len < len || len < n_len)
		return (0);
	i = 0;
	while (haystack[i] != 0 && i < len)
	{
		if (ft_memcmp((char *)haystack + i, needle, n_len) == 0)
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
