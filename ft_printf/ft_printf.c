/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:09:27 by okim              #+#    #+#             */
/*   Updated: 2021/03/14 21:23:19 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		rtn;
	char	*str;
	char	*target;
	t_format	*structs;
	va_list	arg;

	rtn = 0;
	va_start(arg, format);
	str = (char*)format;
	target = str;
	while (ft_strchr(target, '%'))
	{
		target = ft_strchr(target, '%');
		rtn += print_str(str, target++ - str);
		//printf("\nbefore target : %p, %c\n", target, target[0]);
		structs = (t_format*)malloc(sizeof(t_format));
		new_structs(structs);
		format_parser(&target, structs, arg);
		//rtn += print_format(&target, structs, arg);
		printf("\nplus : %d, minus : %d, space : %d, zero : %d\n", structs->plus, structs->minus, structs->space, structs->zero);
		printf("width : %d, precision : %d\n", structs->width, structs->precision);
		printf("length_char : %c\n", structs->length_char);
		printf("specifier : %c\n", structs->specifier);
		free(structs);
		//printf("after target : %p, %c\n", target, target[0]);
	}
	rtn += print_str(target, ft_strlen(target));
	va_end(arg);
	return (rtn);
}
