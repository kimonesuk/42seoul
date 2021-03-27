/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 19:07:52 by okim              #+#    #+#             */
/*   Updated: 2021/03/27 10:08:26 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	base_chk(t_format *str, unsigned long long nmb, int *len, char **nmb_c)
{
	if (str->specifier == 'u')
	{
		*len = unsigned_base_len(nmb, 10);
		*nmb_c = (char *)malloc(sizeof(char) * *len + 1);
		unsigned_conv_z(nmb, nmb_c);
	}
	else if (str->specifier == 'o')
	{
		*len = unsigned_base_len(nmb, 8);
		*nmb_c = (char *)malloc(sizeof(char) * *len + 1);
		conv_oct(nmb, nmb_c);
	}
	else if (str->specifier == 'x')
	{
		*len = unsigned_base_len(nmb, 16);
		*nmb_c = (char *)malloc(sizeof(char) * *len + 1);
		conv_hex_h(nmb, nmb_c);
	}
	else if (str->specifier == 'X')
	{
		*len = unsigned_base_len(nmb, 16);
		*nmb_c = (char *)malloc(sizeof(char) * *len + 1);
		conv_hex_hh(nmb, nmb_c);
	}
}

int		print_number_flag(t_format *structs, char *nmb)
{
	int	nbfg;

	nbfg = structs->number;
	if (nbfg > 0 && ft_strchr("oxX", structs->specifier) && (*nmb != '0'))
	{
		write(1, "0", 1);
		if (structs->specifier == 'x')
			write(1, "x", 1);
		else if (structs->specifier == 'X')
			write(1, "X", 1);
		else
			return (1);
		return (2);
	}
	return (0);
}

int		tmp_len(t_format *structs, char *nmb)
{
	int	tmp;
	int	nbfg;

	nbfg = structs->number;
	if (nbfg > 0 && structs->specifier == 'o' && *nmb != '0')
		tmp = 1;
	else if (nbfg > 0 && ft_strchr("xX", structs->specifier) && *nmb != '0')
		tmp = 2;
	else
		tmp = 0;
	return (tmp);
}

void	print_base(t_format *structs, char *nmb, int len)
{
	int	tmp;

	if (structs->minus > 0)
	{
		tmp = print_number_flag(structs, nmb);
		print_n('0', structs->precision - len);
		print_saved(nmb, len);
		if (structs->precision < len)
			structs->precision = len;
		print_n(' ', structs->width - structs->precision - tmp);
	}
	else
	{
		tmp = tmp_len(structs, nmb);
		if (structs->zero > 0 && structs->precision < 0)
			structs->precision = structs->width - tmp;
		if (structs->precision < len)
			structs->precision = len;
		print_n(' ', structs->width - structs->precision - tmp);
		print_number_flag(structs, nmb);
		print_n('0', structs->precision - len);
		print_saved(nmb, len);
	}
}

int		base_print(t_format *structs, va_list *arg)
{
	unsigned long long	nmb;
	int					len;
	int					max;
	char				*nmb_c;

	nmb = unsigned_length_chk(structs, arg);
	base_chk(structs, nmb, &len, &nmb_c);
	if (structs->precision == 0 && nmb == 0)
		len = 0;
	max = len;
	if (structs->precision > max)
		max = structs->precision;
	if (structs->number > 0 && structs->specifier == 'o' && nmb != 0)
		max += 1;
	if (structs->number > 0 && ft_strchr("xX", structs->specifier) && nmb != 0)
		max += 2;
	if (structs->width > max)
		max = structs->width;
	print_base(structs, nmb_c, len);
	free(nmb_c);
	return (max);
}
