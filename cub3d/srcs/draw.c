/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:39:54 by okim              #+#    #+#             */
/*   Updated: 2021/05/23 14:53:38 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_line(t_map *map)
{
	double	deltay;
	double	start;
	int		color;
	int		lineh;

	lineh = (int)(map->mp.size[1] / map->wdist);
	map->wstart = -(lineh / 2) + (map->mp.size[1] / 2);
	map->wend = (lineh / 2) + (map->mp.size[1] / 2);
	deltay = abs(map->wend - map->wstart);
	deltay /= fabs(deltay);
	start = map->wstart;
	while (fabs(map->wend - start) > 0.01)
	{
		if (start > 0 && start < map->mp.size[1] && start > map->wstart)
		{
			color = set_texture(map, start - map->wstart);
			my_mlx_pixel_put(&map->img, (int)floor(map->xi),
			(int)floor(start), color);
		}
		start += deltay;
	}
}

int		draw_ray(t_map *map)
{
	double	camerax;

	map->xi = 0;
	map->wdist = 0;
	map->distarr = (double *)malloc(sizeof(double) * map->mp.size[0]);
	while (map->xi < map->mp.size[0])
	{
		camerax = ((2 * map->xi) / (double)map->mp.size[0]) - 1;
		map->raydirx = map->dirx + map->planex * camerax;
		map->raydiry = map->diry + map->planey * camerax;
		cast_single_ray(map);
		map->distarr[map->xi] = map->wdist;
		draw_line(map);
		map->xi++;
	}
	return (0);
}

void	draw_back(t_map *map)
{
	int x;
	int y;

	y = 0;
	while (y < map->mp.size[1] / 2)
	{
		x = 0;
		while (x < map->mp.size[0])
		{
			my_mlx_pixel_put(&map->img, x, y, map->fl);
			x++;
		}
		y++;
	}
	while (y < map->mp.size[1])
	{
		x = 0;
		while (x < map->mp.size[0])
		{
			my_mlx_pixel_put(&map->img, x, y, map->cl);
			x++;
		}
		y++;
	}
}

void	draw_loop(t_map *map)
{
	draw_back(map);
	draw_ray(map);
	draw_sprite(map);
	free(map->distarr);
	if (map->mp.save == 1)
	{
		save_bmp(map);
		mlx_destroy_window(map->mlx, map->win);
		printf("bmp is saved\n");
	}
	else
		mlx_put_image_to_window(map->mlx, map->win, map->img.img, 0, 0);
}
