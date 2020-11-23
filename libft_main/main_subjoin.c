#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char *s1 = "Hello";
	char *s2 = "  World!";
	char *s3;

	s3 = ft_strjoin(s1, s2);
	printf("s3 : %s\n", s3);
	return (0);
}
