/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caeduard <caeduard@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:40:35 by caeduard          #+#    #+#             */
/*   Updated: 2021/12/04 20:47:58 by caeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *src, int fd)
{
	char	*buf;
	int		size;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		free (buf);
		return (NULL);
	}
	size = 1;
	while (!ft_strchr(src, '\n') && size != 0)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
		{
			free (buf);
			return (NULL);
		}
		buf[size] = '\0';
		src = ft_strjoin(src, buf);
	}
	free (buf);
	return (src);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*next_line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	next_line = get_line(next_line, fd);
	if (next_line == NULL)
		return (NULL);
	line = ft_read_line(next_line);
	next_line = ft_save_line(next_line);
	if (line[0] == '\0')
	{
		free(next_line);
		free(line);
		return (NULL);
	}
	return (line);
}
