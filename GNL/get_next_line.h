/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 09:43:29 by okim              #+#    #+#             */
/*   Updated: 2021/01/31 22:06:18 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int		get_next_line(int fd, char **line);
char	*ft_strcpy_slice(char *buf, char *str, size_t start, size_t end);
size_t	have_end(const char *str, size_t size);
size_t	ft_strlen(const char *str);

#endif
