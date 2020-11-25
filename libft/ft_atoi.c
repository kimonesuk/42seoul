/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 23:08:32 by okim              #+#    #+#             */
/*   Updated: 2020/11/25 21:04:58 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' ||
		c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *s)
{
	int		rtn;
	int		sign;
	int		i;

	rtn = 0;
	sign = 1;
	i = 0;
	while (s[i] && is_space(s[i]) == 1)
		i++;
	if (s[i] == '+')
		s++;
	else if (s[i] == '-')
	{
		s++;
		sign = -1;
	}
	while (s[i] && s[i] >= 48 && s[i] <= 57)
	{
		rtn = rtn * 10 + (s[i] - 48);
		i++;
	}
	return (sign * rtn);
}
