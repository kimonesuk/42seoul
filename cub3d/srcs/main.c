/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 08:44:36 by okim              #+#    #+#             */
/*   Updated: 2021/05/19 00:09:08 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_inf(t_mpinf *mpinf)
{
	mpinf->size[0] = 0;
	mpinf->size[1] = 0;
	mpinf->map_height = 0;
	mpinf->map_width = 0;
	mpinf->max_height = 0;
	mpinf->max_width = 0;
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
}

int		main(int argc, char *argv[])
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
	init_inf(mpinf);
	if (map_parsing(map_path, mpinf) == -1)
		return (-1);
	if (argc == 3 && ft_strncmp(argv[2], "--save", 6) == 0)
	{
		mpinf->save = 1;
		return (cub3d(mpinf));
	}
	else if (argc == 3)
		return (error_msg(-5));
	else
		return (cub3d(mpinf));
	free(mpinf);
	return (0);
}
