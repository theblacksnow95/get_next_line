/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:21:49 by emurillo          #+#    #+#             */
/*   Updated: 2024/11/05 15:59:31 by emurillo         ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*join;
	size_t	t_len;
	size_t	j;

	if (!s1)
		s1 = "";
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

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
