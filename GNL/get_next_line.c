/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 09:41:22 by okim              #+#    #+#             */
/*   Updated: 2021/01/30 16:51:03 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE];
	static char	store[BUFFER_SIZE];
	size_t		idx;
	
	if (fd == 2 || BUFFER_SIZE <= 0 || read(fd, buff, BUFFER_SIZE) == -1)
		return (-1);
	else
	{
		if (read(fd, buff, BUFFER_SIZE) == 0)
		{
			strcpy(*line, store);
			strcat(*line, buff);
			return (0);
		}
		else
		{
			strcpy(*line, store);
			strcpy(store, buff);
			while ((idx = have_end(store, BUFFER_SIZE)) != 0)
			{
				strcat(*line, store);
				read(fd, buff, BUFFER_SIZE);
				strcpy(store, buff);
			}
			strncat(*line, store, idx);
			ft_strcpy_slice(store, buff, idx, BUFFER_SIZE);
			return (1);
		}
	}
}
