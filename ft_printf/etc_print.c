/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 09:06:50 by okim              #+#    #+#             */
/*   Updated: 2021/03/22 21:15:23 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	n_len_chk(t_format *structs, va_list *arg)
{
	if (structs->length_char == 'l')
		g_n = (int *)va_arg(*arg, long int *);
	else if (structs->length_char == 'L')
		g_n = (int *)va_arg(*arg, long long int *);
	else if (structs->length_char == 'h')
		g_n = (int *)va_arg(*arg, short int *);
	else if (structs->length_char == 'H')
		g_n = (int *)va_arg(*arg, signed char *);
	else
		g_n = va_arg(*arg, int *);
	if (g_n != 0)
		*g_n = structs->rtn;
	return (1);
}

int etc_flag_chk(t_format *structs)
{
	int	len;

	len = 1;
	if (structs->width > 0)
		len = structs->width;
	if (structs->minus > 0)
	{
		write(1, &structs->specifier, 1);
		print_n(' ', len - 1);
	}
	else if (structs->zero > 0)
	{
		print_n('0', len - 1);
		write(1, &structs->specifier, 1);
	}
	else
	{
		print_n(' ', len - 1);
		write(1, &structs->specifier, 1);
	}
	return (len);
}


int	p_flag_chk(t_format *structs, va_list *arg)
{
	int	len;

	return (len);
}

int	etc_print(t_format *structs, va_list *arg)
{
	int	len;

	if (structs->specifier == '%')
		len = etc_flag_chk(structs);
	else if (structs->specifier == 'n')
		n_len_chk(structs, arg);
	else if (structs->specifier == 'p')
		len = p_flag_chk(structs, arg);
	else
		len = etc_flag_chk(structs);
	return (len);
}