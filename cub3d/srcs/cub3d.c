/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 09:08:23 by okim              #+#    #+#             */
/*   Updated: 2021/05/02 08:14:55 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		exit_button(void)
{
	write(1, "The Window is stopped.\n", 23);
	exit(0);
}

int		player_dir(t_map *map) // 플레이어 방향 벡터 초기화
{
	if (map->mpinf.player_v == 'N')
	{
		map->dirX = 0;
		map->dirY = -1;
		map->planeX = 0.66;
		map->planeY = 0;
	}
	else if (map->mpinf.player_v == 'S')
	{
		map->dirX = 0;
		map->dirY = 1;
		map->planeX = -0.66;
		map->planeY = 0;
	}
	else if (map->mpinf.player_v == 'E')
	{
		map->dirX = 1;
		map->dirY = 0;
		map->planeX = 0;
		map->planeY = 0.66;
	}
	else if (map->mpinf.player_v == 'W')
	{
		map->dirX = -1;
		map->dirY = 0;
		map->planeX = 0;
		map->planeY = -0.66;
	}
	return (0);
}

void	col2hex(t_map *map)
{
	int		i;

	i = 0;
	map->FL = 0;
	map->CL = 0;
	while (i < 3)
	{
		map->FL += (map->mpinf.FL[i]) * pow(256, 2 - i);
		map->CL += (map->mpinf.CL[i]) * pow(256, 2 - i);
		i++;
	}
}

void	my_mlx_pixel_put(t_img *img, double x, double y, int color) // 해당 위치에 픽셀 그리기
{
	char	*dst;

	dst = img->addr + (int)floor((y * img->line_size + x * (img->bpp / 8)));
	*(unsigned int*)dst = color;
}

void	set_stepside(t_map *map)
{
	if (map->raydirX < 0)
	{
		map->stepX = -1;
		map->sidedistX = (map->mpinf.player_x - map->mapX) * map->deltadistX;
	}
	else
	{
		map->stepX = 1;
		map->sidedistX = (map->mapX + 1.0 - map->mpinf.player_x) * map->deltadistX;
	}
	if (map->raydirY < 0)
	{
		map->stepY = -1;
		map->sidedistY = (map->mpinf.player_y - map->mapY) * map->deltadistY;
	}
	else
	{
		map->stepY = 1;
		map->sidedistY = (map->mapY + 1.0 - map->mpinf.player_y) * map->deltadistY;
	}
}

double	ray2wall(t_map *map)
{
	if (map->side == 0)
		map->wdist = (map->mapX - map->mpinf.player_x + (1 - map->stepX) / 2) / map->raydirX;
	else
		map->wdist = (map->mapY - map->mpinf.player_y + (1 - map->stepY) / 2) / map->raydirY;
	return (map->wdist);
}

double	cast_single_ray(t_map *map)
{
	map->mapX = (int)map->mpinf.player_x;
	map->mapY = (int)map->mpinf.player_y;
	map->deltadistX = (map->raydirY == 0) ? 0 : (map->raydirX == 0) ? 1 : fabs(1 / map->raydirX);
	map->deltadistY = (map->raydirX == 0) ? 0 : (map->raydirY == 0) ? 1 : fabs(1 / map->raydirY);
	set_stepside(map);
	map->hit = 0;
	while (map->hit == 0)
	{
		if (map->sidedistX < map->sidedistY)
		{
			map->sidedistX += map->deltadistX;
			map->mapX += map->stepX;
			map->side = 0;
		}
		else
		{
			map->sidedistY += map->deltadistY;
			map->mapY += map->stepY;
			map->side = 1;
		}
		if (map->mpinf.map[map->mapY][map->mapX] == '1')
			map->hit = 1;
	}
	return (ray2wall(map));
}

void	dist2wall(t_map *map)
{
	int	lineHeight;

	lineHeight = (int)(map->mpinf.size[1] / map->wdist);
	map->wStart = -(lineHeight / 2) + (map->mpinf.size[1] / 2);
	if (map->wStart < 0)
		map->wStart = 0;
	map->wEnd = (lineHeight / 2) + (map->mpinf.size[1] / 2);
	if (map->wEnd >= map->mpinf.size[1])
		map->wEnd = map->mpinf.size[1] - 1;
}

void	draw_line(t_map *map, int color)
{
	double	deltaY;
	double	step;

	deltaY = map->wEnd - map->wStart;
	step = fabs(deltaY);
	deltaY /= step;
	while (abs(map->wEnd - map->wStart) > 0.01)
	{
		my_mlx_pixel_put(&map->img, (int)floor(map->xi), (int)floor(map->wStart), color);
		map->wStart += deltaY;
	}
}

int		draw_ray(t_map *map)
{
	double	cameraX;
	
	map->xi = 0;
	map->wdist = 0;
	while (map->xi < map->mpinf.size[0])
	{
		cameraX = ((2 * map->xi) / (double)map->mpinf.size[0]) - 1;
		map->raydirX = map->dirX + map->planeX * cameraX;
		map->raydirY = map->dirY + map->planeY * cameraX;
		cast_single_ray(map); // 맵 충돌 및 거리 계산
		dist2wall(map); // 거리기반 세로구하기
		draw_line(map, 0x000000);
		map->xi++;
	}
	return (0);
}

void	draw_back(t_map *map)
{
	int x;
	int y;

	y = 0;
	while (y < map->mpinf.size[1] / 2)
	{
		x = 0;
		while (x < map->mpinf.size[0])
		{
			my_mlx_pixel_put(&map->img, x, y, map->FL);
			x++;
		}
		y++;
	}
	while (y < map->mpinf.size[1])
	{
		x = 0;
		while (x < map->mpinf.size[0])
		{
			my_mlx_pixel_put(&map->img, x, y, map->CL);
			x++;
		}
		y++;
	}
}

int		draw_loop(t_map *map)
{
	draw_back(map);
	draw_ray(map);
	mlx_put_image_to_window(map->mlx, map->win, map->img.img, 0, 0);
	return (0);
}

int	press_key(int key, void *param)
{
	t_map	*map;
	double	moveSpeed;
	double	rotSpeed;
	double	oldDirX;
	double	oldPlaneX;

	moveSpeed = 1;
	rotSpeed = M_PI/45;
	map = (t_map *)param;
	oldDirX = map->dirX;
	oldPlaneX = map->planeX;
	if (key == 53 && map)
		exit(0);
	if ((key == 0 || key == 123) && map)
	{
		map->dirX = map->dirX * cos(-rotSpeed) - map->dirY * sin(-rotSpeed);
		map->dirY = oldDirX * sin(-rotSpeed) + map->dirY * cos(-rotSpeed);
		map->planeX = map->planeX * cos(-rotSpeed) - map->planeY * sin(-rotSpeed);
		map->planeY = oldPlaneX * sin(-rotSpeed) + map->planeY * cos(-rotSpeed);
	}
	if (key == 13 && map)
	{
		if (map->mpinf.map[(int)(map->mpinf.player_y)][(int)(map->mpinf.player_x + map->dirX * moveSpeed)] == '0')
			map->mpinf.player_x += map->dirX * moveSpeed;
		if (map->mpinf.map[(int)(map->mpinf.player_y + map->dirY * moveSpeed)][(int)(map->mpinf.player_x)] == '0')
			map->mpinf.player_y += map->dirY * moveSpeed;
		
	}
	if (key == 1 && map)
	{
		if (map->mpinf.map[(int)(map->mpinf.player_y)][(int)(map->mpinf.player_x - map->dirX * moveSpeed)] == '0')
			map->mpinf.player_x -= map->dirX * moveSpeed;
		if (map->mpinf.map[(int)(map->mpinf.player_y - map->dirY * moveSpeed)][(int)(map->mpinf.player_x)] == '0')
			map->mpinf.player_y -= map->dirY * moveSpeed;
	}
	if ((key == 2 || key == 124) && map)
	{
		map->dirX = map->dirX * cos(rotSpeed) - map->dirY * sin(rotSpeed);
		map->dirY = oldDirX * sin(rotSpeed) + map->dirY * cos(rotSpeed);
		map->planeX = map->planeX * cos(rotSpeed) - map->planeY * sin(rotSpeed);
		map->planeY = oldPlaneX * sin(rotSpeed) + map->planeY * cos(rotSpeed);
	}
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
	map.cube_w = mpinf->size[0] / mpinf->map_width;
	map.cube_h = mpinf->size[1] / mpinf->map_height;
	map.mpinf.player_x += 0.5;
	map.mpinf.player_y += 0.5;
	player_dir(&map);
	col2hex(&map);
	//이미지 띄우기
	map.img.img = mlx_new_image(map.mlx, mpinf->size[0], mpinf->size[1]); // 화면크기에 맞는 새로운 이미지 생성
	map.img.addr = mlx_get_data_addr(map.img.img, &map.img.bpp, &map.img.line_size, &map.img.endian);
	draw_loop(&map);
	mlx_key_hook(map.win, press_key, &map);
	mlx_hook(map.win, 17, 0, exit_button, &map);
	mlx_loop(map.mlx);
	return (0);
}

// void	draw_char(t_map *map, int x, int y, int color)
// {
// 	int	dx;
// 	int	dy;
// 	int	ddx;
// 	int	ddy;
// 
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
// 
// }
// void	draw_line(t_map *map, double x1, double y1, double x2, double y2)
// {
// 	double	deltaX;
// 	double	deltaY;
// 	double	step;
// 
// 	deltaX = x2 - x1;
// 	deltaY = y2 - y1;
// 	step = (fabs(deltaX) > fabs(deltaY)) ? fabs(deltaX) : fabs(deltaY);
// 	deltaX /= step;
// 	deltaY /= step;
// 	while (fabs(x2 - x1) > 0.01 || fabs(y2 - y1) > 0.01)
// 	{
// 		my_mlx_pixel_put(&map->img, (int)floor(x1), (int)floor(y1), 0xb3b3b3);
// 		x1 += deltaX;
// 		y1 += deltaY;
// 	}
// }
// 
// void 	draw_lines(t_map *map)
// {
// 	int		i;
// 	int		j;
// 	int		COL;
// 	int		ROW;
// 
// 	COL = map->mpinf.map_width;
// 	ROW = map->mpinf.map_height;
// 	i = 0;
// 	while (i < COL)
// 	{
// 		draw_line(map, i * map->cube_width, 0, i * map->cube_width, map->mpinf.size[1]);
// 		i++;
// 	}
// 	draw_line(map, COL * map->cube_width - 1, 0, COL * map->cube_width - 1, map->mpinf.size[1]);
// 	j = 0;
// 	while (j < ROW)
// 	{
// 		draw_line(map, 0, j * map->cube_height, map->mpinf.size[0], j * map->cube_height);
// 		j++;
// 	}
// 	draw_line(map, 0, ROW * map->cube_height - 1, map->mpinf.size[0], ROW * map->cube_height - 1);
// }
// 
// int		draw_loop(t_map *map)
// {
// 	draw_back(map);
// 	draw_squares(map);
// 	draw_lines(map);
// 	// draw_char(map, map->cube_width * map->mpinf.player_x + map->mpinf.add_x, map->cube_height * map->mpinf.player_y + map->mpinf.add_y, 0xffcc00);
// 	mlx_put_image_to_window(map->mlx, map->win, map->img.img, 0, 0);
// 	return (0);
// }