#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	main(void)
{
	int num = 10;
	int *arr, *arr2;

	arr = (int *)calloc(num, sizeof(int));
	arr2 = (int *)ft_calloc(num, sizeof(int));

	for (int i = 0; i < num; i++)
	{
		printf("calloc : %d, ft_calloc : %d\n", *(arr + i), *(arr2 + i));
	}

	free(arr);
	free(arr2);

	return (0);
}
