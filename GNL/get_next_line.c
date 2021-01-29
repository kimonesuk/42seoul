/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 09:41:22 by okim              #+#    #+#             */
/*   Updated: 2021/01/29 09:42:01 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char	buff[BUFFER_SIZE];
	
	if (fd == 2)
		return (-1);
	else
	{
		if (read(fd, buff, BUFFER_SIZE) == -1)
			return (-1);
		else if (read(fd, buff, BUFFER_SIZE) == 0)
			return (0);
		else
		{

		}
	}
}
