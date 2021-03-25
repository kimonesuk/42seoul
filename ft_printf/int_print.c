/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 21:08:03 by okim              #+#    #+#             */
/*   Updated: 2021/03/25 19:57:16 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(t_format *structs, char *nmb_c, int len, long long int nmb)
{
	int	max;

	max = len;
	if (nmb < 0 || structs->space > 0 || structs->plus > 0)
		structs->width = structs->width - 1;
	if (structs->precision == -2 || structs->precision == 0)
	{
		len = 0;
		structs->width++;
	}
	if (structs->zero > 0 && structs->precision < 0 && structs->minus <= 0)
		structs->precision = structs->width;
	if (structs->precision > max)
		max = structs->precision;
	if (structs->minus <= 0)
	{
		print_n(' ', structs->width - max);
		if (nmb < 0)
			write(1, "-", 1);
		else if (structs->plus > 0)
			write(1, "+", 1);
		else if (structs->space > 0)
			write(1, " ", 1);
		print_n('0', structs->precision - len);
		print_saved(nmb_c, len);
	}
	else
	{
		if (nmb < 0)
			write(1, "-", 1);
		else if (structs->plus > 0)
			write(1, "+", 1);
		else if (structs->space > 0)
			write(1, " ", 1);
		print_n('0', structs->precision - len);
		print_saved(nmb_c, len);
		print_n(' ', structs->width - max);
	}
	if (structs->width > max)
		max = structs->width;
	if (nmb < 0 || structs->space > 0 || structs->plus > 0)
		max++;
	if (structs->precision == -2 || structs->precision == 0)
		max--;
	return (max);
}

int	print_base(t_format *structs, char *nmb, int len)
{
	int	max;

	max = len;
	if (structs->number > 0 && ft_strchr("oxX", structs->specifier) && (*nmb != '0'))
		structs->width = structs->width - 2;
	if (structs->zero > 0 && structs->precision < 0 && structs->minus <= 0)
		structs->precision = structs->width;
	if (structs->precision > max)
		max = structs->precision;
	if (structs->precision == -2 || structs->precision == 0)
	{
		len = 0;
		structs->width++;
	}
	if (structs->minus <= 0)
	{
		print_n(' ', structs->width - max);
		if (structs->number > 0 && ft_strchr("oxX", structs->specifier) && (*nmb != '0'))
		{
			write(1, "0", 1);
			if (structs->specifier == 'x')
				write(1, "x", 1);
			else if (structs->specifier == 'X')
				write(1, "X", 1);
		}
		print_n('0', structs->precision - len);
		print_saved(nmb, len);
	}
	else
	{
		if (structs->number > 0 && ft_strchr("oxX", structs->specifier) && (*nmb != '0'))
		{
			write(1, "0", 1);
			if (structs->specifier == 'x')
				write(1, "x", 1);
			else if (structs->specifier == 'X')
				write(1, "X", 1);
		}
		print_n('0', structs->precision - len);
		print_saved(nmb, len);
		print_n(' ', structs->width - max);
	}
	if (structs->number > 0 && ft_strchr("oxX", structs->specifier))
		structs->width = structs->width + 2;
	if (structs->width > max)
		max = structs->width;
	if (structs->precision == -2 || structs->precision == 0)
		max--;
	return (max);
}

int	int_print(t_format *structs, va_list *arg)
{
	long long int	nmb;
	int				len;
	char			*nmb_c;

	len = 0;
	if (structs->specifier == 'd' || structs->specifier == 'i')
	{
		nmb = signed_length_chk(structs, arg);
		len = base_len(nmb, 10);
		nmb_c = (char *)malloc(sizeof(char) * len);
		conv_z(nmb, &nmb_c);
		len = print_int(structs, nmb_c, len, nmb);
		free(nmb_c);
	}
	else
	{
		nmb = unsigned_length_chk(structs, arg);
		if (structs->specifier == 'u')
		{
			len = base_len(nmb, 10);
			nmb_c = (char *)malloc(sizeof(char) * len + 1);
			conv_z(nmb, &nmb_c);
		}
		else if (structs->specifier == 'o')
		{
			len = base_len(nmb, 8);
			nmb_c = (char *)malloc(sizeof(char) * len + 1);
			conv_oct(nmb, &nmb_c);
		}
		else if (structs->specifier == 'x')
		{
			len = base_len(nmb, 16);
			nmb_c = (char *)malloc(sizeof(char) * len + 1);
			conv_hex_h(nmb, &nmb_c);
		}
		else if (structs->specifier == 'X')
		{
			len = base_len(nmb, 16);
			nmb_c = (char *)malloc(sizeof(char) * len + 1);
			conv_hex_H(nmb, &nmb_c);
		}
		else
			return (0);
		len = print_base(structs, nmb_c, len);
		free(nmb_c);
	}
	return (len);
}
