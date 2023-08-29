/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorcvaz <victorcvaz@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 00:46:47 by victorcvaz        #+#    #+#             */
/*   Updated: 2023/08/25 20:05:36 by victorcvaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*curr_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FD_LIMITS)
		return (NULL);
	read_file_content(fd, &buffer);
	if (!buffer)
		return (NULL);
	curr_line = get_line(&buffer);
	return (curr_line);
}

void	read_file_content(int fd, char **buffer)
{
	char	*temp;
	int		bytes_read;
	char	*read_buffer;

	read_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !has_newline(*buffer))
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			break ;
		read_buffer[bytes_read] = '\0';
		temp = ft_strjoin(*buffer, read_buffer);
		free(*buffer);
		*buffer = temp;
	}
	free(read_buffer);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	int		bytes_read;
	char	line[BUFFER_SIZE + 1];

	fd = open("test.txt", O_RDONLY);
	printf("fd value: %d\n", fd);
	if (fd < 0)
		return (0);
	bytes_read = read(fd, line, BUFFER_SIZE);
	printf("Bytes_read: %d\n", bytes_read);
	bytes_read = read(fd, line, BUFFER_SIZE);
	printf("Bytes_read: %d\n", bytes_read);
	close(fd);
}
