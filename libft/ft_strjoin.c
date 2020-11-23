/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:29:37 by okim              #+#    #+#             */
/*   Updated: 2020/11/23 16:30:49 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *jnstr;
	int	len1;
	int	len2;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(jnstr = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (0);
	ft_strlcpy(jnstr, s1, len1 + 1);
	ft_strlcat(jnstr, s2, len1 + len2 + 1);
	return (jnstr);
}
