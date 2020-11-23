#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	f(unsigned int i, char c)
{
	if (i + 1)
	{
		c = ft_toupper(c);
	}
	return (c);
}

int	main(void)
{
	char *s = "Hi Hello World!?!";

	printf("%s\n", ft_strmapi(s, f));
	return (0);
}
