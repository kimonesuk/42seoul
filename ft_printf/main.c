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

	rtn1 = printf("--->[% k]<---\n","Hello");
	rtn2 = printf("--->[%#k]<---\n","Hello");
	printf("rtn 1 : %d\nrtn 2 : %d\n", rtn1 - 10, rtn2 - 10);
	rtn3 = printf("--->[%0k]<---\n","Hello");
	rtn4 = printf("--->[%+k]<---\n","Hello");
	printf("rtn 3 : %d\nrtn 4 : %d\n", rtn3 - 10, rtn4 - 10);
	rtn5 = printf("--->[%-k]<---\n","Hello");
	rtn6 = printf("--->[%6k]<---\n","Hello");
	printf("rtn 5 : %d\nrtn 6 : %d\n", rtn5 - 10, rtn6 - 10);
	rtn7 = printf("--->[%.7k]<---\n","Hello");
	rtn8 = printf("--->[%.0k]<---\n","Hello");
	printf("rtn 7 : %d\nrtn 8 : %d\n", rtn7 - 10, rtn8 - 10);
	rtn9 = printf("--->[%010k]<---\n","Hello");
	rtn10 = printf("--->[%-10k]<---\n","Hello");
	printf("rtn 9 : %d\nrtn 10 : %d\n", rtn9 - 10, rtn10 - 10);

	return (0);
}