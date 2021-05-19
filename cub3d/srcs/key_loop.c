/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:27:16 by okim              #+#    #+#             */
/*   Updated: 2021/05/19 18:24:08 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	press_key(int key, t_map *map)
{
	double			mspd;
	double			rspd;
	const double	oldirx = map->dirx;
	const double	oldplnx = map->planex;

	rspd = (key == 2) ? M_PI / 45 * -1 : M_PI / 45;
	mspd = (key == 1) ? -1 : 1;
	if (key == 0 || key == 2)
	{
		map->dirx = map->dirx * cos(-rspd) - map->diry * sin(-rspd);
		map->diry = oldirx * sin(-rspd) + map->diry * cos(-rspd);
		map->planex = map->planex * cos(-rspd) - map->planey * sin(-rspd);
		map->planey = oldplnx * sin(-rspd) + map->planey * cos(-rspd);
	}
	if (key == 13 || key == 1)
	{
		if (map->mp.map[(int)(map->mp.player_y)]
		[(int)(map->mp.player_x + map->dirx * mspd)] == '0')
			map->mp.player_x += map->dirx * mspd;
		if (map->mp.map[(int)(map->mp.player_y + map->diry * mspd)]
		[(int)(map->mp.player_x)] == '0')
			map->mp.player_y += map->diry * mspd;
	}
	draw_loop(map);
}

int		key_press(int keycode, t_map *map)
{
	if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13)
		press_key(keycode, map);
	if (keycode == 123 || keycode == 124)
		press_arrow(keycode, map);
	if (keycode == 53)
	{
		printf("window is stopped.\n");
		free(map->sp);
		free(map->distarr);
		free(map->mp.map);
		exit(0);
	}
	return (0);
}

int		key_release(int keycode, t_map *map)
{
	if (keycode == 123 || keycode == 124)
		release_arrow(keycode, map);
	return (0);
}

int		key_exit(t_map *map)
{
	printf("window is stopped.\n");
	free(map->sp);
	free(map->distarr);
	free(map->mp.map);
	exit(0);
}

void	key_loop(t_map *map)
{
	mlx_hook(map->win, X_EVENT_KEY_PRESS, 0, key_press, map);
	mlx_hook(map->win, X_EVENT_KEY_RELEASE, 0, key_release, map);
	mlx_hook(map->win, X_EVENT_KEY_EXIT, 0, key_exit, map);
}
