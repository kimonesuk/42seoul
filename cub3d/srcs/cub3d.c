/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 09:08:23 by okim              #+#    #+#             */
/*   Updated: 2021/04/29 09:17:30 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		exit_button(void)
{
	write(1, "The Window is stopped.\n", 23);
	exit(0);
}

int		player_dir(t_map *map)
{
	if (map->mpinf.player_v == 'N')
	{
		map->mpinf.dir_x = 0;
		map->mpinf.dir_y = 1;
	}
	else if (map->mpinf.player_v == 'S')
	{
		map->mpinf.dir_x = 0;
		map->mpinf.dir_y = -1;
	}
	else if (map->mpinf.player_v == 'W')
	{
		map->mpinf.dir_x = -1;
		map->mpinf.dir_y = 0;
	}
	else if (map->mpinf.player_v == 'E')
	{
		map->mpinf.dir_x = 1;
		map->mpinf.dir_y = 0;
	}
	return (0);
}

void	my_mlx_pixel_put(t_img *img, double x, double y, int color)
{
	char	*dst;

	dst = img->addr + (int)floor((y * img->line_size + x * (img->bpp / 8)));
	*(unsigned int*)dst = color;
}

void	draw_ray(t_map *map, int color)
{
	int		x;
	int		w;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int mapX;
	int mapY;
	double sideDistX;
	double sideDistY;
	double deltaDistX = std::abs(1 / rayDirX);
	double deltaDistY = std::abs(1 / rayDirY);
	double perpWallDist;
	int stepX;
	int stepY;
	int hit; //was there a wall hit?
	int side; //was a NS or a EW wall hit?
	
	x = 0;
	w = 16; // w = 평면을 나누는 간격(-,-,-,-,-...,-,-)
	mapX = int(map->mpinf.player_x);
	mapY = int(map->mpinf.player_y);
	hit = 0;
	while(x < w) // 0, 1, 2, ..., 15
	{
		cameraX = 2 * x / double(w) - 1; // 2를 곱해주지 않으면 음수부분만 표현
		rayDirX = map->mpinf.dir_x + map->mpinf.plane_x * cameraX;
		rayDirY = map->mpinf.dir_y + map->mpinf.plane_y * cameraX; //광선방향 = 플레이어 방향 + 평면 방향 * 배수
		x++;
	}
}

// void	draw_char(t_map *map, int x, int y, int color)
// {
// 	int	dx;
// 	int	dy;
// 	int	ddx;
// 	int	ddy;

// 	dx = 1;
// 	dy = 1;
// 	while (dy > -(map->cube_height / 2))
// 	{
// 		ddx = cos(map->mpinf.ceta) * dx - sin(map->mpinf.ceta) * dy;
// 		ddy = sin(map->mpinf.ceta) * dx + cos(map->mpinf.ceta) * dy;
// 		my_mlx_pixel_put(&map->img, x + ddx, y + ddy, color);
// 		dy--;
// 	}
// 	dy = -(map->cube_height / 8);
// 	while (dy < (map->cube_height / 8))
// 	{
// 		dx = -(map->cube_width / 8);
// 		while (dx < (map->cube_width / 8))
// 		{
// 			my_mlx_pixel_put(&map->img, x + dx, y + dy, 0x00FF00);
// 			dx++;
// 		}
// 		dy++;
// 	}
// }

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
void	draw_line(t_map *map, double x1, double y1, double x2, double y2)
{
	double	deltaX;
	double	deltaY;
	double	step;

	deltaX = x2 - x1;
	deltaY = y2 - y1;
	step = (fabs(deltaX) > fabs(deltaY)) ? fabs(deltaX) : fabs(deltaY);
	deltaX /= step;
	deltaY /= step;
	while (fabs(x2 - x1) > 0.01 || fabs(y2 - y1) > 0.01)
	{
		my_mlx_pixel_put(&map->img, (int)floor(x1), (int)floor(y1), 0xb3b3b3);
		x1 += deltaX;
		y1 += deltaY;
	}
}

void 	draw_lines(t_map *map)
{
	int		i;
	int		j;
	int		COL;
	int		ROW;

	COL = map->mpinf.map_width;
	ROW = map->mpinf.map_height;
	i = 0;
	while (i < COL)
	{
		draw_line(map, i * map->cube_width, 0, i * map->cube_width, map->mpinf.size[1]);
		i++;
	}
	draw_line(map, COL * map->cube_width - 1, 0, COL * map->cube_width - 1, map->mpinf.size[1]);
	j = 0;
	while (j < ROW)
	{
		draw_line(map, 0, j * map->cube_height, map->mpinf.size[0], j * map->cube_height);
		j++;
	}
	draw_line(map, 0, ROW * map->cube_height - 1, map->mpinf.size[0], ROW * map->cube_height - 1);
}

int		draw_loop(t_map *map)
{
	draw_back(map);
	draw_squares(map);
	draw_lines(map);
	// draw_char(map, map->cube_width * map->mpinf.player_x + map->mpinf.add_x, map->cube_height * map->mpinf.player_y + map->mpinf.add_y, 0xffcc00);
	mlx_put_image_to_window(map->mlx, map->win, map->img.img, 0, 0);
	return (0);
}

int	press_key(int key, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (key == 53 && map)
		exit(0);
	if ((key == 0 || key == 123) && map)
		map->mpinf.ceta -= M_PI / 180 * 5;
	if (key == 13 && map)
	{
		map->mpinf.add_x += (int)(5 * sin(map->mpinf.ceta));
		map->mpinf.add_y -= (int)(5 * cos(map->mpinf.ceta));
	}
	if (key == 1 && map)
	{
		map->mpinf.add_x -= (int)(5 * sin(map->mpinf.ceta));
		map->mpinf.add_y += (int)(5 * cos(map->mpinf.ceta));
	}
	if ((key == 2 || key == 124) && map)
		map->mpinf.ceta += M_PI / 180 * 5;
	draw_loop(map);
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
	map.mpinf.add_x = 0;
	map.mpinf.add_y = 0;
	map.cube_width = mpinf->size[0] / mpinf->map_width;
	map.cube_height = mpinf->size[1] / mpinf->map_height;
	map.mpinf.player_x += (map->cube_width / 2);
	map.mpinf.player_y += (map->cube_height / 2);
	player_dir(&map);
	map.mpinf.player_x = map.mpinf.dir_y;
	map.mpinf.player_y = map.mpinf.dir_x;
	if (map.mpinf.plane_x == 0)
		map.mpinf.plane_x = 0.66;
	if (map.mpinf.plane_y == 0)
		map.mpinf.plane_y = 0.66;
	//이미지 띄우기
	map.img.img = mlx_new_image(map.mlx, mpinf->size[0], mpinf->size[1]); // 화면크기에 맞는 새로운 이미지 생성
	map.img.addr = mlx_get_data_addr(map.img.img, &map.img.bpp, &map.img.line_size, &map.img.endian);
	draw_loop(&map);
	mlx_key_hook(map.win, press_key, &map);
	mlx_hook(map.win, 17, 0, exit_button, &map);
	mlx_loop(map.mlx);
	return (0);
}