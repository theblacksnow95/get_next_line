/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:20:57 by emurillo          #+#    #+#             */
/*   Updated: 2024/11/07 18:39:24 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*left_line(char *buf)
{
	char	*line;
	int		i;

	i = 0;
	line = (char *)malloc(ft_strlen(buf) * sizeof(char));
	while (*buf != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	line[i] = '\0';
	buf++;
}

char	*get_next_line(int fd)
{
	size_t			buf_read;
	static char		*buffer_line;
	char			*new_line;

	buffer_line = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer_line)
		return (NULL);
	buf_read = read(fd, buffer_line, BUFFER_SIZE);
	new_line = (char *)ft_calloc((int)ft_strlen(buffer_line) + 1, sizeof(char));
	if (!new_line)
		return (NULL);
	new_line = ft_strjoin(new_line, buffer_line);
	return (new_line);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*join;
	size_t	t_len;
	size_t	j;

	if (!s1)
		s1 = "\0";
	if (!s2)
		s2 = "";
	i = 0;
	j = 0;
	t_len = (ft_strlen(s1) + ft_strlen(s2));
	join = (char *)malloc((t_len + 1) * sizeof(char));
	if (join == NULL)
		return (NULL);
	while (s1[j])
		join[i++] = s1[j++];
	j = 0;
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = '\0';
	return (join);
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
