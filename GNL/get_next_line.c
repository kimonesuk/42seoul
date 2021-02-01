/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 09:41:22 by okim              #+#    #+#             */
/*   Updated: 2021/02/01 16:56:17 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*stored[OPEN_MAX];
	size_t		readsize;
	size_t		idx;

	*line = (char*)malloc(BUFFER_SIZE + 1);
	if (fd == 2 || fd < 0 || BUFFER_SIZE <= 0 || read(fd, buff, BUFFER_SIZE) == -1)
		return (-1);
	while ((readsize = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[readsize] = '\0';
		//strcpy(*line, store);
		//strcpy(*line, buff);
		return (0);
	}

}
