#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int	main(void)
{
	int a;
	int b;

	for(int i = 0; i < 225; i++)
	{
		a = toupper(i);
		b = ft_toupper(i);
		printf("%d : %d : %d\n", i, a, b);
	}
	printf("\n\n");
	for(int i = 0; i < 225; i++)
	{
		a = tolower(i);
		b = ft_tolower(i);
		printf("%d : %d : %d\n", i, a, b);
	}
	printf("\n\n");
	return (0);
}
