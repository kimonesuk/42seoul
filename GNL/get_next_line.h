/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 09:43:29 by okim              #+#    #+#             */
/*   Updated: 2021/02/07 04:14:07 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define FD_MAX 256

int		get_next_line(int fd, char **line);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strdup(const char *s1);
size_t	chk_slice(char **line, char **stored, size_t idx);
size_t	idx_newline(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);

#endif
