/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 22:41:39 by okim              #+#    #+#             */
/*   Updated: 2020/11/26 11:23:50 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n_len;
	size_t	h_len;

	if (*needle == 0)
		return ((char *)haystack);
	n_len = ft_strlen(needle);
	h_len = ft_strlen(haystack);
	if (len < n_len || h_len < n_len)
		return (0);
	while (len-- >= n_len)
	{
		if (ft_memcmp((char *)haystack, needle, n_len) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}
