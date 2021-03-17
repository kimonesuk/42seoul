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
	else if(**format == '-')
		structs->minus++;
	else if(**format == '#')
		structs->number++;
	else if(**format == ' ')
		structs->space++;
	else if(**format == '+')
		structs->plus++;
	else
		return (0);
	return (1);
}
/*
int	width_parser(char **foramt, t_format *structs)
{
	if (error)
		return (0);
	return (1);
}

int	precise_parser(char **format, t_format *structs)
{
	if (error)
		return (0);
	return (1);
}

int	length_parser(char **format, t_format *structs)
{
	if (error)
		return (0);
	return (1);
}
*/
int	format_parser(char **format, t_format *structs, va_list arg)
{
	char	specifiers[14];

	ft_strlcpy(specifiers, "diucspxX%nfeg", 14);
	while ((ft_strchr(specifiers, **format)) == 0)
	{
		flag_parser(format, structs);
//		width_parser(format, structs);
//		precise_parser(format, structs);
//		length_parser(format, structs);
//		return (0);
		*format = *format + sizeof(char) * 1;
	}
	structs->specifier = **format;
	*format = *format + sizeof(char) * 1;
	return (1);
}