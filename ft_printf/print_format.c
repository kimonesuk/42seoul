/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:28:20 by okim              #+#    #+#             */
/*   Updated: 2021/03/20 00:24:26 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
int float_print(char **format, t_format *structs, va_list arg) // f, e, g
{
    if (structs->specifier == 'f')
    {
        
    }
    else if (structs->specifier == 'e')
    {
        
    }
    else if (structs->specifier == 'g')
    {
        
    }
}

int base_print(char **format, t_format *structs, va_list arg) // o, x, X, u
{
    
}

int str_print(char **format, t_format *structs, va_list arg) // c, s
{
    
}

int etc_print(char **format, t_format *structs, va_list arg) // p, %, n, etc
{

}
*/
int print_format(char **format, t_format *structs, va_list arg)
{
    //printf("\nzero : %d, minus : %d, number : %d, space : %d\nplus : %d, width : %d, precision : %d\nspecifier : %c\n", structs->zero, structs->minus, structs->number, structs->space, structs->plus, structs->width, structs->precision, structs->specifier);
    if (structs->specifier == 'd' || structs->specifier == 'i')
        structs->rtn = int_print(format, structs, arg);
    // else if (structs->specifier == 'f' || structs->specifier == 'e' || structs->specifier == 'g')
    //     structs->rtn = float_print(&format, structs, arg);
    // else if (structs->specifier == 'o' || structs->specifier == 'x' || structs->specifier == 'X'  || structs->specifier == 'u')
    //     structs->rtn = base_print(&format, structs, arg);
    // else if (structs->specifier == 'c' || structs->specifier == 's')
    //     structs->rtn = str_print(&format, structs, arg);
    // else
    //     structs->rtn = etc_print(&format, structs, arg);
    return (structs->rtn);
}