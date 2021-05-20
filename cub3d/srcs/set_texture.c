/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:16:09 by okim              #+#    #+#             */
/*   Updated: 2021/05/20 20:23:27 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_color(t_map *map)
{
	if (map->side == 0 && map->raydirx < 0)
	{
		map->texx = (int)((1 - map->wallx) * map->ea_w);
		map->texy = (int)(map->wally * map->ea_h);
		map->color = my_mlx_pixel_get(&map->ea_img, map->texx, map->texy);
	}
	else if (map->side == 0 && map->raydirx >= 0)
	{
		map->texx = (int)(map->wallx * map->we_w);
		map->texy = (int)(map->wally * map->we_h);
		map->color = my_mlx_pixel_get(&map->we_img, map->texx, map->texy);
	}
	else if (map->side == 1 && map->raydiry < 0)
	{
		map->texx = (int)(map->wallx * map->so_w);
		map->texy = (int)(map->wally * map->so_h);
		map->color = my_mlx_pixel_get(&map->so_img, map->texx, map->texy);
	}
	else if (map->side == 1 && map->raydiry >= 0)
	{
		map->texx = (int)((1 - map->wallx) * map->no_w);
		map->texy = (int)(map->wally * map->no_h);
		map->color = my_mlx_pixel_get(&map->no_img, map->texx, map->texy);
	}
}

int		set_texture(t_map *map, double dy)
{
	map->color = -1;
	if (map->side == 0)
		map->wallx = map->mp.player_y + map->wdist * map->raydiry;
	else
		map->wallx = map->mp.player_x + map->wdist * map->raydirx;
	map->wallx -= floor(map->wallx);
	map->wally = dy / abs(map->wend - map->wstart);
	set_color(map);
	return (map->color);
}
