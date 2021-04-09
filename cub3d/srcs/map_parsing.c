/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:42:58 by okim              #+#    #+#             */
/*   Updated: 2021/04/08 01:20:23 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*skip_space(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] == ' ')
		i++;
	return (&str[i]);
}

int	map_parsing(char *map_path, t_mpinf *mpinf)
{
	char	*line = 0;
	int		ret;
	int		fd;
	int		maze;

	maze = 0;
	if ((fd = open(map_path, O_RDONLY)) == -1)
	{
		write(1, "Invalid file path\n",18);
		return (-1);
	}
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		line = skip_space(line);
		if (maze == 0 && ft_strncmp(line, "NO", 2) == 0)
		{

		}
		else if (maze == 0 && ft_strncmp(line, "SO", 2) == 0)
		{

		}
		else if (maze == 0 && ft_strncmp(line, "WE", 2) == 0)
		{

		}
		else if (maze == 0 && ft_strncmp(line, "EA", 2) == 0)
		{

		}
		else if (maze == 0 && ft_strncmp(line, "S", 1) == 0)
		{

		}
		else if (maze == 0 && ft_strncmp(line, "R", 1) == 0)
		{

		}
		else if (maze == 0 && ft_strncmp(line, "F", 1) == 0)
		{

		}
		else if (maze == 0 && ft_strncmp(line, "C", 1) == 0)
		{

		}
		else if (maze == 0 && ft_strncmp(line, "1", 1) == 0)
		{
			maze = 1;
		}
		else if (maze == 1)
		{

		}
		else
		{
			write(1, "Invalid map contents.\n", 22);
			return (-1);
		}
		free(line);
	}
	printf("%s\n", line);
	mpinf->width = 500;
	free(line);
	return (0);
}