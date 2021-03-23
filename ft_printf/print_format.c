/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:28:20 by okim              #+#    #+#             */
/*   Updated: 2021/03/24 00:19:37 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_format(t_format *structs, va_list *arg)
{
	int rtn;

	rtn = 0;
	if (ft_strchr("diuoxX", structs->specifier) != 0)
		rtn = int_print(structs, arg);
	//else if (ft_strchr("eEfg", structs->specifier) != 0)
	//	rtn = float_print(structs, arg);
	else if (ft_strchr("sc", structs->specifier) != 0)
		rtn = str_print(structs, arg);
	else
		rtn = etc_print(structs, arg);
	return (rtn);
}
