/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:21:43 by emurillo          #+#    #+#             */
/*   Updated: 2024/11/05 15:58:02 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 50
# include <unistd.h>
# include <fcntl.h>

void	*ft_calloc(size_t nitems, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(char const *str);


#endif
