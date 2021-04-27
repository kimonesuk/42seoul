/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 09:08:23 by okim              #+#    #+#             */
/*   Updated: 2021/04/27 11:25:24 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		exit_button(void)
{
	exit(0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_size + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	draw_square(t_map *map, int x, int y, int color)
{
	int dx;
	int dy;

	dy = 0;
	while (dy < map->cube_height)
	{
		dx = 0;
		while (dx < map->cube_width)
		{
			my_mlx_pixel_put(&map->img, x + dx, y + dy, color);
			dx++;
		}
		dy++;
	}
}

void	draw_squares(t_map *map)
{
	int x;
	int y;

	y = 0;
	while (y < map->mpinf.map_height)
	{
		x = 0;
		while (x < ft_strlen(map->mpinf.map[y]))
		{
			if (map->mpinf.map[y][x] == '1')
				draw_square(map, map->cube_width * x, map->cube_height * y, 0x0000FF);
			else if (map->mpinf.map[y][x] == '2')
				draw_square(map, map->cube_width * x, map->cube_height * y, 0x00FFFF);
			else if (map->mpinf.map[y][x] == ' ')
				draw_square(map, map->cube_width * x, map->cube_height * y, 0x000000);
			else
				draw_square(map, map->cube_width * x, map->cube_height * y, 0xFFFFFF);
			x++;
		}
		y++;
	}
}

void	draw_back(t_map *map)
{
	int x;
	int y;

	y = 0;
	while (y < map->mpinf.map_height)
	{
		x = 0;
		while (x < map->mpinf.map_width)
		{
			draw_square(map, map->cube_width * x, map->cube_height * y, 0x000000);
			x++;
		}
		y++;
	}
}

int		draw_loop(t_map *map)
{
	draw_back(map);
	draw_squares(map);
	//draw_lines(map);
	mlx_put_image_to_window(map->mlx, map->win, map->img.img, 0, 0);
	return (0);
}

int	cub3d(t_mpinf *mpinf)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	map;

	if ((mlx_ptr = mlx_init()) == NULL)
			return (error_msg(-7));
	//화면 최대값 수정
	mlx_get_screen_size(mlx_ptr, &mpinf->max_width, &mpinf->max_height);
	if (mpinf->size[0] >= mpinf->max_width)
		mpinf->size[0] = mpinf->max_width;
	if (mpinf->size[1] >= mpinf->max_height)
		mpinf->size[1] = mpinf->max_height;
	//새창 띄우기
	if ((win_ptr = mlx_new_window(mlx_ptr, mpinf->size[0], mpinf->size[1], "cub3d")) == NULL)
		return (error_msg(-8));
	//map 구조체 초기화
	map.mpinf = *mpinf;
	map.mlx = mlx_ptr;
	map.win = win_ptr;
	map.cube_width = mpinf->size[0] / mpinf->map_width;
	map.cube_height = mpinf->size[1] / mpinf->map_height;
	//이미지 띄우기
	map.img.img = mlx_new_image(map.mlx, mpinf->size[0], mpinf->size[1]); // 화면크기에 맞는 새로운 이미지 생성
	map.img.addr = mlx_get_data_addr(map.img.img, &map.img.bpp, &map.img.line_size, &map.img.endian);
	draw_loop(&map);
	mlx_key_hook(map.win, press_key, map.win);
	mlx_hook(map.win, 17, 0, exit_button, &map);
	mlx_loop(map.mlx);
	return (0);
}