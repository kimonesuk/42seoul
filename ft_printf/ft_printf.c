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
		printf("\nbefore target : %p, %c\n", target, target[0]);
		structs = (t_format*)malloc(sizeof(t_format));
		format_parser(&target, structs, arg);
		//rtn += print_format(&target, structs, arg);
		free(structs);
		printf("after target : %p, %c\n", target, target[0]);
	}
	rtn += print_str(target, ft_strlen(target));
	va_end(arg);
	return (rtn);
}
