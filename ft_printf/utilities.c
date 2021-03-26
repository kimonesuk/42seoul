/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 20:58:54 by okim              #+#    #+#             */
/*   Updated: 2021/03/27 01:49:44 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	base_len(long long int nmb, int base)
{
	int	len;

	len = 0;
	if (nmb < 0)
		nmb = nmb * -1;
	while (nmb >= base)
	{
		len++;
		nmb /= base;
	}
	len++;
	return (len);
}

int	conv_z(long long int nmb, char **z)
{
	char	r_z[255];
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (nmb < 0)
		nmb = nmb * -1;
	while (nmb >= 10)
	{
		r_z[i++] = "0123456789" [nmb % 10];
		nmb /= 10;
	}
	r_z[i] = "0123456789" [nmb];
	while (i >= 0)
		*(*z + sizeof(char) * j++) = r_z[i--];
	*(*z + sizeof(char) * j) = '\0';
	return (1);
}

int	new_structs(t_format *structs)
{
	structs->zero = 0;
	structs->minus = 0;
	structs->number = 0;
	structs->space = 0;
	structs->plus = 0;
	structs->width = 0;
	structs->precision = -1;
	structs->rtn = 0;
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
