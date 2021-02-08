/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 09:41:22 by okim              #+#    #+#             */
/*   Updated: 2021/02/09 00:54:21 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	chk_slice(char **line, char **stored, int idx)
{
	char	*tmp;
	
	//printf("stored : %s\n", *stored);
	if ((*stored != 0) && (idx >= 0))
	{
		printf("in if, idx : %d\n", idx);
		printf("stored len : %d\n", ft_strlen(*stored));
		(*stored)[idx] = '\0';
		//printf("cuted stored : %s\n", *stored);
		*line = ft_strdup(*stored);
		//printf("line : %s\n", *line);
		if (*(*stored + idx + 1))
			tmp = ft_strdup(*stored + idx + 1);
		else
			tmp = 0;
		free(*stored);
		*stored = tmp;
	//	printf("new stored : %s\n\n", *stored);
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

int	idx_newline(const char *s)
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

int	get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*stored[FD_MAX];
	int				readsize;
	int				idx;

	if ((fd < 0) || (line == 0) || (BUFFER_SIZE <= 0))
		return (-1);
	while ((readsize = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		//printf("readsize : %d\n", readsize);
		buff[readsize] = '\0';
		stored[fd] = ft_strjoin(stored[fd], buff);
		//printf("stored[fd] : %s\n-----end-----\n", stored[fd]);
		if ((idx = idx_newline(stored[fd])) >= 0)
			return (chk_slice(line, &stored[fd], idx));
	}
	if (readsize < 0)
		return (-1);
	idx = idx_newline(stored[fd]);
	return (chk_slice(line, &stored[fd], idx));
}
