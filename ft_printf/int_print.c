/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 21:08:03 by okim              #+#    #+#             */
/*   Updated: 2021/03/20 01:29:27 by okim             ###   ########.fr       */
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
    if (nmb < 0)
    {
        nmb = nmb * -1;
        len++;
    }
    while (nmb > 0)
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
    while (nmb > 0 || len > 0)
    {
        *(*nmb_c + sizeof(char) * len) = nmb % 10 + 48;
        nmb /= 10;
        len--;
    }
    return (sign);
}

int flag_chk(char **nmb, t_format *structs, long long n, int nmb_len, int len, int sign)
{
    if (structs->minus > 0)
    {
        ft_memset(*nmb, ' ', len - 1);
        ntos(nmb, n, nmb_len);
    }
    else if (structs->zero > 0)
        ft_memset((void*)*nmb, '0', len - nmb_len);
    if (sign > 0)
        if (structs->plus > 0)
            **nmb = '+';
        else if (structs->space > 0)
            **nmb = ' ';
    else
        **nmb = '-';
    return (1);
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
    len = nmb_l > structs->precision ? nmb_l : structs->precision;
    len = structs->width > len ? structs->width : len;
    len = structs->plus > 0 || structs->space > 0 || nmb < 0 ? len + 1 : len;
    nmb_c = (char*)malloc(sizeof(char) * (len + 1));
    ft_memset((void*)nmb_c, ' ', len);
    nmb_c[len] = '\0';
    sign = ntos(&nmb_c, nmb, len - 1);
    flag_chk(&nmb_c, structs, nmb, nmb_l, len, sign);
    print_str(nmb_c, len);
    return (len);
}