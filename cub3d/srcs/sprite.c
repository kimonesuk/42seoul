/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:22:09 by okim              #+#    #+#             */
/*   Updated: 2021/05/19 14:22:22 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_sprite(t_map *map)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	map->sp_dist = (double *)malloc(sizeof(double) * map->mp.spcnt);
	while (i < map->mp.spcnt) // 플레이어 ~ 스프라이트 길이
	{
		map->sp_dist[i] = pow((map->mp.player_x - map->sp[i].x), 2) + pow((map->mp.player_y - map->sp[i].y), 2);
		i++;
	}
	i = 0; // 정렬
	while (i < map->mp.spcnt)
	{
		j = 0;
		while (j < map->mp.spcnt - i - 1)
		{
			if (map->sp_dist[j] > map->sp_dist[j + 1])
			{
				tmp = map->sp_dist[j];
				map->sp_dist[j] = map->sp_dist[j + 1];
				map->sp_dist[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	for(int i = 0; i < map->mp.spcnt; i++)
	{
		double spriteX = map->sp[i].x - map->mp.player_x; // 스프라이트의 상대적 위치 x
		double spriteY = map->sp[i].y - map->mp.player_y; // 스프라이트의 상대적 위치 y
		double invDet = 1.0 / (map->planex * map->diry - map->dirx * map->planey);
		double transformX = invDet * (map->diry * spriteX - map->dirx * spriteY); // 화면평면에 투사된 x
		double transformY = invDet * (-map->planey * spriteX + map->planex * spriteY); // 화면평면에 투사된 y
		int spriteScreenX = (int)((map->mp.size[0] / 2) * (1 + transformX / transformY));
		int spriteHeight = abs((int)(map->mp.size[1] / (transformY))); // 스프라이트의 높이
		int drawStartY = -spriteHeight / 2 + map->mp.size[1] / 2;
		if (drawStartY < 0) drawStartY = 0;
		int drawEndY = spriteHeight / 2 + map->mp.size[1] / 2;
		if (drawEndY >= map->mp.size[1]) drawEndY = map->mp.size[1] - 1;

		int spriteWidth = abs((int)(map->mp.size[1] / (transformY)));
		int drawStartX = -spriteWidth / 2 + spriteScreenX;
		if(drawStartX < 0) drawStartX = 0;
		int drawEndX = spriteWidth / 2 + spriteScreenX;
		if(drawEndX >= map->mp.size[0]) drawEndX = map->mp.size[0] - 1;

		for(int stripe = drawStartX; stripe < drawEndX; stripe++)
		{
			int texX = (int)((stripe - (-spriteWidth / 2 + spriteScreenX)) * map->sp_w / spriteWidth);
			if(transformY > 0 && stripe > 0 && stripe < map->mp.size[0] && transformY < map->distarr[stripe])
			for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
			{
				int texY = (int)((y * 2 + spriteHeight - map->mp.size[1]) * map->sp_h / spriteHeight / 2);
				int	color = my_mlx_pixel_get(&map->s_img, texX, texY);
				if((color & 0x00FFFFFF) != 0) my_mlx_pixel_put(&map->img, (int)floor(stripe), (int)floor(y), color);
			}
		}
	}
}
