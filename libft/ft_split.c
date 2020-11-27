/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:26:47 by okim              #+#    #+#             */
/*   Updated: 2020/11/27 17:20:13 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	**clear_mem(char **strs)
{
	int		i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (0);
}

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

	if (!s)
		return (0);
	count = get_count(s, c);
	if (!(nums = (int *)malloc(sizeof(int) * count)))
		return (0);
	i = 0;
	j = 0;
	while (s[i] && j < count)
	{
		while (s[i] == c)
			i++;
		nums[j] = 0;
		while (s[i] && s[i] != c)
		{
			nums[j]++;
			i++;
		}
		j++;
	}
	return (nums);
}

char		**ft_split(const char *s, char c)
{
	char	**splt_strs;
	int		*nums;
	char	count;
	int		j;

	if (!s)
		return (0);
	count = get_count(s, c);
	if (!(splt_strs = (char **)malloc(sizeof(char *) * (count + 1))))
		return (0);
	j = 0;
	nums = get_nums(s, c);
	while (*s && j < count)
	{
		while (*s && *s == c)
			s++;
		if (!(splt_strs[j] = (char *)malloc(sizeof(char) * (nums[j] + 1))))
			return (clear_mem(splt_strs));
		ft_strlcpy(splt_strs[j], s, nums[j] + 1);
		s += nums[j++];
	}
	splt_strs[j] = NULL;
	free(nums);
	return (splt_strs);
}
