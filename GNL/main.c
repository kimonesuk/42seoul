#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		ret;
	int		fd;

	line = (char*)malloc(BUFFER_SIZE);
	memset(line, '\0', BUFFER_SIZE);
	fd = open("test.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) >= 0)
	{
		printf("%s\n", line);
		memset(line, '\0', BUFFER_SIZE);
	}
	free(line);
	return (0);
}
