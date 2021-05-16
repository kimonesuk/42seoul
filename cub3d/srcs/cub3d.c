/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 09:08:23 by okim              #+#    #+#             */
/*   Updated: 2021/05/16 12:12:32 by okim             ###   ########.fr       */
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

int		my_mlx_pixel_get(t_img *img, double x, double y)
{
	char	*dst;
	int		color;

	dst = img->addr + (int)floor((y * img->line_size + x * (img->bpp / 8)));
	color = *(unsigned int*)dst;
	return (color);
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
	int	i;

	i = 0;
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

int		setTexture(t_map *map, double dy)
{
	int		color;
	int		texX;
	int		texY;
	double	wallX;
	double	wallY;

	color = -1;
	if (map->side == 0)	wallX = map->mpinf.player_y + map->wdist * map->raydirY;
	else	wallX = map->mpinf.player_x + map->wdist * map->raydirX;
	wallX -= floor(wallX);
	wallY = dy / abs(map->wEnd - map->wStart);
	if (map->side == 0 && map->raydirX < 0) // east
	{
		texX = (int)(wallX * map->EA_w);
		texY = (int)(wallY * map->EA_h);
		color = my_mlx_pixel_get(&map->EA_img, texX, texY);
	}
	else if (map->side == 0 && map->raydirX >= 0) // west
	{
		texX = (int)(wallX * map->WE_w);
		texY = (int)(wallY * map->WE_h);
		color = my_mlx_pixel_get(&map->WE_img, texX, texY);
	}
	else if (map->side == 1 && map->raydirY < 0) // south
	{
		texX = (int)(wallX * map->SO_w);
		texY = (int)(wallY * map->SO_h);
		color = my_mlx_pixel_get(&map->SO_img, texX, texY);
	}
	else if (map->side == 1 && map->raydirY >= 0) // north
	{
		texX = (int)(wallX * map->NO_w);
		texY = (int)(wallY * map->NO_h);
		color = my_mlx_pixel_get(&map->NO_img, texX, texY);
	}
	else
		color = 0;
	return (color);
}

void	draw_line(t_map *map)
{
	double	deltaY;
	double	start;
	int		color;

	start = map->wStart;
	deltaY = map->wEnd - map->wStart;
	deltaY /= fabs(deltaY);
	while (fabs(map->wEnd - start) > 0.01)
	{
		color = setTexture(map, start - map->wStart);
		my_mlx_pixel_put(&map->img, (int)floor(map->xi), (int)floor(start), color);
		start += deltaY;
	}
}

int		draw_ray(t_map *map)
{
	double	cameraX;
	
	map->xi = 0;
	map->wdist = 0;
	map->distarr = (double *)malloc(sizeof(double) * map->mpinf.size[0]);
	while (map->xi < map->mpinf.size[0])
	{
		cameraX = ((2 * map->xi) / (double)map->mpinf.size[0]) - 1;
		map->raydirX = map->dirX + map->planeX * cameraX;
		map->raydirY = map->dirY + map->planeY * cameraX;
		cast_single_ray(map); // 맵 충돌 및 거리 계산
		dist2wall(map); // 거리기반 세로구하기
		map->distarr[map->xi] = map->wdist;
		draw_line(map);
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

void	draw_sprite(t_map *map)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	map->sp_dist = (double *)malloc(sizeof(double) * map->mpinf.spcnt);
	while (i < map->mpinf.spcnt) // 플레이어 ~ 스프라이트 길이
	{
		map->sp_dist[i] = pow((map->mpinf.player_x - map->sp[i].x), 2) + pow((map->mpinf.player_y - map->sp[i].y), 2);
		i++;
	}
	i = 0; // 정렬
	while (i < map->mpinf.spcnt)
	{
		j = 0;
		while (j < map->mpinf.spcnt - i - 1)
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
	for(int i = 0; i < map->mpinf.spcnt; i++)
	{
		double spriteX = map->sp[i].x - map->mpinf.player_x; // 스프라이트의 상대적 위치 x
		double spriteY = map->sp[i].y - map->mpinf.player_y; // 스프라이트의 상대적 위치 y
		double invDet = 1.0 / (map->planeX * map->dirY - map->dirX * map->planeY);
		double transformX = invDet * (map->dirY * spriteX - map->dirX * spriteY); // 화면평면에 투사된 x
		double transformY = invDet * (-map->planeY * spriteX + map->planeX * spriteY); // 화면평면에 투사된 y
		int spriteScreenX = (int)((map->mpinf.size[0] / 2) * (1 + transformX / transformY));
		int spriteHeight = abs((int)(map->mpinf.size[1] / (transformY))); // 스프라이트의 높이
		int drawStartY = -spriteHeight / 2 + map->mpinf.size[1] / 2;
		if (drawStartY < 0) drawStartY = 0;
		int drawEndY = spriteHeight / 2 + map->mpinf.size[1] / 2;
		if (drawEndY >= map->mpinf.size[1]) drawEndY = map->mpinf.size[1] - 1;

		int spriteWidth = abs((int)(map->mpinf.size[1] / (transformY)));
		int drawStartX = -spriteWidth / 2 + spriteScreenX;
		if(drawStartX < 0) drawStartX = 0;
		int drawEndX = spriteWidth / 2 + spriteScreenX;
		if(drawEndX >= map->mpinf.size[0]) drawEndX = map->mpinf.size[0] - 1;

		for(int stripe = drawStartX; stripe < drawEndX; stripe++)
		{
			int texX = (int)((stripe - (-spriteWidth / 2 + spriteScreenX)) * map->sp_w / spriteWidth);
			if(transformY > 0 && stripe > 0 && stripe < map->mpinf.size[0] && transformY < map->distarr[stripe])
			for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
			{
				int texY = (int)((y * 2 + spriteHeight - map->mpinf.size[1]) * map->sp_h / spriteHeight / 2);
				int	color = my_mlx_pixel_get(&map->S_img, texX, texY);
				if((color & 0x00FFFFFF) != 0) my_mlx_pixel_put(&map->img, (int)floor(stripe), (int)floor(y), color);
			}
		}
	}
}

int		draw_loop(t_map *map)
{
	draw_back(map);
	draw_ray(map);
	draw_sprite(map);
	mlx_put_image_to_window(map->mlx, map->win, map->img.img, 0, 0);
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

void pst_sp(t_map *map)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	map->sp = (t_sprite *)malloc(sizeof(t_sprite) * map->mpinf.spcnt);
	while (y < map->mpinf.map_height)
	{
		x = 0;
		while (x < ft_strlen(map->mpinf.map[y]))
		{
			if (map->mpinf.map[y][x] == '2')
			{
				map->sp[i].x = x + 0.5;
				map->sp[i].y = y + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
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
	//map 구조체 초기화
	map.mpinf = *mpinf;
	map.mlx = mlx_ptr;
	map.cube_w = mpinf->size[0] / mpinf->map_width;
	map.cube_h = mpinf->size[1] / mpinf->map_height;
	map.mpinf.player_x += 0.5;
	map.mpinf.player_y += 0.5;
	map.pressed = 0;
	pst_sp(&map);
	player_dir(&map);
	col2hex(&map);
	//텍스쳐 초기화
	map.NO_img.img = mlx_xpm_file_to_image(map.mlx, map.mpinf.NO_path, &map.NO_w, &map.NO_h);
	map.NO_img.addr = mlx_get_data_addr(map.NO_img.img, &map.NO_img.bpp, &map.NO_img.line_size, &map.NO_img.endian);
	map.SO_img.img = mlx_xpm_file_to_image(map.mlx, map.mpinf.SO_path, &map.SO_w, &map.SO_h);
	map.SO_img.addr = mlx_get_data_addr(map.SO_img.img, &map.SO_img.bpp, &map.SO_img.line_size, &map.SO_img.endian);
	map.EA_img.img = mlx_xpm_file_to_image(map.mlx, map.mpinf.EA_path, &map.EA_w, &map.EA_h);
	map.EA_img.addr = mlx_get_data_addr(map.EA_img.img, &map.EA_img.bpp, &map.EA_img.line_size, &map.EA_img.endian);
	map.WE_img.img = mlx_xpm_file_to_image(map.mlx, map.mpinf.WE_path, &map.WE_w, &map.WE_h);
	map.WE_img.addr = mlx_get_data_addr(map.WE_img.img, &map.WE_img.bpp, &map.WE_img.line_size, &map.WE_img.endian);
	map.S_img.img = mlx_xpm_file_to_image(map.mlx, map.mpinf.S_path, &map.sp_w, &map.sp_h);
	map.S_img.addr = mlx_get_data_addr(map.S_img.img, &map.S_img.bpp, &map.S_img.line_size, &map.S_img.endian);
	//이미지 초기화
	map.img.img = mlx_new_image(map.mlx, mpinf->size[0], mpinf->size[1]); // 화면크기에 맞는 새로운 이미지 생성
	map.img.addr = mlx_get_data_addr(map.img.img, &map.img.bpp, &map.img.line_size, &map.img.endian);
	if (map.mpinf.save == 1)
	{
		draw_back(&map);
		draw_ray(&map);
		draw_sprite(&map);
		//map.img를 bmp 파일로 저장하기
		return (0);
	}
	//새창 띄우기
	if ((win_ptr = mlx_new_window(mlx_ptr, mpinf->size[0], mpinf->size[1], "cub3d")) == NULL)
		return (error_msg(-8));
	map.win = win_ptr;
	draw_loop(&map);
	mlx_hook(map.win, X_EVENT_KEY_PRESS, 0, key_press, &map);
	mlx_hook(map.win, X_EVENT_KEY_release, 0, key_release, &map);
	mlx_hook(map.win, X_EVENT_KEY_EXIT, 0, key_exit, &map);
	mlx_loop(map.mlx);
	return (0);
}