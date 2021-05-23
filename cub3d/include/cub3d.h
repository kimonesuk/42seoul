/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:32:45 by okim              #+#    #+#             */
/*   Updated: 2021/05/23 09:09:12 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "mlxgl.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <math.h>

# define _USE_MATH_DEFINES
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17

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
	int		spcnt;
	int		save;
	int		flag;
	double	player_x;
	double	player_y;
	char	player_v;
	int		fl[3];
	int		cl[3];
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*s_path;
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

typedef	struct	s_sprite
{
	double		x;
	double		y;
}				t_sprite;

typedef struct	s_map
{
	void		*mlx;
	void		*win;
	double		cube_w;
	double		cube_h;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		raydirx;
	double		raydiry;
	int			fl;
	int			cl;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			mapx;
	int			mapy;
	int			wstart;
	int			wend;
	int			xi;
	int			pressed;
	int			no_w;
	int			no_h;
	int			so_w;
	int			so_h;
	int			ea_w;
	int			ea_h;
	int			we_w;
	int			we_h;
	int			sp_w;
	int			sp_h;
	double		sidex;
	double		sidey;
	double		deltax;
	double		deltay;
	double		wdist;
	double		*distarr;
	double		*sp_dist;
	int			color;
	double		texx;
	double		texy;
	double		wallx;
	double		wally;
	t_img		no_img;
	t_img		so_img;
	t_img		we_img;
	t_img		ea_img;
	t_img		s_img;
	t_img		img;
	t_mpinf		mp;
	t_sprite	*sp;
}				t_map;

typedef	struct	s_sprite_draw
{
	double		sprx;
	double		spry;
	double		invd;
	double		transx;
	double		transy;
	int			sprsnx;
	int			stripe;
	int			sprh;
	int			starty;
	int			endy;
	int			sprw;
	int			startx;
	int			endx;
	int			texx;
	int			texy;
	int			color;
	int			y;
}				t_sprd;

int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_isdigit(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
t_list			*ft_lstnew(char *content);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			*ft_memset(char *b, int c, size_t len);
char			*skip_space(char *str);
int				error_msg(int error_n);
int				map_parsing(char *map_path, t_mpinf *mpinf);
int				map_save(int fd, t_mpinf *mpinf);
int				save_bmp(t_map *map);
void			player_dir(t_map *map);
void			my_mlx_pixel_put(t_img *img, double x, double y, int color);
int				my_mlx_pixel_get(t_img *img, double x, double y);
double			cast_single_ray(t_map *map);
int				set_texture(t_map *map, double dy);
void			draw_sprite(t_map *map);
void			draw_loop(t_map *map);
void			press_ad(int key, t_map *map);
void			press_ws(int key, t_map *map);
void			press_arrow(int key, t_map *map);
void			release_arrow(int key, t_map *map);
void			key_loop(t_map *map);
int				cub3d(t_mpinf *mpinf);

#endif
