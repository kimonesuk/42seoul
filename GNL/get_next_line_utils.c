/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 09:42:49 by okim              #+#    #+#             */
/*   Updated: 2021/02/01 23:32:10 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy_slice(char *buf, char *str, size_t start, size_t end)
{
	size_t	size;

	size = end - start + 1;
	if (ft_strlen(str) > start && size >= 0)
	{
		str += start;
		while (size-- && *str != '\0')
			*(buf++) = *(str++);
		*buf = '\0';
	}
	return buf;
}

size_t	have_end(const char	*str, size_t size)
{
	size_t	len;

	len = ft_strlen(str);
	if (len < size)
		return (len);
	else
		return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*jnstr;
	int		len1;
	int		len2;

	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(jnstr = (char*)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (0);
	ft_strlcpy(jnstr, s1, len + 1);
	free(s1);
	ft_strlcat(jnstr, s2, len1 + len2 + 1);
	return (jnstr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	i = 0;
	while (dstsize > 0)
	{
		while (--dstsize > 0 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dstsize == 0)
		return (src_len);
	while (src[i] != 0 && i + dst_len < dstsize - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dstsize >= dst_len + i)
		dst[dst_len + i] = 0;
	if (dst_len < dstsize)
		return (dst_len + src_len);
	return (dstsize + src_len);
}

char	*ft_strdup(const char *s1)
{
	char	*rtn;
	int		len;
	int		i;

	len = ft_strlen(s1);
	if (!(rtn = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		rtn[i] = s1[i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*(s++))
		len++;
	return (len);
}
