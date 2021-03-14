/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:09:27 by okim              #+#    #+#             */
/*   Updated: 2021/03/14 21:21:10 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		rtn;
	char	*str;
	char	*target;
	va_list	arg;

	rtn = 0;
	va_start(arg, format);
	str = (char*)format;
	while ((target = ft_strchr(str, '%')))
	{
		rtn += print_str(str, target - str);
		//rtn += format_parser(&target, structs, arg);
		//rtn += print_format(&target, structs, arg);
		str = ++target;
	}
	rtn += print_str(str, ft_strlen(str));
	va_end(arg);
	return (rtn);
}
