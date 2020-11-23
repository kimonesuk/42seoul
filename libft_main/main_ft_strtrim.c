#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char *s1;
	char *s2;
	char *s3;
	char *s4;
	char *s5;

	s1 = ft_strtrim("ABCCBA", "AB");
	s2 = ft_strtrim("ACCBACBA", "AB");
	s3 = ft_strtrim("ABCCBA", "");
	s4 = ft_strtrim("", "AB");
	s5 = ft_strtrim("Hello World!", "Hlde");

	printf("s1 : %s\ns2 : %s\ns3 : %s\ns4 : %s\ns5 : %s\n", s1, s2, s3, s4, s5);
	return (0);
}
