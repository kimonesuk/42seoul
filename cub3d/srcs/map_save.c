/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_save.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 09:12:06 by okim              #+#    #+#             */
/*   Updated: 2021/04/24 22:30:02 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	map_content_chk(char *str)
{
	int i;
	int	ch;

	i = 0;
	ch = 0;
	while (i < ft_strlen(str))
	{
		if (ft_strchr(" 012NSEW", str[i]) == 0)
			return (-1);
		else if ((ch == 1) && (ft_strchr("NSEW", str[i]) != 0))
			return (-1);
		else if (ft_strchr("NSEW", str[i]) != 0)
			ch = 1;
		i++;
	}
	return (0);
}

int	map_line_chk(char **map, int x, int y)
{
	int	i;
	int	j;

	if (map[y][x] == '1' || map[y][x] == 'x')
		return (1);
	if (map[y][x] == ' ')
		return (-1);
	map[y][x] = 'x';
	j = -2;
	while (++j < 2)
	{
		i = -2;
		while (++i < 2)
		{
			if (map_line_chk(map, x + j, y + i) == -1)
				return (-1);
		}
	}
	return (1);
}

int	map_shape_chk(char **map, t_mpinf *mpinf)
{
	int	i;
	int	j;

	i = 0;
	while (i < mpinf->map_height)
	{
		j = 0;
		if (map_content_chk(mpinf->map[i]) == -1)
			return (error_msg(-3));
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
	char	**tmp_map;
	t_list	*tmp_lst;

	mpinf->map = (char **)malloc(sizeof(char *) * (mpinf->map_height));
	tmp_map = (char **)malloc(sizeof(char *) * (mpinf->map_height));
	tmp_lst = mpinf->map_lst;
	i = 0;
	while (tmp_lst != 0)
	{
		mpinf->map[i] = ft_strdup(tmp_lst->content);
		tmp_map[i++] = ft_strdup(tmp_lst->content);
		tmp_lst = tmp_lst->next;
	}
	ft_lstclear(&mpinf->map_lst);
	rtn = map_shape_chk(tmp_map, mpinf);
	i = -1;
	while (++i < mpinf->map_height)
		printf("%s\n", tmp_map[i]);
	i = -1;
	while (++i < mpinf->map_height)
		free(tmp_map[i]);
	free(tmp_map);
	return (rtn);
}

int	map_save(int fd, t_mpinf *mpinf)
{
	char	*line;
	t_list	*tmp_list;

	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strlen(line) > mpinf->map_width)
			mpinf->map_width = ft_strlen(line);
		mpinf->map_height++;
		tmp_list = ft_lstnew(ft_strdup(line));
		ft_lstadd_back(&mpinf->map_lst, tmp_list);
		free(line);
	}
	if (ft_strlen(line) > mpinf->map_width)
		mpinf->map_width = ft_strlen(line);
	mpinf->map_height++;
	tmp_list = ft_lstnew(ft_strdup(line));
	ft_lstadd_back(&mpinf->map_lst, tmp_list);
	free(line);
	return (lst_to_map(mpinf));
}
