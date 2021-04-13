/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 08:44:36 by okim              #+#    #+#             */
/*   Updated: 2021/04/14 02:31:03 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	press_esc_key(int key, void *param)
{
	if (key == 53 && param)
	{
		write(1, "The Window is stopped.\n", 23);
		exit(0);
	}
	return (0);
}

void	init_inf(t_mpinf *mpinf)
{
	mpinf->width = 9999;
	mpinf->length = 9999;
	mpinf->map_height = 0;
	mpinf->map_width = 0;
	mpinf->FL[0] = 300;
	mpinf->FL[1] = 300;
	mpinf->FL[2] = 300;
	mpinf->CL[0] = 300;
	mpinf->CL[1] = 300;
	mpinf->CL[2] = 300;
}

int	main(int argc, char *argv[])
{
	char	*map_path;
	int		map_len;
	void	*mlx_ptr;
	void	*win_ptr;
	t_mpinf	*mpinf;

	if (argc < 2 || argc > 3)
	{
		write(1, "Invalid input.\n", 15);
		return (-1);
	}
	map_path = ft_strdup(argv[1]);
	map_len = ft_strlen(map_path);
	if (map_len < 5 || (ft_strncmp(&map_path[map_len - 4], ".cub", 4) != 0))
	{
		write(1, "Invalid map file.\n", 18);
		return (-1);
	}
	mpinf = (t_mpinf *)malloc(sizeof(t_mpinf));
	init_inf(mpinf);
	if (map_parsing(map_path, mpinf) == -1)
		return (-1);
	if (argc == 3 && ft_strlen(argv[2]) == 6 && ft_strncmp(argv[2], "--save", 6) == 0)
	{
		printf("--save is inputed\n");
		return (0);
	}
	else if (argc == 3)
	{
		write(1, "Invalid input.\n", 15);
		return (-1);
	}
	else
	{
		if ((mlx_ptr = mlx_init()) == NULL)
		{
			write(1, "Can't Connect mlx\n", 18);
			return (-1);
		}
		if ((win_ptr = mlx_new_window(mlx_ptr, mpinf->width, mpinf->length, "cub3d")) == NULL)
		{
			write(1, "Can't open a new window\n", 24);
			return (-1);
		}
		mlx_key_hook(win_ptr, press_esc_key, win_ptr);
		mlx_loop(mlx_ptr);
// F5 : 96  <- : 123  -> : 124  A : 0  W : 13  S : 1  D : 2
	}
	return (0);
}
