/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:27:08 by okim              #+#    #+#             */
/*   Updated: 2021/05/23 20:54:52 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		bmp_header(int fd, int filesize, t_map *map)
{
	int				i;
	unsigned char	bmpheader[54];

	i = 0;
	while (i < 54)
		bmpheader[i++] = (unsigned char)(0);
	bmpheader[0] = (unsigned char)('B');
	bmpheader[1] = (unsigned char)('M');
	*(unsigned int *)&bmpheader[2] = filesize;
	bmpheader[10] = (unsigned char)(54);
	bmpheader[14] = (unsigned char)(40);
	*(unsigned int *)&bmpheader[18] = (signed int)(map->mp.size[0]);
	*(unsigned int *)&bmpheader[22] = (signed int)(map->mp.size[1]);
	bmpheader[26] = (unsigned char)(1);
	bmpheader[28] = (unsigned char)(32);
	return (!(write(fd, bmpheader, 54) < 0));
}

int		bmp_data(int file, t_map *map, int filesize)
{
	int				i;
	int				j;
	unsigned int	color;
	unsigned char	buffer[filesize - 54];

	i = 0;
	while (i < (signed int)map->mp.size[1])
	{
		j = 0;
		while (j < (signed int)map->mp.size[0])
		{
			color = my_mlx_pixel_get(&map->img, j, i);
			*(unsigned int *)&buffer[((map->mp.size[1] - (i + 1))
			* map->mp.size[0] + j) * 4] = color;
			j++;
		}
		i++;
	}
	return (!(write(file, buffer, filesize - 54) < 0));
}

int		save_bmp(t_map *map)
{
	int		filesize;
	int		file;

	filesize = 4 * map->mp.size[0] * map->mp.size[1] + 54;
	if ((file = open("screenshot.bmp", O_WRONLY | O_CREAT, 0644 | O_TRUNC)) < 0)
		return (0);
	if (!bmp_header(file, filesize, map))
		return (0);
	if (!bmp_data(file, map, filesize))
		return (0);
	close(file);
	return (1);
}
