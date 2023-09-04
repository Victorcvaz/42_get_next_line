/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorcvaz <victorcvaz@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 00:46:47 by victorcvaz        #+#    #+#             */
/*   Updated: 2023/09/04 02:36:43 by victorcvaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	read_file_content(int fd, char **buffer);
static char	*get_line(char **buffer);
static void	update_buffer(char **buffer, char *new_buffer);

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

static void	read_file_content(int fd, char **buffer)
{
	char	*read_buffer;
	int		bytes_read;

	read_buffer = malloc(sizeof(char) * (BUFFER_SIZE + NULL_BYTE));
	if (!read_buffer)
		return ;
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(read_buffer, '\n'))
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			break ;
		read_buffer[bytes_read] = '\0';
		update_buffer(buffer, ft_strjoin(*buffer, read_buffer));
	}
	if (read_buffer[0] == '\0' && (!*buffer || !**buffer))
		update_buffer(buffer, NULL);
	return (free(read_buffer));
}

static char	*get_line(char **buffer)
{
	char	*line;
	int		line_len;

	line_len = 0;
	while ((*buffer)[line_len] != '\n' && (*buffer)[line_len] != '\0')
		line_len++;
	if ((*buffer)[line_len] == '\0')
	{
		line = ft_strdup(*buffer);
		update_buffer(buffer, NULL);
		return (line);
	}
	line = ft_substr(*buffer, 0, line_len + LINE_BREAK);
	update_buffer(buffer, ft_strdup(*buffer + line_len + LINE_BREAK));
	return (line);
}

static void	update_buffer(char **buffer, char *new_buffer)
{
	if (*buffer)
		free(*buffer);
	*buffer = new_buffer;
}
