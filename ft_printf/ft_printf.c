/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:09:27 by okim              #+#    #+#             */
/*   Updated: 2021/03/14 19:37:24 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		rtn;
	char	*str;
	va_list	ap;
	
	rtn = 0;
	str = (char*)format;
	while (*str != 0)
	{
		if (*str != '%')
		{
			write(1, str, 1);
			rtn++;
			str++;
		}
		else
		{
			str++;
			//format_parse(str);
			//printf_format
		}
	}
	return (rtn);
}
