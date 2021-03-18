/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:28:20 by okim              #+#    #+#             */
/*   Updated: 2021/03/18 09:35:06 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int spec_len_print(char **format, t_format *structs, va_list arg)
{
    if (structs->precision == 'l')
    {
        if (structs->specifier == 'd' || structs->specifier == 'i')
            structs->content = va_arg(arg, long int);
        else if (structs->specifier == 'u' || structs->specifier == 'x' || structs->specifier == 'X')
            structs->content = va_arg(arg, unsigned long int);
        else if (structs->specifier == 'n')
            structs->content = va_arg(arg, long int*);
        else if (structs->specifier == 'c')
            structs->content = va_arg(arg, wint_t);
        else if (structs->specifier == 's')
            structs->content = va_arg(arg, wchar_t*);
        else if (structs->specifier == 'f' || structs->specifier == 'e' || structs->specifier == 'g')
            structs->content = va_arg(arg, double);
    }
    else if (structs->precision == 'L')
    {
        if (structs->specifier == 'd' || structs->specifier == 'i')
            structs->content = va_arg(arg, long long int);
        else if (structs->specifier == 'u' || structs->specifier == 'x' || structs->specifier == 'X')
            structs->content = va_arg(arg, unsigned long long int);
        else if (structs->specifier == 'n')
            structs->content = va_arg(arg, long long int*);
    }
    else if (structs->precision == 'h')
    {
        if (structs->specifier == 'd' || structs->specifier == 'i')
            structs->content = va_arg(arg, short int);
        else if (structs->specifier == 'u' || structs->specifier == 'x' || structs->specifier == 'X')
            structs->content = va_arg(arg, unsigned short int);
        else if (structs->specifier == 'n')
            structs->content = va_arg(arg, short int*);
    }
    else if (structs->precision == 'H')
    {
        if (structs->specifier == 'd' || structs->specifier == 'i')
            structs->content = va_arg(arg, signed char);
        else if (structs->specifier == 'u' || structs->specifier == 'x' || structs->specifier == 'X')
            structs->content = va_arg(arg, unsigned char);
        else if (structs->specifier == 'n')
            structs->content = va_arg(arg, signed char*);
    }
    else if (structs->content == 0)
    {
    if (structs->specifier == 'd' || structs->specifier == 'i' || structs->specifier == 'c')
        structs->content = va_arg(arg, int);
    else if (structs->specifier == 'u' || structs->specifier == 'x' || structs->specifier == 'X')
        structs->content = va_arg(arg, unsigned int);
    else if (structs->specifier == 'n')
        structs->content = va_arg(arg, int*);
    else if (structs->specifier == 's')
        structs->content = va_arg(arg, char*);
    else if (structs->specifier == 'p' || structs->specifier == '%')
        structs->content = va_arg(arg, void*);
    else if (structs->specifier == 'f' || structs->specifier == 'e' || structs->specifier == 'g')
        structs->content = va_arg(arg, float);
    }
    return (0);
}

int width_prec_print(char **format, t_format *structs)
{

}

int flag_print(char **format, t_format *structs)
{

}

int print_format(char **format, t_format *structs, va_list arg)
{
    spec_len_print(format, structs, arg);
    printf("")
    //width_prec_print(format, structs);
    //structs->rtn=flag_print(format, structs);
    return (structs->rtn);
}