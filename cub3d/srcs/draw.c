/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:39:54 by okim              #+#    #+#             */
/*   Updated: 2021/05/20 08:00:49 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
		map->wdist = (map->mapx - map->mp.player_x + (1 - map->stepx) / 2) / map->raydirx;
	else
		map->wdist = (map->mapy - map->mp.player_y + (1 - map->stepy) / 2) / map->raydiry;
	return (map->wdist);
}

double	cast_single_ray(t_map *map)
{
	int	i;

	i = 0;
	map->mapx = (int)map->mp.player_x;
	map->mapy = (int)map->mp.player_y;
	map->deltax = (map->raydiry == 0) ? 0 : (map->raydirx == 0) ? 1 : fabs(1 / map->raydirx);
	map->deltay = (map->raydirx == 0) ? 0 : (map->raydiry == 0) ? 1 : fabs(1 / map->raydiry);
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

void	dist2wall(t_map *map)
{
	int	lineHeight;

	lineHeight = (int)(map->mp.size[1] / map->wdist);
	map->wstart = -(lineHeight / 2) + (map->mp.size[1] / 2);
	if (map->wstart < 0)
		map->wstart = 0;
	map->wend = (lineHeight / 2) + (map->mp.size[1] / 2);
	if (map->wend >= map->mp.size[1])
		map->wend = map->mp.size[1] - 1;
}

int		setTexture(t_map *map, double dy)
{
	int		color;
	int		texX;
	int		texY;
	double	wallX;
	double	wallY;

	color = -1;
	if (map->side == 0)	wallX = map->mp.player_y + map->wdist * map->raydiry;
	else	wallX = map->mp.player_x + map->wdist * map->raydirx;
	wallX -= floor(wallX);
	wallY = dy / abs(map->wend - map->wstart);
	if (map->side == 0 && map->raydirx < 0) // east
	{
		texX = (int)((1 - wallX) * map->ea_w);
		texY = (int)(wallY * map->ea_h);
		color = my_mlx_pixel_get(&map->ea_img, texX, texY);
	}
	else if (map->side == 0 && map->raydirx >= 0) // west
	{
		texX = (int)(wallX * map->we_w);
		texY = (int)(wallY * map->we_h);
		color = my_mlx_pixel_get(&map->we_img, texX, texY);
	}
	else if (map->side == 1 && map->raydiry < 0) // south
	{
		texX = (int)(wallX * map->so_w);
		texY = (int)(wallY * map->so_h);
		color = my_mlx_pixel_get(&map->so_img, texX, texY);
	}
	else if (map->side == 1 && map->raydiry >= 0) // north
	{
		texX = (int)((1 - wallX) * map->no_w);
		texY = (int)(wallY * map->no_h);
		color = my_mlx_pixel_get(&map->no_img, texX, texY);
	}
	else
		color = 0;
	return (color);
}

void	draw_line(t_map *map)
{
	double	deltaY;
	double	start;
	int		color;

	start = map->wstart;
	deltaY = map->wend - map->wstart;
	deltaY /= fabs(deltaY);
	while (fabs(map->wend - start) > 0.01)
	{
		color = setTexture(map, start - map->wstart);
		my_mlx_pixel_put(&map->img, (int)floor(map->xi), (int)floor(start), color);
		start += deltaY;
	}
}

int		draw_ray(t_map *map)
{
	double	cameraX;
	
	map->xi = 0;
	map->wdist = 0;
	map->distarr = (double *)malloc(sizeof(double) * map->mp.size[0]);
	while (map->xi < map->mp.size[0])
	{
		cameraX = ((2 * map->xi) / (double)map->mp.size[0]) - 1;
		map->raydirx = map->dirx + map->planex * cameraX;
		map->raydiry = map->diry + map->planey * cameraX;
		cast_single_ray(map);
		dist2wall(map);
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
	if (map->mp.save == 1)
	{
		mlx_clear_window(map->mlx, map->win);
		save_bmp(map);
		printf("bmp is saved\n");
	}
	else
		mlx_put_image_to_window(map->mlx, map->win, map->img.img, 0, 0);
}
// 화면 높이보다 큰 경우 문제가 생김