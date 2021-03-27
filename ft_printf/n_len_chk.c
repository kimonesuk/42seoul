/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_len_chk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 13:38:39 by okim              #+#    #+#             */
/*   Updated: 2021/03/27 13:52:46 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	l_len_chk(t_format *structs, va_list *arg)
{
	long int	*tmp;

	tmp = va_arg(*arg, long int *);
	if (tmp != 0)
		*tmp = structs->rtn;
}

void	ll_len_chk(t_format *structs, va_list *arg)
{
	long long int	*tmp;

	tmp = va_arg(*arg, long long int *);
	if (tmp != 0)
		*tmp = structs->rtn;
}

void	h_len_chk(t_format *structs, va_list *arg)
{
	short int	*tmp;

	tmp = va_arg(*arg, short int *);
	if (tmp != 0)
		*tmp = structs->rtn;
}

void	hh_len_chk(t_format *structs, va_list *arg)
{
	signed char	*tmp;

	tmp = va_arg(*arg, signed char *);
	if (tmp != 0)
		*tmp = structs->rtn;
}

int		n_len_chk(t_format *structs, va_list *arg)
{
	int	*tmp;

	if (structs->length_char == 'l')
		l_len_chk(structs, arg);
	else if (structs->length_char == 'L')
		ll_len_chk(structs, arg);
	else if (structs->length_char == 'h')
		h_len_chk(structs, arg);
	else if (structs->length_char == 'H')
		hh_len_chk(structs, arg);
	else
	{
		tmp = va_arg(*arg, int *);
		if (tmp != 0)
			*tmp = structs->rtn;
	}
	return (1);
}
