/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:42:58 by okim              #+#    #+#             */
/*   Updated: 2021/04/25 08:55:36 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	info_chk(t_mpinf *mpinf)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (mpinf->FL[i] > 255)
			return (error_msg(-2));
		if (mpinf->CL[i] > 255)
			return (error_msg(-2));
		i++;
	}
	if (mpinf->size[0] == 0 || mpinf->size[1] == 0 || mpinf->S_path == 0)
		return (error_msg(-2));
	if (mpinf->NO_path == 0 || mpinf->SO_path == 0 || mpinf->WE_path == 0 ||
	mpinf->EA_path == 0)
		return (error_msg(-2));
	return (0);
}

int	contents_nmb_save(char *line, t_mpinf *mpinf, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] != 0)
	{
		if (ft_isdigit(line[i]))
		{
			if (c == 'C')
				mpinf->CL[j] = mpinf->CL[j] * 10 + line[i] - '0';
			else if (c == 'F')
				mpinf->FL[j] = mpinf->FL[j] * 10 + line[i] - '0';
		}
		else if ((j < 3) && (line[i] = ','))
			j++;
		else
			return (-1);
		i++;
	}
	return (0);
}

int	contents_size_save(char *line, t_mpinf *mpinf)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i] != 0)
	{
		if (ft_isdigit(line[i]))
			mpinf->size[j] = mpinf->size[j] * 10 + line[i] - '0';
		else if ((j == 0) && (line[i] = ' '))
			j++;
		else
			return (-1);
		i++;
	}
	if (mpinf->size[0] >= mpinf->max_width)
		mpinf->size[0] = mpinf->max_width;
	if (mpinf->size[1] >= mpinf->max_length)
		mpinf->size[1] = mpinf->max_length;
	return (0);
}

int	elements_save(char *line, t_mpinf *mpinf)
{
	int	rtn;

	rtn = 0;
	if (ft_strncmp(line, "NO ", 3) == 0)
		mpinf->NO_path = ft_strdup((line + sizeof(char) * 3));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		mpinf->SO_path = ft_strdup((line + sizeof(char) * 3));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		mpinf->WE_path = ft_strdup((line + sizeof(char) * 3));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		mpinf->EA_path = ft_strdup((line + sizeof(char) * 3));
	else if (ft_strncmp(line, "S ", 2) == 0)
		mpinf->S_path = ft_strdup((line + sizeof(char) * 2));
	else if (ft_strncmp(line, "R ", 2) == 0)
		rtn = contents_size_save(line + sizeof(char) * 2, mpinf);
	else if (ft_strncmp(line, "F ", 2) == 0)
		rtn = contents_nmb_save(line + sizeof(char) * 2, mpinf, 'F');
	else if (ft_strncmp(line, "C ", 2) == 0)
		rtn = contents_nmb_save(line + sizeof(char) * 2, mpinf, 'C');
	else
		rtn = -1;
	free(line);
	if (rtn == -1)
		return (-1);
	return (1);
}

int	map_parsing(char *map_path, t_mpinf *mpinf)
{
	char	*line;
	char	*tmp;
	int		fd;

	if ((fd = open(map_path, O_RDONLY)) == -1)
		return (error_msg(-1));
	while (get_next_line(fd, &line) > 0)
	{
		tmp = skip_space(line);
		if (ft_strncmp(tmp, "1", 1) == 0)
			break ;
		else if (*tmp == 0)
			continue;
		else
		{
			if (elements_save(line, mpinf) == -1)
				return (error_msg(-2));
		}
	}
	mpinf->map_width = ft_strlen(line);
	mpinf->map_height++;
	mpinf->map_lst = ft_lstnew(line);
	if (map_save(fd, mpinf) == -1)
		return (-1);
	return (info_chk(mpinf));
}
