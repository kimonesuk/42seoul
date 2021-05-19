/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:32:37 by okim              #+#    #+#             */
/*   Updated: 2021/05/19 15:47:07 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	press_arrow(int key, t_map *map)
{
	double	rspd;
	double	oldirx;
	double	oldplanex;
	int		i;

	rspd = M_PI / 45;
	if (map->pressed == 1)
		return ;
	i = 0;
	if (key == 124)
		rspd *= -1;
	while (fabs(i * rspd) < M_PI / 6)
	{
		oldirx = map->dirx;
		oldplanex = map->planex;
		map->dirx = map->dirx * cos(-rspd) - map->diry * sin(-rspd);
		map->diry = oldirx * sin(-rspd) + map->diry * cos(-rspd);
		map->planex = map->planex * cos(-rspd) - map->planey * sin(-rspd);
		map->planey = oldplanex * sin(-rspd) + map->planey * cos(-rspd);
		draw_loop(map);
		i++;
	}
	map->pressed = 1;
}

void	release_arrow(int key, t_map *map)
{
	double	rspd;
	double	oldirx;
	double	oldplanex;
	int		i;

	rspd = M_PI / 45;
	if (map->pressed == 0)
		return ;
	i = 0;
	if (key == 124)
		rspd *= -1;
	while (fabs(i * rspd) < M_PI / 6)
	{
		oldirx = map->dirx;
		oldplanex = map->planex;
		map->dirx = map->dirx * cos(rspd) - map->diry * sin(rspd);
		map->diry = oldirx * sin(rspd) + map->diry * cos(rspd);
		map->planex = map->planex * cos(rspd) - map->planey * sin(rspd);
		map->planey = oldplanex * sin(rspd) + map->planey * cos(rspd);
		draw_loop(map);
		i++;
	}
	map->pressed = 0;
}
