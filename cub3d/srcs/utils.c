/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 09:10:00 by okim              #+#    #+#             */
/*   Updated: 2021/05/23 14:54:02 by okim             ###   ########.fr       */
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
	write(1, "Error\n", 6);
	if (error_n == -1)
		write(1, "Invalid file path\n", 18);
	else if (error_n == -2)
		write(1, "Invalid elements contents\n", 26);
	else if (error_n == -3)
		write(1, "Invalid map contents\n", 21);
	else if (error_n == -4)
		write(1, "Invalid map shape\n", 18);
	else if (error_n == -5)
		write(1, "Invalid input.\n", 15);
	else if (error_n == -6)
		write(1, "Invalid map file.\n", 18);
	else if (error_n == -7)
		write(1, "Can't Connect mlx\n", 18);
	else if (error_n == -8)
		write(1, "Can't open a new window\n", 24);
	else
		return (0);
	return (0);
}
