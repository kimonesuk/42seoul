/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 09:08:23 by okim              #+#    #+#             */
/*   Updated: 2021/05/23 14:25:41 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	col2hex(t_map *map)
{
	int	i;

	i = 0;
	map->fl = 0;
	map->cl = 0;
	while (i < 3)
	{
		map->fl += (map->mp.fl[i]) * pow(256, 2 - i);
		map->cl += (map->mp.cl[i]) * pow(256, 2 - i);
		i++;
	}
}

void	sp_pst(t_map *map)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	map->sp = (t_sprite *)malloc(sizeof(t_sprite) * map->mp.spcnt);
	while (y < map->mp.map_height)
	{
		x = 0;
		while (x < ft_strlen(map->mp.map[y]))
		{
			if (map->mp.map[y][x] == '2')
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

int		init_img(t_map *map)
{
	map->no_img.img = mlx_xpm_file_to_image(map->mlx, map->mp.no_path,
	&map->no_w, &map->no_h);
	map->so_img.img = mlx_xpm_file_to_image(map->mlx, map->mp.so_path,
	&map->so_w, &map->so_h);
	map->ea_img.img = mlx_xpm_file_to_image(map->mlx, map->mp.ea_path,
	&map->ea_w, &map->ea_h);
	map->we_img.img = mlx_xpm_file_to_image(map->mlx, map->mp.we_path,
	&map->we_w, &map->we_h);
	map->s_img.img = mlx_xpm_file_to_image(map->mlx, map->mp.s_path,
	&map->sp_w, &map->sp_h);
	if (map->no_img.img == NULL || map->so_img.img == NULL || map->ea_img.img
	== NULL || map->we_img.img == NULL || map->s_img.img == NULL)
		return (error_msg(-1));
	map->no_img.addr = mlx_get_data_addr(map->no_img.img, &map->no_img.bpp,
	&map->no_img.line_size, &map->no_img.endian);
	map->so_img.addr = mlx_get_data_addr(map->so_img.img, &map->so_img.bpp,
	&map->so_img.line_size, &map->so_img.endian);
	map->ea_img.addr = mlx_get_data_addr(map->ea_img.img, &map->ea_img.bpp,
	&map->ea_img.line_size, &map->ea_img.endian);
	map->we_img.addr = mlx_get_data_addr(map->we_img.img, &map->we_img.bpp,
	&map->we_img.line_size, &map->we_img.endian);
	map->s_img.addr = mlx_get_data_addr(map->s_img.img, &map->s_img.bpp,
	&map->s_img.line_size, &map->s_img.endian);
	return (0);
}

int		init_map(t_map *map, t_mpinf *mp)
{
	if (mp->size[0] >= mp->max_width)
		mp->size[0] = mp->max_width;
	if (mp->size[1] >= mp->max_height)
		mp->size[1] = mp->max_height;
	map->mp = *mp;
	map->cube_w = mp->size[0] / mp->map_width;
	map->cube_h = mp->size[1] / mp->map_height;
	map->mp.player_x += 0.5;
	map->mp.player_y += 0.5;
	map->pressed = 0;
	player_dir(map);
	sp_pst(map);
	col2hex(map);
	map->img.img = mlx_new_image(map->mlx, map->mp.size[0], map->mp.size[1]);
	map->img.addr = mlx_get_data_addr(map->img.img, &map->img.bpp,
	&map->img.line_size, &map->img.endian);
	if (init_img(map) == -1)
	{
		free(mp->map);
		free(mp);
		return (-1);
	}
	return (0);
}

int		cub3d(t_mpinf *mp)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	map;

	if ((mlx_ptr = mlx_init()) == NULL)
		return (error_msg(-7));
	map.mlx = mlx_ptr;
	mlx_get_screen_size(mlx_ptr, &mp->max_width, &mp->max_height);
	if (init_map(&map, mp) == -1)
		return (-1);
	if ((win_ptr = mlx_new_window(mlx_ptr, mp->size[0], mp->size[1],
	"cub3D")) == NULL)
		return (error_msg(-8));
	map.win = win_ptr;
	draw_loop(&map);
	if (map.mp.save != 1)
	{
		printf("cub3D is running\n");
		key_loop(&map);
		mlx_loop(map.mlx);
	}
	return (0);
}
