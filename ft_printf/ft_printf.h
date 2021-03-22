/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:51:09 by okim              #+#    #+#             */
/*   Updated: 2021/03/22 10:21:41 by okim             ###   ########.fr       */
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
	int	precision;
	char	length_char;
	char	specifier;
}				t_format;

int	ft_printf(const char *format, ...);
int	print_saved(char *format, int len);
int	new_structs(t_format *structs);
int	format_parser(char **format, t_format *structs, va_list *arg);
int	print_format(char **format, t_format *structs, va_list *arg);
int	print_n(char c, int len);
int	flag_chk_int(char **nmb, t_format *structs, int nmb_len, int len, int sign);
int int_print(char **format, t_format *structs, va_list *arg);
int	float_print(char **format, t_format *structs, va_list *arg);
int	str_print(char **format, t_format *structs, va_list *arg);
int	etc_print(char **format, t_format *structs, va_list *arg);

#endif