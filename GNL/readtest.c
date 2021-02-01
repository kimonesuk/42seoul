#include "get_next_line.h"

int	main(void)
{
	char	buff[BUFFER_SIZE];
	int		fd;
	int		readsize;

	fd = open("test.txt", O_RDONLY);
	while ((readsize = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[readsize] = '\0';
		printf("%s\n\n", buff);
	}
	return (0);
}
