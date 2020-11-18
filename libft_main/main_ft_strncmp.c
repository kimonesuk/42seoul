#include <stdio.h>
#include <string.h>
#include "libft.h"

int		main(void)
{
	char *s1 = "Hello World!!!";
	char *s2 = "Hello World!?!";
	int	rtn;

	rtn = strncmp(s1, s2, 20);
	printf("strncmp : %d\n", rtn);

	rtn = ft_strncmp(s1, s2, 20);
	printf("ft_strncmp : %d\n", rtn);

	return (0);
}
