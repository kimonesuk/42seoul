/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:32:37 by okim              #+#    #+#             */
/*   Updated: 2021/05/23 16:50:31 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	press_arrow(int key, t_map *map)
{
	double			rspd;
	const double	oldirx = map->dirx;
	const double	oldplnx = map->planex;

	rspd = (key == 124) ? M_PI / 45 * -1 : M_PI / 45;
	map->dirx = map->dirx * cos(-rspd) - map->diry * sin(-rspd);
	map->diry = oldirx * sin(-rspd) + map->diry * cos(-rspd);
	map->planex = map->planex * cos(-rspd) - map->planey * sin(-rspd);
	map->planey = oldplnx * sin(-rspd) + map->planey * cos(-rspd);
	draw_loop(map);
}

void	press_ws(int key, t_map *map)
{
	double			mspd;

	mspd = (key == 1) ? -1 : 1;
	if (map->mp.map[(int)(map->mp.player_y)]
	[(int)(map->mp.player_x + map->dirx * mspd)] == '0')
		map->mp.player_x += map->dirx * mspd;
	if (map->mp.map[(int)(map->mp.player_y + map->diry * mspd)]
	[(int)(map->mp.player_x)] == '0')
		map->mp.player_y += map->diry * mspd;
	draw_loop(map);
}

void	press_ad(int key, t_map *map)
{
	double			mspd;

	mspd = (key == 2) ? -1 : 1;
	if (map->mp.map[(int)(map->mp.player_y)]
	[(int)(map->mp.player_x + map->diry * mspd)] == '0')
		map->mp.player_x += map->diry * mspd;
	if (map->mp.map[(int)(map->mp.player_y - map->dirx * mspd)]
	[(int)(map->mp.player_x)] == '0')
		map->mp.player_y -= map->dirx * mspd;
	draw_loop(map);
}
