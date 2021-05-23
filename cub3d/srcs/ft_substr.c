/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 20:35:38 by okim              #+#    #+#             */
/*   Updated: 2021/05/23 17:30:21 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (!s)
		return (0);
	if (ft_strlen(s) < (int)start)
		return (ft_strdup(""));
	if (!(substr = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
