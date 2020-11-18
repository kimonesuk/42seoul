#include <ctype.h>
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	int a;

	for(int i = 0; i < 256; i++)
	{
		a = ft_isalpha(i);
		printf("%d : %d\n", i, a);	
	}
	printf("\n\n");
	for(int i = 0; i < 256; i++)
	{
		a = ft_isdigit(i);
		printf("%d : %d\n", i, a);	
	}
	printf("\n\n");
	for(int i = 0; i < 256; i++)
	{
		a = ft_isalnum(i);
		printf("%d : %d\n", i, a);	
	}
	printf("\n\n");
	for(int i = 0; i < 256; i++)
	{
		a = ft_isascii(i);
		printf("%d : %d\n", i, a);	
	}
	printf("\n\n");
	for(int i = 0; i < 256; i++)
	{
		a = ft_isprint(i);
		printf("%d : %d\n", i, a);	
	}
	printf("\n\n");
	return (0);
}
