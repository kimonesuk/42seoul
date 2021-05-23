/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:22:09 by okim              #+#    #+#             */
/*   Updated: 2021/05/23 10:32:53 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	dist_sprites(t_map *map)
{
	int	i;

	i = 0;
	map->sp_dist = (double *)malloc(sizeof(double) * map->mp.spcnt);
	while (i < map->mp.spcnt)
	{
		map->sp_dist[i] = pow((map->mp.player_x - map->sp[i].x), 2)
		+ pow((map->mp.player_y - map->sp[i].y), 2);
		i++;
	}
}

void	sort_sprites(t_map *map)
{
	int			i;
	int			j;
	int			tmp;
	t_sprite	tmpp;

	i = 0;
	while (i < map->mp.spcnt)
	{
		j = 0;
		while (j < map->mp.spcnt - i - 1)
		{
			if (map->sp_dist[j] < map->sp_dist[j + 1])
			{
				tmp = map->sp_dist[j];
				tmpp = map->sp[j];
				map->sp_dist[j] = map->sp_dist[j + 1];
				map->sp[j] = map->sp[j + 1];
				map->sp_dist[j + 1] = tmp;
				map->sp[j + 1] = tmpp;
			}
			j++;
		}
		i++;
	}
}

void	init_sprd(t_sprd *sd, t_map *map, int i)
{
	sd->invd = 1.0 / (map->planex * map->diry - map->dirx * map->planey);
	sd->sprx = map->sp[i].x - map->mp.player_x;
	sd->spry = map->sp[i].y - map->mp.player_y;
	sd->transx = sd->invd * (map->diry * sd->sprx - map->dirx * sd->spry);
	sd->transy = sd->invd * (-map->planey * sd->sprx + map->planex * sd->spry);
	sd->sprsnx = (int)((map->mp.size[0] / 2) * (1 + sd->transx / sd->transy));
	sd->sprh = (int)(map->mp.size[1] / (sd->transy));
	sd->starty = -sd->sprh / 2 + map->mp.size[1] / 2;
	if (sd->starty < 0)
		sd->starty = 0;
	sd->endy = sd->sprh / 2 + map->mp.size[1] / 2;
	if (sd->endy >= map->mp.size[1])
		sd->endy = map->mp.size[1] - 1;
	sd->sprw = (int)(map->mp.size[1] / (sd->transy));
	sd->startx = -sd->sprw / 2 + sd->sprsnx;
	if (sd->startx < 0)
		sd->startx = 0;
	sd->endx = sd->sprw / 2 + sd->sprsnx;
	if (sd->endx >= map->mp.size[0])
		sd->endx = map->mp.size[0] - 1;
	sd->stripe = sd->startx;
}

void	get_sprite_color(t_sprd *sd, t_map *map)
{
	sd->texy = (int)((sd->y * 2 + sd->sprh - map->mp.size[1])
	* map->sp_h / sd->sprh / 2);
	sd->color = my_mlx_pixel_get(&map->s_img, sd->texx, sd->texy);
	if ((sd->color & 0x00FFFFFF) != 0)
		my_mlx_pixel_put(&map->img, (int)floor(sd->stripe),
		(int)floor(sd->y), sd->color);
	sd->y++;
}

void	draw_sprite(t_map *map)
{
	int		i;
	t_sprd	sd;

	dist_sprites(map);
	sort_sprites(map);
	i = 0;
	while (i < map->mp.spcnt)
	{
		init_sprd(&sd, map, i);
		while (sd.stripe < sd.endx)
		{
			sd.texx = (int)((sd.stripe - (-sd.sprw / 2 + sd.sprsnx))
			* map->sp_w / sd.sprw);
			sd.y = sd.endy;
			if (sd.transy > 0 && sd.stripe > 0 && sd.stripe <
			map->mp.size[0] && sd.transy < map->distarr[sd.stripe])
				sd.y = sd.starty;
			while (sd.y < sd.endy)
				get_sprite_color(&sd, map);
			sd.stripe++;
		}
		i++;
	}
	free(map->sp_dist);
}
