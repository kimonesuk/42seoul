/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 09:08:23 by okim              #+#    #+#             */
/*   Updated: 2021/05/02 15:01:05 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

// int		my_mlx_pixel_get(t_img *img, double x, double y)
// {
// 	int		color;
// 	char	*dst;

// 	dst = img->addr + (int)floor((y * img->line_size + x * (img->bpp / 8)));
// 	color = *(unsigned int*)dst;
// 	return (color);
// }

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

// int		setTexture(t_map *map)
// {
// 	int		color;
// 	int		texX;
// 	int		texY;
// 	double	wallX;
// 	double	step;


// 	if (map->side == 0)	wallX = map->mpinf.player_y + map->wdist * map->raydirY;
// 	else	wallX = map->mpinf.player_x + map->wdist * map->raydirX;
// 	wallX -= floor((wallX));
// 	texX = (int)(wallX * (double)(map->mpinf.size[0]));
// 	step = 1.0 * map->mpinf.size[1] / (map->wEnd - map->wStart);
// 	texY = map->wStart * step * map->xi;
// 	if(map->side == 0 && map->raydirX > 0) texX = map->mpinf.size[0] - texX - 1;
// 	if(map->side == 1 && map->raydirY < 0) texX = map->mpinf.size[0] - texX - 1;
// 	if (map->side == 0 && map->dirX < 0) // east
// 		color = my_mlx_pixel_get(&map->EA_img, texX, texY);
// 	else if (map->side == 0 && map->dirX >= 0) // west
// 		color = my_mlx_pixel_get(&map->WE_img, texX, texY);
// 	else if (map->side == 1 && map->dirY < 0) // south
// 		color = my_mlx_pixel_get(&map->SO_img, texX, texY);
// 	else if (map->side == 1 && map->dirY >= 0) // north
// 		color = my_mlx_pixel_get(&map->NO_img, texX, texY);
// 	return (-1);
// }

int		draw_ray(t_map *map)
{
	double	cameraX;
	int		texture;
	
	map->xi = 0;
	map->wdist = 0;
	while (map->xi < map->mpinf.size[0])
	{
		cameraX = ((2 * map->xi) / (double)map->mpinf.size[0]) - 1;
		map->raydirX = map->dirX + map->planeX * cameraX;
		map->raydirY = map->dirY + map->planeY * cameraX;
		cast_single_ray(map); // 맵 충돌 및 거리 계산
		dist2wall(map); // 거리기반 세로구하기
		texture = 0;
		//texture = setTexture(map); //텍스쳐 지정함수 설정 (side, dir에 따라 동서남북 구분)
		draw_line(map, texture);
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
	printf("%d %d\n", map->mpinf.size[0], map->mpinf.size[1]);
	return (0);
}

int press_arrow(int key, t_map *map)
{
	double	rotSpeed;
	double	oldDirX;
	double	oldPlaneX;
	int		i;

	rotSpeed = M_PI / 45;
	if (map->pressed == 1)
		return (0);
	i = 0;
	while (i * rotSpeed < M_PI / 6)
	{
		oldDirX = map->dirX;
		oldPlaneX = map->planeX;
		if (key == 123 && map)
		{
			map->dirX = map->dirX * cos(-rotSpeed) - map->dirY * sin(-rotSpeed);
			map->dirY = oldDirX * sin(-rotSpeed) + map->dirY * cos(-rotSpeed);
			map->planeX = map->planeX * cos(-rotSpeed) - map->planeY * sin(-rotSpeed);
			map->planeY = oldPlaneX * sin(-rotSpeed) + map->planeY * cos(-rotSpeed);
		}
		if (key == 124 && map)
		{
			map->dirX = map->dirX * cos(rotSpeed) - map->dirY * sin(rotSpeed);
			map->dirY = oldDirX * sin(rotSpeed) + map->dirY * cos(rotSpeed);
			map->planeX = map->planeX * cos(rotSpeed) - map->planeY * sin(rotSpeed);
			map->planeY = oldPlaneX * sin(rotSpeed) + map->planeY * cos(rotSpeed);
		}
		draw_loop(map);
		i++;
	}
	map->pressed = 1;
	return (0);
}

int release_arrow(int key, t_map *map)
{
	double	rotSpeed;
	double	oldDirX;
	double	oldPlaneX;
	int		i;

	rotSpeed = M_PI / 45;
	if (map->pressed == 0)
		return (0);
	i = 0;
	while (i * rotSpeed < M_PI / 6)
	{
		oldDirX = map->dirX;
		oldPlaneX = map->planeX;
		if (key == 123 && map)
		{
			map->dirX = map->dirX * cos(rotSpeed) - map->dirY * sin(rotSpeed);
			map->dirY = oldDirX * sin(rotSpeed) + map->dirY * cos(rotSpeed);
			map->planeX = map->planeX * cos(rotSpeed) - map->planeY * sin(rotSpeed);
			map->planeY = oldPlaneX * sin(rotSpeed) + map->planeY * cos(rotSpeed);
		}
		if (key == 124 && map)
		{
			map->dirX = map->dirX * cos(-rotSpeed) - map->dirY * sin(-rotSpeed);
			map->dirY = oldDirX * sin(-rotSpeed) + map->dirY * cos(-rotSpeed);
			map->planeX = map->planeX * cos(-rotSpeed) - map->planeY * sin(-rotSpeed);
			map->planeY = oldPlaneX * sin(-rotSpeed) + map->planeY * cos(-rotSpeed);
		}
		draw_loop(map);
		i++;
	}
	map->pressed = 0;
	return (0);
}

int	press_key(int key, t_map *map)
{
	double	moveSpeed;
	double	rotSpeed;
	double	oldDirX;
	double	oldPlaneX;

	moveSpeed = 1;
	rotSpeed = M_PI/45;
	oldDirX = map->dirX;
	oldPlaneX = map->planeX;
	if (key == 53 && map)
		exit(0);
	if (key == 0 && map)
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
	if (key == 2 && map)
	{
		map->dirX = map->dirX * cos(rotSpeed) - map->dirY * sin(rotSpeed);
		map->dirY = oldDirX * sin(rotSpeed) + map->dirY * cos(rotSpeed);
		map->planeX = map->planeX * cos(rotSpeed) - map->planeY * sin(rotSpeed);
		map->planeY = oldPlaneX * sin(rotSpeed) + map->planeY * cos(rotSpeed);
	}
	draw_loop(map);
	return (0);
}

int	key_press(int keycode, t_map *map)
{
	if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13)
		press_key(keycode, map);
	if (keycode == 123 || keycode == 124)
		press_arrow(keycode, map);
	if (keycode == 53)
	{
		write(1, "The Window is stopped.\n", 23);
		exit(0);
	}
	return (0);
}

int	key_release(int keycode, t_map *map)
{
	if (keycode == 123 || keycode == 124)
		release_arrow(keycode, map);
	return (0);
}

int	key_exit()
{
	write(1, "The Window is stopped.\n", 23);
	exit(0);
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
	map.pressed = 0;
	player_dir(&map);
	col2hex(&map);
	//텍스쳐 초기화
	// map.NO_img.img = mlx_xpm_file_to_image(map.mlx, map.mpinf.NO_path, &map.mpinf.size[0], &map.mpinf.size[1]);
	// map.NO_img.addr = mlx_get_data_addr(map.NO_img.img, &map.NO_img.bpp, &map.NO_img.line_size, &map.NO_img.endian);
	// map.SO_img.img = mlx_xpm_file_to_image(map.mlx, map.mpinf.SO_path, &map.mpinf.size[0], &map.mpinf.size[1]);
	// map.SO_img.addr = mlx_get_data_addr(map.SO_img.img, &map.SO_img.bpp, &map.SO_img.line_size, &map.SO_img.endian);
	// map.EA_img.img = mlx_xpm_file_to_image(map.mlx, map.mpinf.EA_path, &map.mpinf.size[0], &map.mpinf.size[1]);
	// map.EA_img.addr = mlx_get_data_addr(map.EA_img.img, &map.EA_img.bpp, &map.EA_img.line_size, &map.EA_img.endian);
	// map.WE_img.img = mlx_xpm_file_to_image(map.mlx, map.mpinf.WE_path, &map.mpinf.size[0], &map.mpinf.size[1]);
	// map.WE_img.addr = mlx_get_data_addr(map.WE_img.img, &map.WE_img.bpp, &map.WE_img.line_size, &map.WE_img.endian);
	//이미지 초기화
	map.img.img = mlx_new_image(map.mlx, mpinf->size[0], mpinf->size[1]); // 화면크기에 맞는 새로운 이미지 생성
	map.img.addr = mlx_get_data_addr(map.img.img, &map.img.bpp, &map.img.line_size, &map.img.endian);
	draw_loop(&map);
	// mlx_put_image_to_window(map.mlx, map.win, map.SO_img.img, 0, 0);
    mlx_hook(map.win, X_EVENT_KEY_PRESS, 0, key_press, &map);
    mlx_hook(map.win, X_EVENT_KEY_release, 0, key_release, &map);
    mlx_hook(map.win, X_EVENT_KEY_EXIT, 0, key_exit, &map);
	mlx_loop(map.mlx);
	return (0);
}