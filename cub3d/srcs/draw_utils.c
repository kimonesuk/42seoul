/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 09:24:36 by okim              #+#    #+#             */
/*   Updated: 2021/05/23 13:51:11 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_delta(t_map *map)
{
	map->mapx = (int)map->mp.player_x;
	map->mapy = (int)map->mp.player_y;
	if (map->raydiry == 0)
		map->deltax = 0;
	else
	{
		if (map->raydirx == 0)
			map->deltax = 1;
		else
			map->deltax = fabs(1 / map->raydirx);
	}
	if (map->raydirx == 0)
		map->deltay = 0;
	else
	{
		if (map->raydiry == 0)
			map->deltay = 1;
		else
			map->deltay = fabs(1 / map->raydiry);
	}
}

void	set_stepside(t_map *map)
{
	if (map->raydirx < 0)
	{
		map->stepx = -1;
		map->sidex = (map->mp.player_x - map->mapx) * map->deltax;
	}
	else
	{
		map->stepx = 1;
		map->sidex = (map->mapx + 1.0 - map->mp.player_x) * map->deltax;
	}
	if (map->raydiry < 0)
	{
		map->stepy = -1;
		map->sidey = (map->mp.player_y - map->mapy) * map->deltay;
	}
	else
	{
		map->stepy = 1;
		map->sidey = (map->mapy + 1.0 - map->mp.player_y) * map->deltay;
	}
}

double	ray2wall(t_map *map)
{
	if (map->side == 0)
		map->wdist = (map->mapx - map->mp.player_x +
		(1 - map->stepx) / 2) / map->raydirx;
	else
		map->wdist = (map->mapy - map->mp.player_y +
		(1 - map->stepy) / 2) / map->raydiry;
	return (map->wdist);
}

double	cast_single_ray(t_map *map)
{
	int	i;

	i = 0;
	set_delta(map);
	set_stepside(map);
	map->hit = 0;
	while (map->hit == 0)
	{
		if (map->sidex < map->sidey)
		{
			map->sidex += map->deltax;
			map->mapx += map->stepx;
			map->side = 0;
		}
		else
		{
			map->sidey += map->deltay;
			map->mapy += map->stepy;
			map->side = 1;
		}
		if (map->mp.map[map->mapy][map->mapx] == '1')
			map->hit = 1;
	}
	return (ray2wall(map));
}

void	free_map(t_mpinf *mpinf, char **tmp_map)
{
	int i;

	i = 0;
	while (i < mpinf->map_height + 1)
	{
		free(tmp_map[i]);
		i++;
	}
	free(tmp_map);
}
