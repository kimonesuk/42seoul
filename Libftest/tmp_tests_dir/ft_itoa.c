/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:27:34 by okim              #+#    #+#             */
/*   Updated: 2020/11/25 16:01:25 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static long int	n_abs(long int n)
{
	return (n < 0 ? n * -1 : n);
}

static int		nbr_len(int n)
{
	int		len;

	len = n <= 0 ? 1 : 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		o_n;

	len = nbr_len(n);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	str[len] = '\0';
	len--;
	o_n = n;
	while (len >= 0)
	{
		str[len] = n_abs(n % 10) + 48;
		n = n_abs(n / 10);
		len--;
	}
	if (o_n < 0)
		str[0] = '-';
	return (str);
}
