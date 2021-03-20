#include "ft_printf.h"

int	main(void)
{
	int	rtn;

	rtn = printf("--->[%6.7d]<---\n", 12345);
	printf("rtn : %d\n", rtn - 11);

	return (0);
}
