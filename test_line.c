/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:36:11 by emurillo          #+#    #+#             */
/*   Updated: 2024/11/10 14:53:42 by emurillo         ###   ########.fr       */
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

char	*next_line(char *str)
{
	int		i;
	char	*right_line;
	size_t		len;

	i = 0;
	if (ft_strrchr(str, '\n'))
		len = ft_strlen(str) - ft_strlen(ft_strrchr(str, '\n'));
	else
		len = ft_strlen(str);
	right_line = (char *)malloc((int)(ft_strlen(ft_strrchr(str, '\n'))) +2 * sizeof(char));
	if (!ft_strrchr(str,'\n'))
		while(str[i++])
			right_line[i] = str[i];
	else
	{
		while (str[i + len])
		{
			right_line[i] = str[i + len];
			i++;
		}
	}
	right_line[i] = '\0';
	return (right_line);

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
	right_line = next_line(buffer_text);
	return (right_line);
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
