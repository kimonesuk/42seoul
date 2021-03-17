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

int	format_parser(char **format, t_format *structs, va_list arg)
{
	char	specifiers[13];

	ft_strlcpy(specifiers, "diucspxX%nfeg", 14);
	while (ft_strchr(specifiers, **format) == 0)
	{
		printf("while is work!");
		(*format)++;
	}
	printf("\nbefore *format : %p, %c\n", *format, *format);
	(*format)++;
	printf("after *format : %p, %c\n", *format, *format);
	return (0);
}