/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 11:33:10 by okim              #+#    #+#             */
/*   Updated: 2020/11/13 11:35:24 by okim             ###   ########.fr       */
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

	a = (char*)memset(test, test_n, sizeof(test));
	printf("a : %p\ntest : %s\n\n", a, test);
	
	b = (char*)ft_memset(test, test_n, sizeof(test));
	printf("b : %p\ntest : %s\n\n", b, test);

	return (0);
}
