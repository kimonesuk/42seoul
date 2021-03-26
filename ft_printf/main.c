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
	int	*ptr;

	ptr = 0;
	rtn1 = printf("-->|%-16p|<--\n", ptr); // 0출력
	rtn2 = printf("-->|%-16.p|<--\n", ptr); // 0출력x precision == 0 &&
	rtn3 = printf("-->|%.p|<--\n", ptr); // 0출력x
	rtn4 = printf("-->|%.-16p|<--\n", ptr); // 0 & width 안에 포함 X (음수인 경우 width로 처리)
	rtn5 = printf("-->|%.16p|<--\n", ptr); // width 안에 포함, 0출력x
	rtn1 = ft_printf("-->|%-16p|<--\n", ptr); // 0출력
	rtn2 = ft_printf("-->|%-16.p|<--\n", ptr); // 0출력x
	rtn3 = ft_printf("-->|%.p|<--\n", ptr); // 0출력x
	rtn4 = ft_printf("-->|%.-16p|<--\n", ptr); // 0 & width 안에 포함 X (음수인 경우 width로 처리)
	rtn5 = ft_printf("-->|%.16p|<--\n", ptr); // width 안에 포함, 0출력x
	printf("rtn 1 : %d\nrtn 2 : %d\nrtn 3 : %d\nrtn 4 : %d\nrtn 5 : %d\n", rtn1, rtn2, rtn3, rtn4, rtn5);

	return (0);
}
