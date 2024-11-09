/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:36:11 by emurillo          #+#    #+#             */
/*   Updated: 2024/11/09 20:50:23 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char	*fill_line(char *buffer)
{
	int			i;
	static char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_line(int fd)
{
	char	*left_line;
	char	buffer_text[BUFFER_SIZE + 1];
	char	*right_line;
	int		bytes_read;

	bytes_read = read(fd, buffer_text, BUFFER_SIZE);
	if (bytes_read < 0)
		return (NULL);
	buffer_text[bytes_read] = '\0';
	left_line = fill_line(buffer_text);
	right_line = new_buf(char *str, BUFFER_SIZE);
	return (left_line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY | O_CREAT);
	line = get_line(fd);
	printf("%s\n", line);
	line = get_line(fd);
	printf("%s\n", line);
	line = get_line(fd);
	printf("%s\n", line);
	line = get_line(fd);
	printf("%s\n", line);
	line = get_line(fd);
	printf("%s\n", line);
	close(fd);
	return (0);
}
