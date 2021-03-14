/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:51:09 by okim              #+#    #+#             */
/*   Updated: 2021/03/14 16:08:27 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

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
	char	length_char;
	char	specifier;	
}				t_format;

int	ft_printf(const char *, ...);
int	format_parser();
int	flag_parser();
int	width_parser();
int	precision_parser();
int	lenght_parser();
int specifier_parser();

#endif;
