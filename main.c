#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	// int		fd2;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	// fd2 = open("test2.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("1: %s", line);
	free(line);
	// line = get_next_line(fd2);
	// printf("2: %s", line);
	// free(line);
	line = get_next_line(fd);
	printf("3: %s", line);
	free(line);
	// line = get_next_line(fd2);
	// printf("4: %s", line);
	// free(line);
	line = get_next_line(fd);
	printf("5: %s\n", line);
	free(line);
	// line = get_next_line(fd2);
	// printf("6: %s\n", line);
	// free(line);
	close(fd);
}
