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
	int rtn11;
	int rtn12;
	int rtn13;
	int rtn14;
	int rtn15;
	int rtn16;
	int rtn17;
	int rtn18;
	int rtn19;
	int rtn20;
	int rtn21;
	int rtn22;
	int rtn23;
	int rtn24;

	rtn1 = printf("--->[%d]<---\n",123);
	rtn2 = ft_printf("--->[%d]<---\n",123);
	printf("rtn 1 : %d\nrtn 2 : %d\n", rtn1 - 10, rtn2 - 10);
	rtn3 = printf("--->[%d]<---\n",-123);
	rtn4 = ft_printf("--->[%d]<---\n",-123);
	printf("rtn 3 : %d\nrtn 4 : %d\n", rtn3 - 10, rtn4 - 10);
	rtn5 = printf("--->[%- .d]<---\n",123);
	rtn6 = ft_printf("--->[%- .d]<---\n",123);
	printf("rtn 5 : %d\nrtn 6 : %d\n", rtn5 - 10, rtn6 - 10);
	rtn7 = printf("--->[%-8d]<---\n",123);
	rtn8 = ft_printf("--->[%-8d]<---\n",123);
	printf("rtn 7 : %d\nrtn 8 : %d\n", rtn7 - 10, rtn8 - 10);
	rtn9 = printf("--->[% 8.7d]<---\n",123);
	rtn10 = ft_printf("--->[% 8.7d]<---\n",123);
	printf("rtn 9 : %d\nrtn 10 : %d\n", rtn9 - 10, rtn10 - 10);
	rtn11 = printf("--->[%8.11d]<---\n",-123);
	rtn12 = ft_printf("--->[%8.11d]<---\n",-123);
	printf("rtn 11 : %d\nrtn 12 : %d\n", rtn11 - 10, rtn12 - 10);
	rtn13 = printf("--->[%-.7d]<---\n",123);
	rtn14 = ft_printf("--->[%-.7d]<---\n",123);
	printf("rtn 13 : %d\nrtn 14 : %d\n", rtn13 - 10, rtn14 - 10);
	rtn15 = printf("--->[%-.7d]<---\n",-123);
	rtn16 = ft_printf("--->[%-.7d]<---\n",-123);
	printf("rtn 15 : %d\nrtn 16 : %d\n", rtn15 - 10, rtn16 - 10);
	rtn17 = printf("--->[% .7d]<---\n",123);
	rtn18 = ft_printf("--->[% .7d]<---\n",123);
	printf("rtn 17 : %d\nrtn 18 : %d\n", rtn17 - 10, rtn18 - 10);
	rtn19 = printf("--->[% .7d]<---\n",-123);
	rtn20 = ft_printf("--->[% .7d]<---\n",-123);
	printf("rtn 19 : %d\nrtn 20 : %d\n", rtn19 - 10, rtn20 - 10);
	rtn21 = printf("--->[%+.7d]<---\n",123);
	rtn22 = ft_printf("--->[%+.7d]<---\n",123);
	printf("rtn 21 : %d\nrtn 22 : %d\n", rtn21 - 10, rtn22 - 10);
	rtn23 = printf("--->[%+.7d]<---\n",-123);
	rtn24 = ft_printf("--->[%+.7d]<---\n",-123);
	printf("rtn 23 : %d\nrtn 24 : %d\n", rtn23 - 10, rtn24 - 10);

	return (0);
}