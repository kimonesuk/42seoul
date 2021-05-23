/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 09:10:00 by okim              #+#    #+#             */
/*   Updated: 2021/05/23 21:06:15 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*skip_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	return (&str[i]);
}

void	player_dir(t_map *map)
{
	map->dirx = 0;
	map->diry = 0;
	map->planex = 0;
	map->planey = 0;
	if (map->mp.player_v == 'N')
	{
		map->diry = -1;
		map->planex = 0.66;
	}
	else if (map->mp.player_v == 'S')
	{
		map->diry = 1;
		map->planex = -0.66;
	}
	else if (map->mp.player_v == 'E')
	{
		map->dirx = 1;
		map->planey = 0.66;
	}
	else if (map->mp.player_v == 'W')
	{
		map->dirx = -1;
		map->planey = -0.66;
	}
}

void	my_mlx_pixel_put(t_img *img, double x, double y, int color)
{
	char	*dst;

	dst = img->addr + (int)floor((y * img->line_size + x * (img->bpp / 8)));
	*(unsigned int*)dst = color;
}

int		my_mlx_pixel_get(t_img *img, double x, double y)
{
	char	*dst;
	int		color;

	dst = img->addr + (int)floor((y * img->line_size + x * (img->bpp / 8)));
	color = *(unsigned int*)dst;
	return (color);
}

int		error_msg(int error_n)
{
	printf("Error\n");
	if (error_n == -1)
		printf("Invalid file path\n");
	else if (error_n == -2)
		printf("Invalid elements contents\n");
	else if (error_n == -3)
		printf("Invalid map contents\n");
	else if (error_n == -4)
		printf("Invalid map shape\n");
	else if (error_n == -5)
		printf("Invalid input.\n");
	else if (error_n == -6)
		printf("Invalid map file.\n");
	else if (error_n == -7)
		printf("Can't Connect mlx\n");
	else if (error_n == -8)
		printf("Can't open a new window\n");
	else
		return (-1);
	return (-1);
}
