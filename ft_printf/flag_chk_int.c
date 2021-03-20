/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_chk_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 21:33:49 by okim              #+#    #+#             */
/*   Updated: 2021/03/21 01:52:33 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int flag_chk_int(char **nmb, t_format *structs, int nmb_len, int len, int sign)
{
    int rtn;

    rtn = 1;
    if (structs->precision != 0)
    {
        if (sign > 0)
        {
            if (structs->plus > 0)
                write(1, "+", 1);
            else if (structs->space > 0)
                write(1, " ", 1);
            else
                rtn = 0;
        }
        else
            write(1, "-", 1);
        print_n('0', len - nmb_len);
        print_str(*nmb, nmb_len);
    }
    else
    {
        if (structs->minus > 0)
        {
            if (sign > 0)
            {
                if (structs->plus > 0)
                    write(1, "+", 1);
                else if (structs->space > 0)
                    write(1, " ", 1);
                else
                    rtn = 0;
            }
            else
                write(1, "-", 1);
            print_str(*nmb, nmb_len);
            print_n(' ', len - nmb_len);
        }
        else if (structs->zero > 0)
        {
            if (sign > 0)
            {
                if (structs->plus > 0)
                    write(1, "+", 1);
                else if (structs->space > 0)
                    write(1, " ", 1);
                else
                    rtn = 0;
            }
            else
                write(1, "-", 1);
            print_n('0', len - nmb_len);
            print_str(*nmb, nmb_len);
        }
        else
        {
            print_n(' ', len - nmb_len);
            if (sign > 0)
            {
                if (structs->plus > 0)
                    write(1, "+", 1);
                else if (structs->space > 0)
                    write(1, " ", 1);
                else
                    rtn = 0;
            }
            else
                write(1, "-", 1);
            print_str(*nmb, nmb_len);
        }
    }
    return (rtn);
}