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
	int rtn3;
	int rtn4;
	int rtn5;
	int rtn6;
	int rtn7;
	int rtn8;
	int rtn9;
	int rtn10;

	rtn1 = ft_printf("--->[% p]<---\n","Hi");
	rtn2 = ft_printf("--->[%#p]<---\n","Hi");
	printf("rtn 1 : %d\nrtn 2 : %d\n", rtn1 - 10, rtn2 - 10);
	rtn3 = ft_printf("--->[%0p]<---\n","Hi");
	rtn4 = ft_printf("--->[%+p]<---\n","Hi");
	printf("rtn 3 : %d\nrtn 4 : %d\n", rtn3 - 10, rtn4 - 10);
	rtn5 = ft_printf("--->[%-p]<---\n","Hi");
	rtn6 = ft_printf("--->[%6p]<---\n","Hi");
	printf("rtn 5 : %d\nrtn 6 : %d\n", rtn5 - 10, rtn6 - 10);
	rtn7 = ft_printf("--->[%025.20p]<---\n","Hi");
	rtn8 = ft_printf("--->[%.20p]<---\n","Hi");
	printf("rtn 7 : %d\nrtn 8 : %d\n", rtn7 - 10, rtn8 - 10);
	rtn9 = ft_printf("--->[%20p]<---\n","Hi");
	rtn10 = ft_printf("--->[%-20.15p]<---\n","Hi");
	printf("rtn 9 : %d\nrtn 10 : %d\n", rtn9 - 10, rtn10 - 10);

	return (0);
}