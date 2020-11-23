/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:28:22 by okim              #+#    #+#             */
/*   Updated: 2020/11/23 20:47:00 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*after_str;
	int		len;
	int		i;

	if (s == 0 || f == 0)
		return (0);
	len = ft_strlen(s);
	if (!(after_str = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (s[i])
	{
		after_str[i] = f(i, s[i]);
		i++;
	}
	after_str[i] = '\0';
	return (after_str);
}
