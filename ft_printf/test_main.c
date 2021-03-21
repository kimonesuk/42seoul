#include "ft_printf.h"

int	main(void)
{
	// int	rtn;
	// rtn = printf("--->[%+07d]<---\n", 12345);
	// printf("rtn : %d\n", rtn - 11);

	ft_printf("This is test --->[%0# + *.* d]<--- This is test\n", 12, -13, 77);
	return (0);
}
