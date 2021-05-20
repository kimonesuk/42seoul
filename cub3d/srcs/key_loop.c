/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:27:16 by okim              #+#    #+#             */
/*   Updated: 2021/05/20 19:28:09 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		key_press(int keycode, t_map *map)
{
	if (keycode == 0 || keycode == 2)
		press_ad(keycode, map);
	if (keycode == 13 || keycode == 1)
		press_ws(keycode, map);
	if (keycode == 123 || keycode == 124)
		press_arrow(keycode, map);
	if (keycode == 53)
	{
		printf("window is stopped.\n");
		free(map->sp);
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
	free(map->mp.map);
	exit(0);
}

void	key_loop(t_map *map)
{
	mlx_hook(map->win, X_EVENT_KEY_PRESS, 0, key_press, map);
	mlx_hook(map->win, X_EVENT_KEY_RELEASE, 0, key_release, map);
	mlx_hook(map->win, X_EVENT_KEY_EXIT, 0, key_exit, map);
}
