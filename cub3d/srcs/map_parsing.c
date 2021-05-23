/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:42:58 by okim              #+#    #+#             */
/*   Updated: 2021/05/23 10:21:12 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	info_chk(t_mpinf *mpinf)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (mpinf->fl[i] > 255 || mpinf->fl[i] == -1)
			return (error_msg(-2));
		if (mpinf->cl[i] > 255 || mpinf->cl[i] == -1)
			return (error_msg(-2));
		i++;
	}
	if (mpinf->size[0] == 0 || mpinf->size[1] == 0 || mpinf->s_path == 0
	|| mpinf->no_path == 0 || mpinf->so_path == 0 || mpinf->we_path == 0 ||
	mpinf->ea_path == 0 || mpinf->player_v == 0)
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
			if (c == 'C' && mpinf->cl[j] == -1)
				mpinf->cl[j] = 0;
			if (c == 'F' && mpinf->fl[j] == -1)
				mpinf->fl[j] = 0;
			if (c == 'C')
				mpinf->cl[j] = mpinf->cl[j] * 10 + line[i] - '0';
			else if (c == 'F')
				mpinf->fl[j] = mpinf->fl[j] * 10 + line[i] - '0';
		}
		else if (j < 3 && (line[i] == ','))
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
		else if ((j < 1) && (line[i] = ' '))
			j++;
		else
			return (-1);
		i++;
	}
	return (0);
}

int	elements_save(char *line, t_mpinf *mpinf)
{
	int	rtn;

	rtn = 0;
	if (ft_strncmp(line, "NO ", 3) == 0)
		mpinf->no_path = ft_strdup((line + sizeof(char) * 3));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		mpinf->so_path = ft_strdup((line + sizeof(char) * 3));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		mpinf->we_path = ft_strdup((line + sizeof(char) * 3));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		mpinf->ea_path = ft_strdup((line + sizeof(char) * 3));
	else if (ft_strncmp(line, "S ", 2) == 0)
		mpinf->s_path = ft_strdup((line + sizeof(char) * 2));
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
