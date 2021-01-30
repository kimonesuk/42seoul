#include "get_next_line.h"

int	main(void)
{
	char	buff[BUFFER_SIZE];
	int		fd;
	
	if (0 < (fd = open("./test.txt", O_RDONLY)))
	{
		while (0 < (read(fd, buff, BUFFER_SIZE)))
		{
			printf("buff : %s\n", buff);
		}
		close(fd);
	}
	else
	{
		printf("Can't open the file.\n");
	}
	return (0);
}
