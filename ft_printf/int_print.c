/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 21:08:03 by okim              #+#    #+#             */
/*   Updated: 2021/03/27 01:25:51 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_sign(t_format *structs, long long int nmb)
{
	if (structs->plus > 0)
	{
		if (nmb < 0)
			write(1, "-", 1);
		else
			write(1, "+", 1);
	}
	else if (structs->space > 0)
	{
		if (nmb < 0)
			write(1, "-", 1);
		else
			write(1, " ", 1);
	}
	else if (nmb < 0)
		write(1, "-", 1);
	else
		return (0);
	return (1);
}

int	tmp_int_len(t_format *structs, long long int nmb)
{
	if (structs->space > 0 || structs->plus > 0 || nmb < 0)
		return (1);
	else
		return (0);
}

void	print_int(t_format *structs, char *nmb_c, int len, long long int nmb)
{	
	int	tmp;

	if (structs->minus > 0)
	{
		tmp = print_sign(structs, nmb);
		print_n('0', structs->precision - len);
		print_saved(nmb_c, len);
		if (structs->precision < len)
			structs->precision = len;
		print_n(' ', structs->width - structs->precision - tmp);
	}
	else
	{
		tmp = tmp_int_len(structs, nmb);
		if (structs->zero > 0 && structs->precision < 0)
			structs->precision = structs->width - tmp;
		if (structs->precision < len)
			structs->precision = len;
		print_n(' ', structs->width - structs->precision - tmp);
		print_sign(structs, nmb);
		print_n('0', structs->precision - len);
		print_saved(nmb_c, len);
	}
}

int	int_print(t_format *structs, va_list *arg)
{
	long long int	nmb;
	int				len;
	int				max;
	char			*nmb_c;

	nmb = signed_length_chk(structs, arg);
	len = base_len(nmb, 10);
	nmb_c = (char *)malloc(sizeof(char) * len);
	conv_z(nmb, &nmb_c);
	if (structs->precision == 0 && nmb == 0)
		len = 0;
	max = len;
	if (structs->precision > max)
		max = structs->precision;
	if (nmb < 0 || structs->space > 0 || structs->plus > 0)
		max += 1;
	if (structs->width > max)
		max = structs->width;
	print_int(structs, nmb_c, len, nmb);
	free(nmb_c);
	return (max);
}
