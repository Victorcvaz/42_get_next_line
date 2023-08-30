/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorcvaz <victorcvaz@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 00:46:47 by victorcvaz        #+#    #+#             */
/*   Updated: 2023/08/30 12:28:25 by victorcvaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char **buffer, int is_last_line)
{
	char	*line;
	char	*temp;
	int		line_len;

	line_len = 0;
	while ((*buffer)[line_len] != '\n' && (*buffer)[line_len] != '\0')
		line_len++;
	if ((*buffer)[line_len] == '\n' && (*buffer)[line_len + 1] != '\0')
	{
		line = ft_substr(*buffer, 0, line_len + 1);
		temp = ft_strdup(*buffer + line_len + 1);
		free(*buffer);
		*buffer = temp;
	}
	else
	{
		line = ft_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
	}
	return (line);
}

static void	update_buffer(char **buffer, char *new_buffer)
{
	free(*buffer);
	*buffer = new_buffer;
}

static char	*read_file_content(int fd, char **buffer)
{
	char	*read_buffer;
	int		bytes_read;

	read_buffer = malloc(sizeof(char) * (BUFFER_SIZE + NULL_BYTE));
	if (!read_buffer)
		return (FALSE);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(read_buffer, '\n'))
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			break ;
		read_buffer[bytes_read] = '\0';
		update_buffer(*buffer, ft_strjoin(*buffer, read_buffer));
	}
	free(read_buffer);
	return (get_line(*buffer, bytes_read));
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*curr_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FD_LIMITS)
		return (NULL);
	curr_line = read_file_content(fd, &buffer);
	if (!buffer)
		return (NULL);
	return (curr_line);
}
