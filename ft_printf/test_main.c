#include "ft_printf.h"

int	main(void)
{
	int	rtn;

	rtn = ft_printf("Hello %d World!\n");
	printf("rtn : %d\n", rtn);

	return (0);
}
