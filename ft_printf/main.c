#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_printf.h"

int	main(void)
{
	int rtn1;
	int rtn2;
	char	c = 0;

	rtn1 = ft_printf("%0d %0i\n", 42, 34);
	rtn2 = ft_printf("%d\n", -1);
	printf("rtn 1 : %d\nrtn 2 : %d\n", rtn1, rtn2);

	return (0);
}