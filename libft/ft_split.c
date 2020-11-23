/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:26:47 by okim              #+#    #+#             */
/*   Updated: 2020/11/23 23:49:35 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int	get_count(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

static int	*get_nums(const char *s, char c)
{
	int *nums;
	int	count;
	int i;
	int	tmp;

	count = get_count(s, c) + 1;
	if(!(nums = (int *)malloc(sizeof(int) * count)))
		return (0);
	i = 0;
	while (count > 0)
	{
		tmp = 0;
		while (s[i] != c)
		{
			tmp++;
			i++;
		}
		i++;
		nums[count--] = tmp;
	}
	return (nums);
}

int	main(void)
{
	char *s1 = "hello";
	char *s2 = "ehelloe";
	char c = 'e';

	int cnt1 = get_count(s1, c);
	int	cnt2 = get_count(s2, c);
	int *getnums1 = get_nums(s1, c);
	int	*getnums2 = get_nums(s2, c);

	printf("cnt1 : %d\nnums1 : ", cnt1);
	for(int i = 0; i <= cnt1 ; i++)
	{
		printf("%d ", getnums1[i]);
	}
	printf("\n");
	printf("cnt2 : %d\nnums2 : ", cnt2);
	for(int i = 0; i <= cnt2 ; i++)
	{
		printf("%d ", getnums2[i]);
	}
	printf("\n");
	free(getnums1);
	free(getnums2);

	return (0);
}

//char	**ft_split(const char *s, char c)
//{
//	return ();
//}
