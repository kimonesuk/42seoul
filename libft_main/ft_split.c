/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:26:47 by okim              #+#    #+#             */
/*   Updated: 2020/11/25 19:52:05 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

static int	get_count(const char *s, char c)
{
	int	count;
	int	i;

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
	int i;
	int	j;

	count = get_count(s, c);
	if(!(nums = (int *)malloc(sizeof(int) * count)))
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

char	**ft_split(const char *s, char c)
{
	char	**splt_strs;
	int		*nums;
	char	count;
	int		i;
	int		j;
	
	if (!s)
		return (0);
	count = get_count(s, c); 
	nums = get_nums(s, c);
	if (!(splt_strs = (char **)malloc(sizeof(char *) * (count + 1))))
		return (0);
	i = 0;
	j = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if(!(splt_strs[j] = (char *)malloc(sizeof(char) * (nums[j] + 1))))
			return (0);
		strlcpy(splt_strs[j], &s[i], nums[j] + 1);
		i += nums[j];
		j++;
		while (s[i] && s[i] == c)
			i++;
	}
	splt_strs[j] = 0;
	free(nums);
	return (splt_strs);
}

int	main(void)
{
	char *s1 = "eeeeeheeeeelloee";
	char *s2 = "eheeeleeleeo";
	char c = 'e';

	int cnt1 = get_count(s1, c);
	int	cnt2 = get_count(s2, c);
	int *getnums1 = get_nums(s1, c);
	int	*getnums2 = get_nums(s2, c);
	char **ss1 = ft_split(s1, c);
	char **ss2 = ft_split(s2, c);

	printf("cnt1 : %d\nnums1 : ", cnt1);
	for(int i = 0; i < cnt1 ; i++)
	{
		printf("%d ", getnums1[i]);
	}
	printf("\n");
	for(int i = 0; i <= cnt1 ; i++)
	{
		printf("%d : %s\n", i, ss1[i]);
	}
	printf("cnt2 : %d\nnums2 : ", cnt2);
	for(int i = 0; i < cnt2 ; i++)
	{
		printf("%d ", getnums2[i]);
	}
	printf("\n");
	for(int i = 0; i <= cnt2 ; i++)
	{
		printf("%d : %s\n", i, ss2[i]);
	}	
	free(getnums1);
	free(getnums2);
	return (0);
}
