/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:09:27 by okim              #+#    #+#             */
/*   Updated: 2021/03/14 16:19:08 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		rtn;
	char*	str;
	va_list	ap;
	
	rtn = 0;
	str = (char)format;
	while (str != 0)
	{
		if (*str != '%')
		{
			write(1,*str,1);
			rtn++;
		}
		else
		{
			str++;
			//format_parse(str);
		}
	}
	return (rtn);
}
