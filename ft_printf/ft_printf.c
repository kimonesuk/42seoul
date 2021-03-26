/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:09:27 by okim              #+#    #+#             */
/*   Updated: 2021/03/26 10:24:11 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int			rtn;
	char		*str;
	char		*target;
	t_format	*structs;
	va_list		arg;

	rtn = 0;
	va_start(arg, format);
	str = (char *)format;
	target = str;
	while (ft_strchr(target, '%'))
	{
		str = target;
		target = ft_strchr(target, '%');
		rtn += print_saved(str, target++ - str);
		structs = (t_format *)malloc(sizeof(t_format));
		new_structs(structs);
		format_parser(&target, structs, &arg);
		structs->rtn = rtn;
		rtn += print_format(structs, &arg);
		free(structs);
	}
	rtn += print_saved(target, ft_strlen(target));
	va_end(arg);
	return (rtn);
}
