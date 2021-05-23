/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 08:44:36 by okim              #+#    #+#             */
/*   Updated: 2021/05/23 12:29:23 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	init_inf(char *map_path, t_mpinf *mpinf)
{
	mpinf->size[0] = 0;
	mpinf->size[1] = 0;
	mpinf->map_height = 0;
	mpinf->map_width = 0;
	mpinf->player_x = 0;
	mpinf->player_y = 0;
	mpinf->player_v = 0;
	mpinf->spcnt = 0;
	mpinf->save = 0;
	mpinf->fl[0] = -1;
	mpinf->fl[1] = -1;
	mpinf->fl[2] = -1;
	mpinf->cl[0] = -1;
	mpinf->cl[1] = -1;
	mpinf->cl[2] = -1;
	if (map_parsing(map_path, mpinf) == -1)
	{
		free(map_path);
		free(mpinf);
		return (-1);
	}
	free(map_path);
	return (0);
}

int	main(int argc, char *argv[])
{
	char	*map_path;
	int		map_len;
	t_mpinf	*mpinf;

	if (argc < 2 || argc > 3)
		return (error_msg(-5));
	map_path = ft_strdup(argv[1]);
	map_len = ft_strlen(map_path);
	if (map_len < 5 || (ft_strncmp(&map_path[map_len - 4], ".cub", 4) != 0))
		return (error_msg(-6));
	mpinf = (t_mpinf *)malloc(sizeof(t_mpinf));
	if (init_inf(map_path, mpinf) == -1)
		return (-1);
	if (argc == 3 && ft_strncmp(argv[2], "--save", 6) == 0)
		mpinf->save = 1;
	else if (argc == 3)
	{
		free(mpinf);
		return (error_msg(-5));
	}
	return (cub3d(mpinf));
}
