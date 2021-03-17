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
	char	*ptr;

	ft_strlcpy(ptr, *format, ft_strlen(*format) + 1);
	ft_strlcpy(specifiers, "diucspxX%nfeg", 14);
	printf("%s, %p, %c\n", *format, *format, **format);
	/*
	while (ft_strchr(specifiers, *ptr) == 0)
	{
		printf("while is work!");
		(ptr)++;
	}
	printf("\nbefore ptr : %p, %c\n", ptr, ptr);
	(ptr)++;
	printf("after ptr : %p, %c\n", ptr, ptr);
	*format = ptr;
	*/
	return (0);
}