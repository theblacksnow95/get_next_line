/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_open_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:40:25 by emurillo          #+#    #+#             */
/*   Updated: 2024/11/12 15:52:57 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
** the function open returns the value of the file descriptor of the file
** read() returns the total value of bytes read.
** each time the file advances it reades the maximum amouts of bytes allowed,
** and at the end if the max is less it will return that number.
** after that read() returns '0', bacause it cannot read more.
** this is how we know we have finished and we can use it in a loop.
**
 */

static char	*get_rest(char *line)
{
	int		i;
	char	*rest;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\0' || line[1] == '\0')
		return (NULL);
	rest = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!rest)
		return (NULL);
	line[i + 1] = '\0';
	return (rest);
}

static char	*fill_line(int fd, char *buffer, char *line)
{
	int		read_bytes;
	char	*rest;

	read_bytes = 1;
	while (read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(buffer);
			return (NULL);
		}
		else if (read_bytes == 0)
			break ;
		buffer[read_bytes] = '\0';
		if (!line)
			line = ft_strdup("");
		rest = line;
		line = ft_strjoin(rest, buffer);
		free(rest);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buffer;
	char		*rest;

	line = NULL;
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE +1);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd , 0 ,0) < 0)
		return (NULL);
	if (!buffer)
		return (NULL);
	line = fill_line(fd, buffer, rest);
	free(buffer);
	if (!line)
		return (NULL);
	rest = get_rest(line);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY | O_CREAT);
	if (fd == -1)
	{
		return (printf("error 1"));
	}
	line = get_next_line(fd);
	while (line >= 0)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
