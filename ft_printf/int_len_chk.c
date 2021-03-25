/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_len_chk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:02:32 by okim              #+#    #+#             */
/*   Updated: 2021/03/25 18:05:46 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int	signed_length_chk(t_format *structs, va_list *arg)
{
	long long int	nmb;

	if (structs->length_char == 'h')
		nmb = (short)va_arg(*arg, int);
	else if (structs->length_char == 'H')
		nmb = (signed char)va_arg(*arg, int);
	else if (structs->length_char == 'l')
		nmb = va_arg(*arg, long int);
	else if (structs->length_char == 'L')
		nmb = va_arg(*arg, long long int);
	else
		nmb = va_arg(*arg, int);
	return (nmb);
}

long long int	unsigned_length_chk(t_format *structs, va_list *arg)
{
	long long int	nmb;

	if (structs->length_char == 'h')
		nmb = (unsigned short)va_arg(*arg, unsigned int);
	else if (structs->length_char == 'H')
		nmb = (unsigned char)va_arg(*arg, int);
	else if (structs->length_char == 'l')
		nmb = va_arg(*arg, unsigned long int);
	else if (structs->length_char == 'L')
		nmb = va_arg(*arg, unsigned long long int);
	else
		nmb = va_arg(*arg, unsigned int);
	return (nmb);
}
