/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 11:33:10 by okim              #+#    #+#             */
/*   Updated: 2020/11/16 17:15:18 by okim             ###   ########.fr       */
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

///////////////////////////////////////////////////////////

	const char *src = "Hello World!";
	char dst[13];
	char *c;
	char *d;

	c = memcpy(dst, src, 12);
	printf("c : %p\nsrc = %s\ndst = %s\n\n", c, src, dst);
	memset (dst, 0, sizeof(dst));
	
	d = ft_memcpy(dst, src, 12);
	printf("d : %p\nsrc = %s\ndst = %s\n\n", d, src, dst);
	memset (dst, 0, sizeof(dst));
	
	c = memccpy(dst, src, 'w', 10);
	printf("c : %p\nsrc = %s\ndst = %s\n\n", c, src, dst);
	memset (dst, 0, sizeof(dst));

	d = ft_memccpy(dst, src, 'w', 10);
	printf("d : %p\nsrc = %s\ndst = %s\n\n", d, src, dst);
	memset (dst, 0, sizeof(dst));

	c = memmove(dst, src, 10);
	printf("c : %p\nsrc = %s\ndst = %s\n\n", c, src, dst);
	memset (dst, 0, sizeof(dst));

	d = ft_memmove(dst, src, 10);
	printf("d : %p\nsrc = %s\ndst = %s\n\n", d, src, dst);


	return (0);
}
