/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 19:37:41 by okim              #+#    #+#             */
/*   Updated: 2021/03/27 11:41:19 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_parser(char **format, t_format *structs)
{
	if (**format == '0')
		structs->zero++;
	else if (**format == '-')
		structs->minus++;
	else if (**format == '#')
		structs->number++;
	else if (**format == ' ')
		structs->space++;
	else if (**format == '+')
		structs->plus++;
	else
		return (0);
	return (1);
}

int	width_parser(char **format, t_format *structs, va_list *arg)
{
	if ((ft_isdigit(**format)) != 0 && (**format > '0'))
	{
		structs->width = 0;
		while ((ft_isdigit(**format)) != 0)
		{
			structs->width = (structs->width) * 10 + (**format - 48);
			*format = *format + sizeof(char) * 1;
		}
		*format = *format - sizeof(char) * 1;
	}
	else if (**format == '*')
	{
		structs->width = 0;
		structs->width = va_arg(*arg, int);
		if (structs->width < 0)
		{
			structs->width = (structs->width) * -1;
			structs->minus = (structs->minus) + 1;
		}
	}
	else
		return (0);
	return (1);
}

int	precise_parser(char **format, t_format *structs, va_list *arg)
{
	if (**format == '.')
	{
		structs->precision = 0;
		*format = *format + sizeof(char) * 1;
		if (**format == '*')
			structs->precision = va_arg(*arg, int);
		else if ((ft_isdigit(**format)) != 0)
		{
			structs->precision = 0;
			while ((ft_isdigit(**format)) != 0)
			{
				structs->precision = structs->precision * 10 + **format - 48;
				*format = *format + sizeof(char) * 1;
			}
			*format = *format - sizeof(char) * 1;
		}
		else
			*format = *format - sizeof(char) * 1;
	}
	else
		return (0);
	return (1);
}

int	length_parser(char **format, t_format *structs)
{
	if (**format == 'h')
	{
		if (*(*format + sizeof(char)) == 'h')
		{
			structs->length_char = 'H';
			*format = *format + sizeof(char) * 1;
		}
		else
			structs->length_char = 'h';
	}
	else if (**format == 'l')
	{
		if (*(*format + sizeof(char)) == 'l')
		{
			structs->length_char = 'L';
			*format = *format + sizeof(char) * 1;
		}
		else
			structs->length_char = 'l';
	}
	else
		return (0);
	return (1);
}

int	format_parser(char **format, t_format *structs, va_list *arg)
{
	char	specifiers[12];
	int		chk_flag;

	ft_strlcpy(specifiers, "diuoxXcsp%n", 12);
	while ((ft_strchr(specifiers, **format)) == 0)
	{
		chk_flag = 0;
		chk_flag += flag_parser(format, structs);
		chk_flag += width_parser(format, structs, arg);
		chk_flag += precise_parser(format, structs, arg);
		if (structs->precision < -1)
			structs->precision = -1;
		chk_flag += length_parser(format, structs);
		if (chk_flag <= 0)
			break ;
		*format = *format + sizeof(char) * 1;
	}
	structs->specifier = **format;
	if (**format != 0)
		*format = *format + sizeof(char) * 1;
	return (1);
}
