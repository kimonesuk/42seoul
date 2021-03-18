/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_structs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:21:41 by okim              #+#    #+#             */
/*   Updated: 2021/03/17 21:10:45 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int new_structs(t_format *structs)
{
    structs->zero = 0;
    structs->minus = 0;
    structs->number = 0;
    structs->space = 0;
    structs->plus = 0;
    structs->width = 0;
    structs->precision = 0;
    structs->rtn = 0;
    structs->length_char = 'd';
    return (0);
}