#include <string.h>
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char *rtn;
	char *s1 = "Hello World!?!";
	char *s2 = "";

	rtn = strnstr(s1, s2, 16);
	printf("strnstr : %p\n", rtn);

	rtn = ft_strnstr(s1, s2, 16);
	printf("ft_strnstr : %p\n", rtn);

	return (0);
}
