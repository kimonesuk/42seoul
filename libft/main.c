/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 11:33:10 by okim              #+#    #+#             */
/*   Updated: 2020/11/17 22:14:49 by okim             ###   ########.fr       */
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
	memset (dst, 0, sizeof(dst));
	
	c = memchr(src, '?', sizeof(src));
	printf("c : %p\n\n", c);

	d = ft_memchr(src, '?', sizeof(src));
	printf("d : %p\n\n", d);

	char *s1 = "Hello World!?";
	char *s2 = "Hello World!!";
	char s3[14];
	char s4[14];
	char s5[17] = "Hi ";
	char s6[17] = "Hi ";
	int n1;
	int	n2;

	n1 = memcmp(s1, s2, 0);
	printf("memcmp : %d\n", n1);

	n2 = ft_memcmp(s1, s2, 0);
	printf("ft_memcmp : %d\n\n", n2);

	n1 = strlen(s2);
	printf("strlen : %d\n", n1);

	n2 = ft_strlen(s2);
	printf("ft_strlen : %d\n\n", n2);

	n1 = strlcpy(s3, s2, 10);
	printf("strlcpy : %d, %s\n", n1, s3);

	n2 = ft_strlcpy(s4, s2, 10);
	printf("ft_strlcpy : %d, %s\n\n", n2, s4);

	n1 = strlcat(s5, s2, 10);
	printf("strlcat : %d, %s\n", n1, s5);

	n2 = ft_strlcat(s6, s2, 10);
	printf("ft_strlcat : %d, %s\n\n", n2, s6);

	return (0);
}
