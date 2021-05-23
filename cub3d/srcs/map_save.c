/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_save.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 09:12:06 by okim              #+#    #+#             */
/*   Updated: 2021/05/23 16:48:45 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	map_content_chk(int j, t_mpinf *mpinf)
{
	int i;

	i = 0;
	while (i < ft_strlen(mpinf->map[j]))
	{
		if (ft_strchr(" 012NSEW", mpinf->map[j][i]) == 0)
			return (-1);
		if (mpinf->flag == 1 && (ft_strchr("NSEW", mpinf->map[j][i]) != 0))
			return (-1);
		else if (ft_strchr("NSEW", mpinf->map[j][i]) != 0)
		{
			mpinf->flag = 1;
			mpinf->player_x = i;
			mpinf->player_y = j;
			mpinf->player_v = mpinf->map[j][i];
			mpinf->map[j][i] = '0';
		}
		else if (mpinf->map[j][i] == '2')
			mpinf->spcnt++;
		i++;
	}
	return (0);
}

int	map_line_chk(char **map, int x, int y)
{
	int	i;
	int	j;

	if (map == 0 || map[y] == 0 || map[y][x] == 0)
		return (-1);
	if (map[y][x] == '1' || map[y][x] == 'x')
		return (1);
	if (map[y][x] == ' ')
		return (-1);
	map[y][x] = 'x';
	j = 2;
	while (--j > -2)
	{
		i = 2;
		while (--i > -2)
		{
			if (map_line_chk(map, x + i, y + j) == -1)
				return (-1);
		}
	}
	return (1);
}

int	map_shape_chk(char **map, t_mpinf *mpinf)
{
	int	i;
	int	j;

	i = 1;
	mpinf->flag = 0;
	while (i < mpinf->map_height)
	{
		if (map_content_chk(i, mpinf) == -1)
			return (error_msg(-3));
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			if (map[i][j] == '0')
			{
				if (map_line_chk(map, j, i) == -1)
					return (error_msg(-4));
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	lst_to_map(t_mpinf *mpinf)
{
	int		i;
	int		rtn;
	char	*frame;
	char	**tmp_map;
	t_list	*tmp_lst;

	mpinf->map = (char **)malloc(sizeof(char *) * (mpinf->map_height));
	tmp_map = (char **)malloc(sizeof(char *) * (mpinf->map_height + 2));
	frame = 0;
	frame = ft_memset(frame, ' ', mpinf->map_width);
	tmp_map[0] = frame;
	tmp_map[mpinf->map_height + 1] = frame;
	tmp_lst = mpinf->map_lst;
	i = 0;
	while (tmp_lst != 0)
	{
		mpinf->map[i] = ft_strdup(tmp_lst->content);
		tmp_map[1 + i++] = ft_strdup(tmp_lst->content);
		tmp_lst = tmp_lst->next;
	}
	ft_lstclear(&mpinf->map_lst);
	rtn = map_shape_chk(tmp_map, mpinf);
	free_map(mpinf, tmp_map);
	return (rtn);
}

int	map_save(int fd, t_mpinf *mpinf)
{
	char	*line;
	t_list	*tmp_list;

	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strlen(skip_space(line)) == 0)
			return (error_msg(-3));
		if (ft_strlen(line) > mpinf->map_width)
			mpinf->map_width = ft_strlen(line);
		mpinf->map_height++;
		tmp_list = ft_lstnew(line);
		ft_lstadd_back(&mpinf->map_lst, tmp_list);
	}
	if (ft_strlen(line) > mpinf->map_width)
		mpinf->map_width = ft_strlen(line);
	mpinf->map_height++;
	tmp_list = ft_lstnew(line);
	ft_lstadd_back(&mpinf->map_lst, tmp_list);
	line = 0;
	close(fd);
	return (lst_to_map(mpinf));
}
