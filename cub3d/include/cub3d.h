/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:32:45 by okim              #+#    #+#             */
/*   Updated: 2021/04/07 19:49:35 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "mlx.h"
#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_map_inf
{
	int	width;
	int	length;
	int	FL[3];
	int	CL[3];
	char	*NO_txt;
	char	*SO_txt;
	char	*WE_txt;
	char	*EA_txt;
	char	*S_txt;
	char	**map;
}				t_mpinf;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		map_parsing(char *map_path, t_mpinf *mpinf);

#endif