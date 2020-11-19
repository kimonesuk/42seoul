#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

int		main(void)
{
	char *s = "HelloWorld!?!";
	char *tst1;
	char *tst2;

	tst1 = strdup(s);
	tst2 = ft_strdup(s);
	printf("strdup : %s\nft_strdup : %s\n\n", tst1, tst2);
	
	free(tst1);
	free(tst2);

	return (0);
}
