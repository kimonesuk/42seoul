/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:28:20 by okim              #+#    #+#             */
/*   Updated: 2021/03/22 12:25:39 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_format(char **format, t_format *structs, va_list *arg)
{
    int rtn;

    rtn = 0;
    //structs->precision == -2인 경우 . 만 있는 경우
    if (ft_strchr("diuoxX", structs->specifier) != 0)
        rtn = int_print(format, structs, arg);
    else if (ft_strchr("eEfg", structs->specifier) != 0)
        rtn = float_print(format, structs, arg);
    else if (ft_strchr("sc", structs->specifier) != 0)
        rtn = str_print(format, structs, arg);
    else
        rtn = etc_print(format, structs, arg);
    return (rtn);
}
