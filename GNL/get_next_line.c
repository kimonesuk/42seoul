/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 09:41:22 by okim              #+#    #+#             */
/*   Updated: 2021/02/02 00:02:47 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE];
	static char	*stored[OPEN_MAX];
	size_t		readsize;
	size_t		idx;

	if (fd == 2 || fd < 0 || BUFFER_SIZE <= 0 || read(fd, buff, BUFFER_SIZE) == -1)
		return (-1);
	while ((readsize = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[readsize] = '\0';
		stored[fd] = ft_strjoin(stored[fd], buff);
		if ((idx = idx_newline(stored[fd])) != 0)
		{
			*line = (char*)malloc(sizeof(char) * (idx));
			strlcpy(*line, stored[fd], idx);
			ft_slpit(stored[fd], idx, ft_strlen(stored[fd]);
			return (readsize == 0 ? 0 : 1);
		}
	}
	return (readsize == 0 ? 0 : 1);
}
