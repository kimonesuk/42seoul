/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:32:45 by okim              #+#    #+#             */
/*   Updated: 2021/04/14 01:45:18 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "mlx.h"
#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct	s_map_inf
{
	int	width;
	int	length;
	int	map_height;
	int	map_width;
	int	FL[3];
	int	CL[3];
	char	*NO_path;
	char	*SO_path;
	char	*WE_path;
	char	*EA_path;
	char	*S_path;
	char	**map;
}				t_mpinf;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		map_parsing(char *map_path, t_mpinf *mpinf);
int		ft_atoi(const char *s);

#endif