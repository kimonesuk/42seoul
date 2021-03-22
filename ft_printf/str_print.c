/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 09:04:54 by okim              #+#    #+#             */
/*   Updated: 2021/03/22 20:46:07 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	c_len_chk(t_format *structs, va_list *arg)
{
	char	c;

	if (structs->length_char == 'l')
		c = (char)va_arg(*arg, wint_t);
	else
		c = va_arg(*arg, int);
	return (c);
}

int	c_flag_chk(char c, t_format *structs)
{
	int	rtn;

	rtn = structs->width;
	if (structs->minus > 0)
	{
		write(1, &c, 1);
		print_n(' ', rtn - 1);
	}
	else if (structs->zero > 0)
	{
		print_n('0', rtn - 1);
		write(1, &c, 1);
	}
	else
	{
		print_n(' ', rtn - 1);
		write(1, &c, 1);
	}
	if (rtn == 0)
		rtn = 1;
	return (rtn);
}

char	*str_len_chk(t_format *structs, va_list *arg)
{
	char	*str;

	if (structs->length_char == 'l')
		str = (char *)va_arg(*arg, wchar_t *);
	else
		str = va_arg(*arg, char *);
	return (str);
}

int	str_flag_chk(char *str, t_format *structs)
{
	int	rtn;

	rtn = structs->precision;
	if (rtn > structs->width)
		print_saved(str, rtn);
	else
	{
		rtn = structs->width;
		if (structs->minus > 0)
		{
			print_saved(str, structs->precision);
			print_n(' ', rtn - structs->precision);
		}
		else if (structs->zero > 0)
		{
			print_n('0', rtn - structs->precision);
			print_saved(str, structs->precision);
		}
		else
		{
			print_n(' ', rtn - structs->precision);
			print_saved(str, structs->precision);
		}
	}
	return (rtn);
}

int	str_print(t_format *structs, va_list *arg)
{
	int		len;
	char	c;
	char	*str;

	if (structs->specifier == 'c')
	{
		c = c_len_chk(structs, arg);
		len = c_flag_chk(c, structs);
	}
	else if (structs->specifier == 's')
	{
		str = str_len_chk(structs, arg);
		if (structs->precision == -2)
			structs->precision = 0;
		else if (structs->precision == -1)
			structs->precision = ft_strlen(str);
		else if (structs->precision > ft_strlen(str))
			structs->precision = ft_strlen(str);
		len = str_flag_chk(str, structs);
	}
	return (len);
}
