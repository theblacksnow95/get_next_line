/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:20:57 by emurillo          #+#    #+#             */
/*   Updated: 2024/11/11 17:38:25 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*left_line(char *buffer)
{
	int			i;
	char		*line;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == 0 || buffer[1] == 0)
		return (NULL);
	line = ft_substr(buffer, i + 1, ft_strlen(buffer) - i);
	if (*line == 0)
	{
		free(line);
		line = NULL;
	}
	line[i + 1] = '\0';
	return (line);
}


static char	*fill_line(int fd, char *buffer, char *new_line)
{
	int		read_bytes;
	char	*temp;

	read_bytes = 1;
	while (read_bytes != '\0')
	{
		read_bytes = read(fd, buffer, new_line);
		if (read_bytes < 0)
			return (NULL);
		if (read_bytes == 0)
			break ;
		buffer[read_bytes] = '\0';
		if (!new_line)
			new_line = ft_strdup("");
		temp = new_line;
		new_line = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (new_line);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*buffer;
	char			*new_line;

	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	line = fill_line(fd, buffer, new_line);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	new_line = left_line(line);
	return (new_line);
}

int	main(void)
{
	char	*str;
	int		fd;

	fd = open("test.txt", O_RDONLY | O_CREAT);
	if (fd == -1)
	{
		return (printf("error 1"));
	}
	str = get_next_line(fd);
	printf("%s\n", str);
	str = get_next_line(fd);
	printf("%s\n", str);
}
