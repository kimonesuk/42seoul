/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 09:41:22 by okim              #+#    #+#             */
/*   Updated: 2021/02/01 10:42:05 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE];
//	static char	store[BUFFER_SIZE] = "";
//	size_t		idx;

	*line = (char*)malloc(BUFFER_SIZE + 1);
	if (fd == 2 || BUFFER_SIZE <= 0 || read(fd, buff, BUFFER_SIZE) == -1)
		return (-1);
	if (read(fd, buff, BUFFER_SIZE) == 0)
	{
		//strcpy(*line, store);
		//strcpy(*line, buff);
		printf("read = 0 : %s\n", buff);
		return (0);
	}
	else
	{
		read(fd, buff, BUFFER_SIZE);
		printf("read != 0 : %s\n", buff);
		//strcpy(*line, store);
		//strcpy(store, buff);
		/*while ((idx = have_end(store, BUFFER_SIZE)) != 0)
		{
			strcpy(*line, store);
			read(fd, buff, BUFFER_SIZE);
			strcpy(store, buff);
		}*/
		//strncat(*line, store, idx);
		//ft_strcpy_slice(store, buff, idx, BUFFER_SIZE);
		return (1);
	}
}
