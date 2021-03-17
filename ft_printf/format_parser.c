/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 19:37:41 by okim              #+#    #+#             */
/*   Updated: 2021/03/14 21:10:45 by okim             ###   ########.fr       */
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

int	width_parser(char **format, t_format *structs)
{
	if ((ft_isdigit(**format)) != 0)
		structs->width = **format - 48;
	else if (**format == '*')
		return (2);
	else
		return (0);
	return (1);
}

int	precise_parser(char **format, t_format *structs)
{
	if (**format == '.')
	{
		*format = *format + sizeof(char) * 1;
		if ((ft_isdigit(**format)) != 0)
			structs->precision = **format - 48;
		else if (**format == '*')
			return (2);
		else
			return (0);
	}
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
	return (1);
}

int	format_parser(char **format, t_format *structs, va_list arg)
{
	char	specifiers[14];

	ft_strlcpy(specifiers, "diucspxX%nfeg", 14);
	while ((ft_strchr(specifiers, **format)) == 0)
	{
		flag_parser(format, structs);
		if (width_parser(format, structs) == 2)
			structs->width = va_arg(arg, int);
		if (precise_parser(format, structs) == 2)
			structs->precision = va_arg(arg, int);
		length_parser(format, structs);
		*format = *format + sizeof(char) * 1;
	}
	structs->specifier = **format;
	*format = *format + sizeof(char) * 1;
	return (1);
}