/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:32:45 by okim              #+#    #+#             */
/*   Updated: 2021/04/27 09:57:17 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "mlx.h"
#include "mlxgl.h"
#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>

typedef struct	s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

typedef struct	s_map_inf
{
	int		size[2];
	int		max_width;
	int		max_height;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	char	player_v;
	int		FL[3];
	int		CL[3];
	char	*NO_path;
	char	*SO_path;
	char	*WE_path;
	char	*EA_path;
	char	*S_path;
	char	**map;
	t_list	*map_lst;
}				t_mpinf;

typedef struct	s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_size;
	int			endian;
}				t_img;

typedef struct	s_map
{
	void		*mlx;
	void		*win;
	int			cube_width;
	int			cube_height;
	t_img		img;
	t_mpinf		mpinf;
}				t_map;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isdigit(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*skip_space(char *str);
t_list	*ft_lstnew(char *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	*ft_memset(char *b, int c, size_t len);
int		error_msg(int error_n);
int		map_parsing(char *map_path, t_mpinf *mpinf);
int		map_save(int fd, t_mpinf *mpinf);
int		cub3d(t_mpinf *mpinf);
int		press_key(int key, void *param);

#endif