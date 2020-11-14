/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 11:33:10 by okim              #+#    #+#             */
/*   Updated: 2020/11/14 13:41:37 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char test[5];
	int test_n = 65;
	char *a;
	char *b;

	memset(test, 48, sizeof(test));
	a = (char*)memset(test, test_n, sizeof(test));
	printf("a : %p\ntest : %s\n\n", a, test);

	memset(test, 48, sizeof(test));
	b = (char*)ft_memset(test, test_n, sizeof(test));
	printf("b : %p\ntest : %s\n\n", b, test);

	memset(test, 48, sizeof(test));
	bzero(test, sizeof(test));
	printf("test : ");
	for(int i = 0; i < (int)sizeof(test); i++)
		printf("%c", test[i]);
	printf("\n\n");

	memset(test, 48, sizeof(test));
	ft_bzero(test, sizeof(test));
	printf("test : ");
	for(int i = 0; i < (int)sizeof(test); i++)
		printf("%c", test[i]);
	printf("\n\n");

	return (0);
}
