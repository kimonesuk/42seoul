/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 00:14:11 by okim              #+#    #+#             */
/*   Updated: 2021/03/25 14:23:37 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	base_len(long long int nmb, int base)
{
	int	len;

	len = 0;
	if (nmb < 0)
		nmb = nmb * -1;
	while (nmb >= base)
	{
		len++;
		nmb /= base;
	}
	len++;
	return (len);
}

int	conv_z(long long int nmb, char **z)
{
	char	r_z[255];
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (nmb < 0)
		nmb = nmb * -1;
	while (nmb >= 10)
	{
		r_z[i++] = "0123456789" [nmb % 10];
		nmb /= 10;
	}
	r_z[i] = "0123456789" [nmb];
	while (i >= 0)
		*(*z + sizeof(char) * j++) = r_z[i--];
	*(*z + sizeof(char) * j) = '\0';
	return (1);
}

int	conv_hex_H(long long int nmb, char **hex)
{
	char	r_hex[255];
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (nmb >= 16)
	{
		r_hex[i++] = "0123456789ABCDEF" [nmb % 16];
		nmb /= 16;
	}
	r_hex[i] = "0123456789ABCDEF" [nmb];
	while (i >= 0)
		*(*hex + sizeof(char) * j++) = r_hex[i--];
	*(*hex + sizeof(char) * j++) = '\0';
	return (1);
}

int	conv_hex_h(long long int nmb, char **hex)
{
	char	r_hex[255];
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (nmb >= 16)
	{
		r_hex[i++] = "0123456789abcdef" [nmb % 16];
		nmb /= 16;
	}
	r_hex[i] = "0123456789abcdef" [nmb];
	while (i >= 0)
		*(*hex + sizeof(char) * j++) = r_hex[i--];
	*(*hex + sizeof(char) * j++) = '\0';
	return (1);
}

int	conv_oct(long long int nmb, char **oct)
{
	char	r_oct[255];
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (nmb >= 8)
	{
		r_oct[i++] = "01234567" [nmb % 8];
		nmb /= 8;
	}
	r_oct[i] = "01234567" [nmb];
	while (i >= 0)
		*(*oct + sizeof(char) * j++) = r_oct[i--];
	*(*oct + sizeof(char) * j++) = '\0';
	return (1);
}
