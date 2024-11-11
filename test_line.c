/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:36:11 by emurillo          #+#    #+#             */
/*   Updated: 2024/11/11 17:05:46 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_line(char *buffer)
{
	int			i;
	char		*line;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == 0 || buffer[1] == 0)
		return (NULL);
	line = (char *)malloc(i + 2);
	if (!line)
		return (NULL);
	i = -1;
	while (buffer[++i] && buffer[i] != '\n')
		line[i] = buffer[i];
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*next_line(char *str)
{
	int			i;
	char		*right_line;
	int			j;

	i = 0;
	j = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	right_line = (char *)malloc((int)ft_strlen(str) - i + 1);
	if (!right_line)
		return (NULL);
	i++;
	while (str[i])
		right_line[j++] = str[i++];
	right_line[j] = '\0';
	free(str);
	return (right_line);

}


char	*get_line(int fd)
{
	static char	*left_line;
	char		buffer_text[BUFFER_SIZE + 1];
	char		*right_line;
	int			bytes_read;

	left_line = NULL;
	while (!ft_strchr(left_line, '\n'))
	{
		bytes_read = read(fd, buffer_text, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		if (bytes_read == 0)
			break ;
		buffer_text[bytes_read] = '\0';
		if (!left_line)
			left_line = ft_strdup("");
		left_line = ft_strjoin(left_line, buffer_text);
	}
	right_line = fill_line(left_line);
	return (right_line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY | O_CREAT);
	if (fd < 0)
		return (1);
	line = get_line(fd);
	while ((line))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}




