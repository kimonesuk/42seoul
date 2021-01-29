#include "get_next_line.h"

int	main(void)
{
	char	buff[BUFFER_SIZE];
	char	line[1024];
	int		fd;
	int		i;
	
	if (0 < (fd = open("./test.txt", O_RDONLY)))
	{
		i = 0;
		while (0 < (read(fd, buff, BUFFER_SIZE)))
		{
			memset(line, '\0', BUFFER_SIZE);
			while (buff[i] != '\0')
			{
				strcat(line, &buff[i]);
				i++;
			}
			printf("line : %s\n", line);
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
