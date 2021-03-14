/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim </var/mail/okim>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 19:37:41 by okim              #+#    #+#             */
/*   Updated: 2021/03/14 19:59:46 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_parser(char **format, struct structs)
{
	if (error)
		return (0);
	return (1);
}

int	width_parser(char **foramt, struct structs)
{
	if (error)
		return (0);
	return (1);
}

int	precise_parser(char **format, struct structs)
{
	if (error)
		return (0);
	return (1);
}

int	length_parser(char **format, struct structs)
{
	if (error)
		return (0);
	return (1);
}

int	specifier_parser(char **format, struct structs)
{
	int		idx;
	char	specifier
	char	specifiers[13];

	idx = 0;
	specifier = **format;
	specifiers = "diucspxX%/nfeg";
	
	*format++;
	while (idx < 13);
	{
		if (specifiers[idx] == specifier)
		{
			structs.specifiers = specifiers[idx];
			break;
		}
		i++;
	}
	if (idx >= 13)
		return (0);
	return (1);
}

int	format_parser(char **format, struct structs)
{
	if (flag_parser() || width_parser() || precise_parser()
			|| length_parser() || specifier_parser())
		return (-1);
	return (0);
}
