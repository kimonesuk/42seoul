#include <stdio.h>
#include "libft.h"

int	main(void)
{
	ft_putchar_fd('C', 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("HelloWorld!", 1);
	ft_putstr_fd("\n", 1);
	ft_putendl_fd("Hello World!!", 1);
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(-2147483648, 1);
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(2147483647, 1);
	ft_putstr_fd("\n", 1);
	return (0);
}
