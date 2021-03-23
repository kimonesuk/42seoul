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

	rtn1 = printf("--->[% d]<---\n",1234); // space
	rtn2 = printf("--->[%#d]<---\n",1234); // #
	printf("rtn 1 : %d\nrtn 2 : %d\n", rtn1 - 10, rtn2 - 10);
	rtn3 = printf("--->[%0d]<---\n",1234); // zero
	rtn4 = printf("--->[%+d]<---\n",1234); // plus
	printf("rtn 3 : %d\nrtn 4 : %d\n", rtn3 - 10, rtn4 - 10);
	rtn5 = printf("--->[%-d]<---\n",1234); // minus
	rtn6 = printf("--->[%2d]<---\n",1234); // width < nb
	printf("rtn 5 : %d\nrtn 6 : %d\n", rtn5 - 10, rtn6 - 10);
	rtn7 = printf("--->[%20d]<---\n",1234); // width > nb
	rtn8 = printf("--->[%6.5d]<---\n",1234); // width > precision
	printf("rtn 7 : %d\nrtn 8 : %d\n", rtn7 - 10, rtn8 - 10);
	rtn9 = printf("--->[%.d]<---\n",1234); // precision only
	rtn10 = printf("--->[%.0d]<---\n",1234); // precision 0
	printf("rtn 9 : %d\nrtn 10 : %d\n", rtn9 - 10, rtn10 - 10);
	rtn11 = printf("--->[%.2d]<---\n",1234); // precision < nb
	rtn12 = printf("--->[%.20d]<---\n",1234); // precision > nb
	printf("rtn 11 : %d\nrtn 12 : %d\n", rtn11 - 10, rtn12 - 10);
	rtn13 = printf("--->[%20.10d]<---\n",1234); // width > precision > nb
	rtn14 = printf("--->[%020.10d]<---\n",1234); // width > precision > nb with 0
	printf("rtn 13 : %d\nrtn 14 : %d\n", rtn13 - 10, rtn14 - 10);
	rtn15 = printf("--->[%+ 20d]<---\n",0); // width > precision > nb with -
	rtn16 = printf("--->[%020.10d]<---\n",1234); // normal
	printf("rtn 15 : %d\nrtn 16 : %d\n", rtn15 - 10, rtn16 - 10);

	return (0);
}