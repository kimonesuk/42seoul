#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*specifiers;

	specifiers = (char*)malloc(sizeof(char) * 13);
	specifiers = "diucspxX%nfeg";
	printf("%s\n", specifiers);
	for (int i = 0; i <= 14; i++)
		printf("%d : %c\n", i, specifiers[i]);
	return (0);
}
