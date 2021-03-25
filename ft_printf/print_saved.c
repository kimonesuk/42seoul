/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_saved.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 20:58:54 by okim              #+#    #+#             */
/*   Updated: 2021/03/25 11:05:09 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_saved(char *format, int len)
{
	write(1, format, len);
	return (len);
}
