#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_printf.h"

int	main(void)
{
	int rtn1;
	int rtn2;
	int rtn3;
	int rtn4;
	int	rtn5;
	int rtn6;
	int rtn7;
	int rtn8;
	int rtn9;
	int	rtn10;
	int rtn11;
	int rtn12;
	int rtn13;
	int rtn14;
	int	rtn15;
	int	rtn16;
	
	rtn1 = printf("-->|%d|<--\n", 12345); // 기본
	rtn2 = printf("-->|%10d|<--\n", 12345); // width > len : width - len 공백
	rtn3 = printf("-->|%3d|<--\n", 12345); // width < len  : 무시
	rtn4 = printf("-->|%010d|<--\n", 12345); // width > len with 0 : 공백 대신 0
	rtn5 = printf("-->|% 10d|<--\n", 12345); // width > len with space : ' ' or -
	rtn6 = printf("-->|%-10d|<--\n", 12345); // width > len with minus : 좌측정렬
	rtn7 = printf("-->|%#10d|<--\n", 12345); // width > len with number : 무시
	rtn8 = printf("-->|%+10d|<--\n", 12345); // width > len with plus : + or -
	rtn9 = printf("-->|%-0#+ 10d|<--\n", 12345); // width > len all : 좌측정렬 & +
	rtn10 = printf("-->|%.10d|<--\n", 12345); // precision > len : precision - len 0
	rtn11 = printf("-->|%.3d|<--\n", 12345); // precision < len : 무시
	rtn12 = printf("-->|%.-10d|<--\n", 12345); // precision < 0 : 좌측정렬
	rtn13 = printf("-->|%.0d|<--\n", 12345); // precision = 0 : 무시, 0일떄 아무것도 출력안함
	rtn14 = printf("-->|%.d|<--\n", 12345); // precision = null : 무시, 0일떄 아무것도 출력안함
	rtn15 = printf("-->|%#20.10d|<--\n", 12345); // width > precision : width-precison 공백, precision - len 0
	rtn16 = printf("-->|%#10.20d|<--\n", 12345); // width < precision : precision - len 0
	// return u = max, nmb부호 = width 안에 포함, precision/len = + 2
	// 0,width,precision = width - precision 공백, precision - len 0
	printf("rtn 1 : %d\nrtn 2 : %d\nrtn 3 : %d\nrtn 4 : %d\nrtn 5 : %d\n", rtn1-9, rtn2-9, rtn3-9, rtn4-9, rtn5-9);
	printf("rtn 6 : %d\nrtn 7 : %d\nrtn 8 : %d\nrtn 9 : %d\nrtn 10 : %d\n", rtn6-9, rtn7-9, rtn8-9, rtn9-9, rtn10-9);
	printf("rtn 11 : %d\nrtn 12 : %d\nrtn 13 : %d\nrtn 14 : %d\nrtn 15 : %d\n", rtn11-9, rtn12-9, rtn13-9, rtn14-9, rtn15-9);
	printf("rtn 16 : %d\n", rtn16-9);

	return (0);
}
