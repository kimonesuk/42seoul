/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:32:45 by okim              #+#    #+#             */
/*   Updated: 2021/04/24 21:14:53 by okim             ###   ########.fr       */
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

typedef struct	s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

typedef struct	s_map_inf
{
	int	size[2];
	int	map_height;
	int	map_width;
	int	FL[3];
	int	CL[3];
	int	max_width;
	int	max_length;
	char	*NO_path;
	char	*SO_path;
	char	*WE_path;
	char	*EA_path;
	char	*S_path;
	char	**map;
	t_list	*map_lst;
}				t_mpinf;

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
int		error_msg(int error_n);
int		map_parsing(char *map_path, t_mpinf *mpinf);
int		map_save(int fd, t_mpinf *mpinf);

#endif