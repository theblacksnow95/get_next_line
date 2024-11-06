/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:21:49 by emurillo          #+#    #+#             */
/*   Updated: 2024/11/06 17:21:03 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	unsigned char	*arr;
	size_t			i;

	i = 0;
	arr = malloc(nitems * size);
	if (arr == NULL)
	{
		return (NULL);
	}
	while (i < nitems * size)
		arr[i++] = 0;
	return ((void *)arr);
}


size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	c = c & 0xFF;
	while (str[i] != '\0')
	{
		i++;
	}
	while (i >= 0)
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i--;
	}
	if (c == '\0')
	{
		return ((char *)str);
	}
	return (NULL);
}
