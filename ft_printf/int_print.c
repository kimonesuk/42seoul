/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 21:08:03 by okim              #+#    #+#             */
/*   Updated: 2021/03/21 02:00:01 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long   length_chk(char **format, t_format *structs, va_list arg)
{
    long long   nmb;

    if (structs->length_char == 'h')
        nmb = (short)va_arg(arg, int);
    else if (structs->length_char == 'H')
        nmb = (char)va_arg(arg, int);
    else if (structs->length_char == 'l')
        nmb = va_arg(arg, long);
    else if (structs->length_char == 'L')
        nmb = va_arg(arg, long long);
    else
        nmb = va_arg(arg, int);
    return (nmb);
}

int nmb_len(long long nmb)
{
    int len;

    len = 0;
    if (nmb == 0)
        return (1);
    if (nmb < 0)
        nmb = nmb * -1;
    while (nmb >= 1)
    {
        len++;
        nmb /= 10;
    }
    return (len);
}

int ntos(char **nmb_c, long long nmb, int len)
{
    int     sign;
    
    sign = 1;
    if (nmb < 0)
    {
        nmb = nmb * -1;
        sign = -1;
    }
    while (nmb >= 1 || len >= 0)
    {
        *(*nmb_c + sizeof(char) * (len - 1)) = nmb % 10 + 48;
        nmb /= 10;
        len--;
    }
    return (sign);
}

int int_print(char **format, t_format *structs, va_list arg)
{
    long long   nmb;
    int         len;
    int         sign;
    int         nmb_l;
    char*       nmb_c;

    nmb = length_chk(format, structs, arg);
    nmb_l = nmb_len(nmb);
    len = nmb_l == 0 > structs->width ? nmb_l : structs->width;
    len = structs->precision > len ? structs->precision : len;
    nmb_c = (char*)malloc(sizeof(char) * (nmb_l + 1));
    ft_memset(nmb_c, ' ', nmb_l);
    nmb_c[nmb_l] = '\0';
    sign = ntos(&nmb_c, nmb, nmb_l);
    return (len);
}