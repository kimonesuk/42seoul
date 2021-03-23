/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 09:05:52 by okim              #+#    #+#             */
/*   Updated: 2021/03/24 00:50:33 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	conv_eE(t_format *structs, double nmb)
// {
// 	int	len;

// 	len = 0;
// 	if (structs->specifier = 'e')
// 	{
// 		return (0);
// 	}
// 	else if (structs->specifier = 'E')
// 	{
// 		return (0);
// 	}
// 	else
// 		return (0);
// 	return (len);
// }

// int	conv_f(t_format *structs, double nmb)
// {
// 	int	len;

// 	len = 0;

// 	return (len);
// }

int float_print(t_format *structs, va_list *arg)
{
	double	nmb;
	// int		len_f;
	// int		len_e;
	
	nmb = va_arg(*arg, double);
	// //len_f = len();
	// //len_e = len();
	if (structs->specifier == 'g')
		return (0);
	// // {
	// // 	if (len_f > len_e)
	// // 		structs->specifier = 'e';
	// // 	else
	// // 		structs->specifier = 'f';
	// // }
	// // else if (structs->specifier == 'e' || structs->specifier == 'E')
	// // 	len_f = conv_eE(structs, nmb); // 변환 & 출력
	// // else if (structs->specifier == 'f')
	// // 	len_f = conv_f(structs, nmb); // 변환 & 출력
	// // else
	// // 	return (0);
	return (0);
}
