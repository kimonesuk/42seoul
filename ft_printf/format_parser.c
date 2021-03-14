/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim </var/mail/okim>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 19:37:41 by okim              #+#    #+#             */
/*   Updated: 2021/03/14 21:10:45 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_parser(char **format, struct structs, va_list arg)
{
	if (flag_parser(format, structs, arg))
		return (-1);
	if (width_parser(format, structs, arg) || precise_parser(format, structs, arg))
		return (-1);
	if (length_parser(format, structs, arg))
		return (-1);
	return (0);
}
