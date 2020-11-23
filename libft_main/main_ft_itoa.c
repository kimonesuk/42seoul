#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	main(void)
{
	int n1 = -2147483648;
	int	n2 = -2147483647;
	int n3 = 2147483646;
	int n4 = 2147483647;
	int n5 = 0;
	char	*s1;
	char	*s2;
	char	*s3;
	char	*s4;
	char	*s5;

	s1 = ft_itoa(n1);
	s2 = ft_itoa(n2);
	s3 = ft_itoa(n3);
	s4 = ft_itoa(n4);
	s5 = ft_itoa(n5);

	printf("n1 : %s\nn2 : %s\nn3 : %s\nn4 : %s\nn5 : %s\n", s1, s2, s3, s4, s5);

	free(s1);
	free(s2);
	free(s3);
	free(s4);
	free(s5);

	return (0);
}
