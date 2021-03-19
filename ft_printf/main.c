#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_printf.h"

/*int nmb_len (long long nmb)
{
    int len;

    nmb = nmb < 0 ? -nmb : nmb;
    len = 1;
    while ((nmb /= 10) > 0)
        len++;
    return (len);
}*/

int	main(void)
{
	int rtn1;
	int rtn2;
	//int len;

	rtn1 = printf("--->[%6d]<---\n",-123);
	rtn2 = ft_printf("--->[%6d]<---\n",-123);
	//rtn2 = printf("--->[%s]<---\n","Hello");
	printf("rtn 1 : %d\nrtn 2 : %d\n", rtn1 - 10, rtn2 - 10);
	//len = nmb_len(-1234567890);
	//printf("len : %d\n", len);

	return (0);
}