/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:26:47 by okim              #+#    #+#             */
/*   Updated: 2020/11/25 19:58:14 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	get_count(const char *s, char c)
{
	int		count;
	int		i;

	if (!s)
		return (0);
	count = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			count++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

static int	*get_nums(const char *s, char c)
{
	int *nums;
	int	count;
	int	i;
	int	j;

	count = get_count(s, c);
	if (!(nums = (int *)malloc(sizeof(int) * count)))
		return (0);
	i = 0;
	j = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		nums[j] = 0;
		while (s[i] && s[i] != c)
		{
			nums[j]++;
			i++;
		}
		j++;
		while (s[i] == c)
			i++;
	}
	return (nums);
}

char		**ft_split(const char *s, char c)
{
	char	**splt_strs;
	int		*nums;
	char	count;
	int		i;
	int		j;

	count = get_count(s, c);
	nums = get_nums(s, c);
	if (!(splt_strs = (char **)malloc(sizeof(char *) * (count + 1))))
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!(splt_strs[j] = (char *)malloc(sizeof(char) * (nums[j] + 1))))
			return (0);
		ft_strlcpy(splt_strs[j], &s[i], nums[j] + 1);
		i += nums[j++];
	}
	splt_strs[j] = 0;
	free(nums);
	return (splt_strs);
}
