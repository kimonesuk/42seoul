/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 09:43:29 by okim              #+#    #+#             */
/*   Updated: 2021/02/09 17:51:20 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define FD_MAX 32

int		get_next_line_bonus(int fd, char **line);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strdup(const char *s1);
int		chk_slice(char **line, char **stored, int idx);
int		idx_newline(const char *str);
int		ft_strlcpy(char *dst, const char *src, int dstsize);
int		ft_strlcat(char *dst, const char *src, int dstsize);
int		ft_strlen(const char *str);

#endif