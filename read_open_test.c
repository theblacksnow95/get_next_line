/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_open_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:40:25 by emurillo          #+#    #+#             */
/*   Updated: 2024/11/06 17:21:01 by emurillo         ###   ########.fr       */
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

int	main(void)
{
	int		fd;
	int		cs;
	char	*c;

	c = (char *)calloc(100, sizeof(char));
	fd = open("test.txt", O_RDONLY | O_CREAT);
	if (fd == -1)
	{
		return (printf("error 1"));
	}
	printf("Value of 'fd': %d\n\n", fd);
	cs = read(fd, c, BUFFER_SIZE);
	printf("first value of read: %d\n", cs);
	while (cs > 0)
	{
		c[cs] = '\0';
		printf("\n%d\n", cs);
		printf("\nbuf -> %s\n", c);
		cs = read(fd, c, BUFFER_SIZE);
	}
	printf("final value od read(): %d\n", cs);
	close(fd);
}
