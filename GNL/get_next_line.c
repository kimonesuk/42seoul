/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 09:41:22 by okim              #+#    #+#             */
/*   Updated: 2021/02/03 12:25:49 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy_slice(char *str, size_t start, size_t end)
{
	size_t	size;
	size_t	idx;

	size = end - start + 1;
	idx = 0;
	if (start == 0)
		str = ft_strdup("");
	if (ft_strlen(str) > start && size > 1)
	{
		while (size-- && str[idx + start] != '\0')
		{
			str[idx] = str[idx + start];
			idx++;
		}
		while (str[idx])
		{
			str[idx] = '\0';
			idx++;
		}
	}
	return (str);
}

size_t	idx_newline(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx])
	{
		if (s[idx] == '\n')
			return (idx);
		idx++;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE];
	static char		*stored[FD_MAX];
	size_t			readsize;
	size_t			idx;

	if (fd == 2 || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	do
	{
		readsize = read(fd, buff, BUFFER_SIZE);
		buff[readsize] = '\0';
		stored[fd] = ft_strjoin(stored[fd], buff);
		if ((idx = idx_newline(stored[fd])) != 0)
		{
			*line = (char*)malloc(sizeof(char) * (idx + 2));
			ft_strlcpy(*line, stored[fd], idx + 1);
			ft_strcpy_slice(stored[fd], idx + 1, ft_strlen(stored[fd]));
			return (1);
		}
	} while (readsize > 0 || ft_strlen(stored[fd]) != 0)
	return (0);
}
