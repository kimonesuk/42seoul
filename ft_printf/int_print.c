/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 21:08:03 by okim              #+#    #+#             */
/*   Updated: 2021/03/20 02:38:14 by okim             ###   ########.fr       */
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
        nmb = nmb * -1;
    while (nmb > 1)
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

int flag_chk(char **nmb, t_format *structs, int nmb_len, int len, int sign)
{
    if (structs->minus > 0)
    {
        if (sign < 0)
            write(1, "-", 1);
        else
        {
            if (structs->plus > 0)
                write(1, "+", 1);
            else if (structs->space > 0)
                write(1, " ", 1);
        }
        print_str(*nmb, nmb_len + 1);
        print_n(' ', len - nmb_len - 2);
    }
    else
    {
        if (sign < 0)
            write(1, "-", 1);
        else
        {
            if (structs->plus > 0)
                write(1, "+", 1);
            else if (structs->space > 0)
                write(1, " ", 1);
        }
        if (structs->zero > 0)
            print_n('0', len - nmb_len - 2);
        else
            print_n(' ', len - nmb_len - 2);
        print_str(*nmb, nmb_len + 1);
    }
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
    nmb_c = (char*)malloc(sizeof(char) * (nmb_l + 1));
    ft_memset(nmb_c, ' ', nmb_l);
    nmb_c[nmb_l] = '\0';
    sign = ntos(&nmb_c, nmb, nmb_l);
    len = nmb_l > structs->precision ? nmb_l : structs->precision;
    len = structs->width > len ? structs->width : len;
    flag_chk(&nmb_c, structs, nmb_l, len, sign);
    return (len);
}