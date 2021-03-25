/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 09:06:50 by okim              #+#    #+#             */
/*   Updated: 2021/03/25 20:06:03 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	n_len_chk(t_format *structs, va_list *arg)
{
	int	*tmp;

	if (structs->length_char == 'l')
		tmp = (int *)va_arg(*arg, long int *);
	else if (structs->length_char == 'L')
		tmp = (int *)va_arg(*arg, long long int *);
	else if (structs->length_char == 'h')
		tmp = (int *)va_arg(*arg, short int *);
	else if (structs->length_char == 'H')
		tmp = (int *)va_arg(*arg, signed char *);
	else
		tmp = va_arg(*arg, int *);
	if (tmp != 0)
		*tmp = structs->rtn;
	return (1);
}

int	etc_flag_chk(t_format *structs)
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

int	p_conv(va_list *arg, char **ptr)
{
	long long int	nmb;
	int				i;
	int				j;
	char			r_ptr[15];

	i = 0;
	j = 0;
	nmb = (long long int)va_arg(*arg, void *);
	while (nmb >= 16)
	{
		r_ptr[i++] = "0123456789abcdef" [nmb % 16];
		nmb /= 16;
	}
	r_ptr[i] = "0123456789abcdef" [nmb];
	while (i >= 0)
		*(*ptr + sizeof(char) * j++) = r_ptr[i--];
	*(*ptr + sizeof(char) * j) = '\0';
	return (j);
}

int	p_flag_chk(t_format *structs, char *ptr, int len, int max)
{
	if (structs->precision > max)
		max = structs->precision + 2;
	if (structs->width > max)
		max = structs->width;
	if (structs->minus > 0)
	{
		write(1, "0x", 2);
		print_n('0', structs->precision - len);
		print_saved(ptr, len);
		if (structs->precision < len)
			structs->precision = len;
		print_n(' ', structs->width - structs->precision - 2);
	}
	else
	{
		if (structs->precision < len)
			structs->precision = len;
		print_n(' ', structs->width - structs->precision - 2);
		write(1, "0x", 2);
		print_n('0', structs->precision - len);
		print_saved(ptr, len);
	}
	return (max);
}

int	etc_print(t_format *structs, va_list *arg)
{
	int		len;
	int		max;
	char	*ptr;

	len = 0;
	if (structs->specifier == '%')
		len = etc_flag_chk(structs);
	else if (structs->specifier == 'n')
		len = n_len_chk(structs, arg);
	else if (structs->specifier == 'p')
	{
		ptr = (char *)malloc(sizeof(char) * 9);
		len = p_conv(arg, &ptr);
		if (structs->precision == -2 || structs->precision == 0)
			len = 0;
		max = len + 2;
		len = p_flag_chk(structs, ptr, len, max);
		free (ptr);
	}
	else
		len = etc_flag_chk(structs);
	return (len);
}
