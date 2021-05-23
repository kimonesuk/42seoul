/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 09:41:22 by okim              #+#    #+#             */
/*   Updated: 2021/05/23 12:51:57 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

int		chk_slice(char **line, char **stored, int idx)
{
	char	*tmp;

	if ((*stored != 0) && (idx >= 0))
	{
		(*stored)[idx] = '\0';
		*line = ft_strdup(*stored);
		if (*(*stored + idx + 1) || *(*stored + idx + 1) == '\0')
			tmp = ft_strdup(*stored + idx + 1);
		else
			tmp = 0;
		free(*stored);
		*stored = tmp;
		return (1);
	}
	else if (*stored != 0)
	{
		*line = *stored;
		*stored = 0;
	}
	else
		*line = ft_strdup("");
	return (0);
}

int		idx_newline(const char *s)
{
	int	idx;

	idx = 0;
	while (s[idx])
	{
		if (s[idx] == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	char			buff[1024 + 1];
	static char		*stored[FD_MAX];
	int				readsize;
	int				idx;

	if ((fd < 0) || (line == 0) || (1024 <= 0))
		return (-1);
	while ((readsize = read(fd, buff, 1024)) > 0)
	{
		buff[readsize] = '\0';
		stored[fd] = ft_strjoin(stored[fd], buff);
		if ((idx = idx_newline(stored[fd])) >= 0)
			return (chk_slice(line, &stored[fd], idx));
	}
	if (readsize < 0)
		return (-1);
	buff[readsize] = '\0';
	stored[fd] = ft_strjoin(stored[fd], buff);
	idx = idx_newline(stored[fd]);
	return (chk_slice(line, &stored[fd], idx));
}
