/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:27:08 by okim              #+#    #+#             */
/*   Updated: 2021/05/19 22:05:53 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	int_char(unsigned char *ptr, int value)
{
	ptr[0] = (unsigned char)(value);
	ptr[1] = (unsigned char)(value >> 8);
	ptr[2] = (unsigned char)(value >> 16);
	ptr[3] = (unsigned char)(value >> 24);
}

int		bmp_header(int fd, int filesize, t_map *map)
{
	int				i;
	int				tmp;
	unsigned char	bmpheader[54];

	i = 0;
	while (i < 54)
		bmpheader[i++] = (unsigned char)(0);
	bmpheader[0] = (unsigned char)('B');
	bmpheader[1] = (unsigned char)('M');
	int_char(bmpheader + 2, filesize);
	bmpheader[10] = (unsigned char)(54);
	bmpheader[14] = (unsigned char)(40);
	tmp = map->mp.size[0];
	int_char(bmpheader + 18, tmp);
	tmp = (map->mp.size[1]) * -1;
	int_char(bmpheader + 22, tmp);
	bmpheader[27] = (unsigned char)(1);
	bmpheader[28] = (unsigned char)(24);
	return (!(write(fd, bmpheader, 54) < 0));
}

int		get_color(t_map *map, int x, int y)
{
	int	rgb;
	int	color;

	color = my_mlx_pixel_get(&map->img, x, y);
	rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);
	return (rgb);
}

int		bmp_data(int file, t_map *map, int pad)
{
	const unsigned char	zero[3] = {0, 0, 0};
	int					i;
	int					j;
	int					color;

	i = 0;
	while (i < (int)map->mp.size[1])
	{
		j = 0;
		while (j < (int)map->mp.size[0])
		{
			color = get_color(map, j, i);
			if (write(file, &color, 3) < 0)
				return (0);
			if (pad > 0 && write(file, &zero, pad) < 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		save_bmp(t_map *map)
{
	int		filesize;
	int		file;
	int		pad;

	pad = (4 - ((int)map->mp.size[0] * 3) % 4) % 4;
	filesize = 54 + (3 * ((int)map->mp.size[0] + pad) * (int)map->mp.size[1]);
	if ((file = open("screenshot.bmp", O_WRONLY | O_CREAT |
	O_TRUNC | O_APPEND)) < 0)
		return (0);
	if (!bmp_header(file, filesize, map))
		return (0);
	if (!bmp_data(file, map, pad))
		return (0);
	close(file);
	return (1);
}
