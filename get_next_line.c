/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:20:57 by emurillo          #+#    #+#             */
/*   Updated: 2024/11/12 19:36:21 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* static char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
} */


static char	*left_line(char *buffer)
{
	int			i;
	char		*line;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0' || buffer[1] == '\0')
		return (NULL);
	line = ft_substr(buffer, i + 1, ft_strlen(buffer) - i);
	if (*line == 0)
	{
		free(line);
		line = NULL;
	}
	buffer[i + 1] = '\0';
	return (line);
}

static char	*fill_line(int fd, char *buffer, char *new_line)
{
	int		read_bytes;
	char	*temp;

	read_bytes = 1;
	while (read_bytes != '\0')
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
		if (!new_line)
			new_line = ft_strdup("");
		temp = ft_strdup(new_line);
		new_line = ft_strjoin(temp, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (new_line);
}

char	*get_next_line(int fd)
{
	char			*line;
	char			*buffer;
	static char		*new_line;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(new_line);
		free(buffer);
		buffer = NULL;
		new_line = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = fill_line(fd, buffer, new_line);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	new_line = left_line(line);
	return (line);
}

/* int	main(void)
{
	char	*str;
	int		fd;

	fd = open("test.txt", O_RDONLY | O_CREAT);
	if (fd == -1)
	{
		return (printf("error 1"));
	}
	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
} */

