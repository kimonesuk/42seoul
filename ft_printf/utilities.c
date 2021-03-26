/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 20:58:54 by okim              #+#    #+#             */
/*   Updated: 2021/03/26 09:08:47 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	new_structs(t_format *structs)
{
	structs->zero = 0;
	structs->minus = 0;
	structs->number = 0;
	structs->space = 0;
	structs->plus = 0;
	structs->width = 0;
	structs->precision = -1;
	structs->rtn = 0; //
	structs->length_char = 'd';
	return (1);
}

int	print_n(char c, int len)
{
	int	rtn;

	rtn = len;
	while (len-- > 0)
		write(1, &c, 1);
	return (rtn);
}

int	print_saved(char *format, int len)
{
	write(1, format, len);
	return (len);
}
