#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	main(void)
{
	char *s1 = "-1234567890";
	char *s2 = "123abc567890";
	char *s3 = "abc1234567890";
	char *s4 = "+2147483648";
	char *s5 = "+2147483647";
	char *s6 = "-2147483648";
	char *s7 = "-2147483647";
	char *s8 = "123---4567890";
	int rtn;

	rtn = atoi(s1);
	printf("s1 : -1234567890 : %d\n", rtn);
	rtn = atoi(s2);
	printf("s2 : 123abc567890 : %d\n", rtn);
	rtn = atoi(s3);
	printf("s3 : abc1234567890 : %d\n", rtn);
	rtn = atoi(s4);
	printf("s4 : +2147483648 : %d\n", rtn);
	rtn = atoi(s5);
	printf("s5 : +2147483647 : %d\n", rtn);
	rtn = atoi(s6);
	printf("s6 : -2147483648 : %d\n", rtn);
	rtn = atoi(s7);
	printf("s7 : -2147483647 : %d\n", rtn);
	rtn = atoi(s8);
	printf("s8 : 123---4567890 : %d\n\n", rtn);

	rtn = ft_atoi(s1);
	printf("s1 : -1234567890 : %d\n", rtn);
	rtn = ft_atoi(s2);
	printf("s2 : 123abc567890 : %d\n", rtn);
	rtn = ft_atoi(s3);
	printf("s3 : abc1234567890 : %d\n", rtn);
	rtn = ft_atoi(s4);
	printf("s4 : +2147483648 : %d\n", rtn);
	rtn = ft_atoi(s5);
	printf("s5 : +2147483647 : %d\n", rtn);
	rtn = ft_atoi(s6);
	printf("s6 : -2147483648 : %d\n", rtn);
	rtn = ft_atoi(s7);
	printf("s7 : -2147483647 : %d\n", rtn);
	rtn = ft_atoi(s8);
	printf("s8 : 123---4567890 : %d\n", rtn);

	return (0);
}
