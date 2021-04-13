/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:42:58 by okim              #+#    #+#             */
/*   Updated: 2021/04/14 01:52:07 by okim             ###   ########.fr       */
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
	char	*line_end = 0;
	char	*line_eend = 0;
	char	*ptr = 0;
	int		ret;
	int		fd;
	int		map_height;
	char	**tmp_map;

	if ((fd = open(map_path, O_RDONLY)) == -1)
	{
		write(1, "Invalid file path\n",18);
		return (-1);
	}
	map_height = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ptr = skip_space(line);
		if (ft_strncmp(ptr, "NO", 2) == 0)
		{
			ptr += sizeof(char) * 2;
			ptr = skip_space(ptr);
			mpinf->NO_path = ft_strdup(ptr);
		}
		else if (ft_strncmp(ptr, "SO", 2) == 0)
		{
			ptr = ptr + sizeof(char) * 2;
			ptr = skip_space(ptr);
			mpinf->SO_path = ft_strdup(ptr);
		}
		else if (ft_strncmp(ptr, "WE", 2) == 0)
		{
			ptr = ptr + sizeof(char) * 2;
			ptr = skip_space(ptr);
			mpinf->WE_path = ft_strdup(ptr);
		}
		else if (ft_strncmp(ptr, "EA", 2) == 0)
		{
			ptr = ptr + sizeof(char) * 2;
			ptr = skip_space(ptr);
			mpinf->EA_path = ft_strdup(ptr);
		}
		else if (ft_strncmp(ptr, "S", 1) == 0)
		{
			ptr = ptr + sizeof(char) * 1;
			ptr = skip_space(ptr);
			mpinf->S_path = ft_strdup(ptr);
		}
		else if (ft_strncmp(ptr, "R", 1) == 0)
		{
			ptr = ptr + sizeof(char) * 1;
			ptr = skip_space(ptr);
			line_end = ft_strchr(ptr, ' ');
			mpinf->width = ft_atoi(ft_substr(ptr, 0, line_end - ptr));
			mpinf->length = ft_atoi(line_end + sizeof(char) * 1);
			// if (mpinf->width >= max)
			// 	mpinf->width = max;
			// if (mpinf->length >= max)
			// 	mpinf->length = max;
		}
		else if (ft_strncmp(ptr, "F", 1) == 0)
		{
			ptr = ptr + sizeof(char) * 1;
			ptr = skip_space(ptr);
			line_end = ft_strchr(ptr, ',') + sizeof(char) * 1;
			line_eend = ft_strchr(line_end, ',') + sizeof(char) * 1;
			mpinf->FL[0] = ft_atoi(ft_substr(ptr, 0, line_end - ptr));
			mpinf->FL[1] = ft_atoi(ft_substr(line_end, 0, line_eend - line_end));
			mpinf->FL[2] = ft_atoi(line_eend);
		}
		else if (ft_strncmp(ptr, "C", 1) == 0)
		{
			ptr = ptr + sizeof(char) * 1;
			ptr = skip_space(ptr);
			line_end = ft_strchr(ptr, ',') + sizeof(char) * 1;
			line_eend = ft_strchr(line_end, ',') + sizeof(char) * 1;
			mpinf->CL[0] = ft_atoi(ft_substr(ptr, 0, line_end - ptr));
			mpinf->CL[1] = ft_atoi(ft_substr(line_end, 0, line_eend - line_end));
			mpinf->CL[2] = ft_atoi(line_eend);
		}
		else if (ft_strncmp(ptr, "1", 1) == 0)
		{
			mpinf->map_width = ft_strlen(line);
			tmp_map = (char **)malloc(sizeof(char *) * 255);
			tmp_map[map_height++] = ft_strdup(line);
			break ;
		}
		else if (*ptr == 0)
			continue ;
		else
		{
			write(1, "Invalid map contents.\n", 22);
			return (-1);
		}
		free(line);
	}
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (ft_strlen(line) > mpinf->map_width)
			mpinf->map_width = ft_strlen(line);
		tmp_map[map_height++] = ft_strdup(line);
		free(line);
	}
	if (ft_strlen(line) > mpinf->map_width)
		mpinf->map_width = ft_strlen(line);
	tmp_map[map_height] = ft_strdup(line);
	mpinf->map_height = map_height;
	mpinf->map = (char**)malloc(sizeof(char *) * (map_height + 1));
	mpinf->map[map_height] = tmp_map[map_height];
	while (map_height-- > 0)
		mpinf->map[map_height] = tmp_map[map_height];
	free(line);
	free(tmp_map);
	printf("width : %d\nlength : %d\nmap_height : %d\nmap_width : %d\nFL : %d %d %d\nCL : %d %d %d\n", mpinf->width, mpinf->length, mpinf->map_height, mpinf->map_width, mpinf->FL[0], mpinf->FL[1], mpinf->FL[2], mpinf->CL[0], mpinf->CL[1], mpinf->CL[2]);
	printf("NO : %s\nSO : %s\nWE : %s\nEA : %s\nS : %s\n", mpinf->NO_path, mpinf->SO_path, mpinf->WE_path, mpinf->EA_path, mpinf->S_path);
	for (int i = 0; i < mpinf->map_height; i++)
		printf("%s\n", mpinf->map[i]);
	return (0);
}