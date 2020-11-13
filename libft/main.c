#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	char test[60];
	int test_n = 10;
	char a,b;

	a = *(char*)memset(test, test_n, sizeof(test));
	printf("a : %c\n test : %s\n\n", a, test);
	
	b = *(char*)ft_memset(test, test_n, sizeof(test));
	printf("b : %c\n test : %s\n\n", b, test);

	return (0);
}
