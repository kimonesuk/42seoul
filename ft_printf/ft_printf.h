/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:51:09 by okim              #+#    #+#             */
/*   Updated: 2021/03/14 21:24:22 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"

typedef	struct	s_format_inf
{
	int	zero;
	int	minus;
	int	number;
	int	space;
	int	plus;
	int	width;
	int	tags;
	int	precision;
	int	rtn;
	char	length_char;
	char	specifier;	
}				t_format;

int	ft_printf(const char *format, ...);
char	*ft_strchr(char *format, char c);
int	ft_strlen(char *format);
int	print_str(char *format, int len);
int	format_parser(char **format, t_format *structs, va_list arg);
int	new_structs(t_format *structs);

#endif
