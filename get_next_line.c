/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:11:51 by victor            #+#    #+#             */
/*   Updated: 2022/03/23 17:15:09 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*linedup(char **rest, size_t size)
{
	char	*line;

	line = (char *) malloc(sizeof(char) + size);
	if (!line)
	{
		free(*rest);
		return (NULL);
	}
	line[size] = '\0';
	size--;
	while (size >= 1)
	{
		line[size] = rest[0][size];
		size--;
	}
	line[0] = rest[0][0];
	return (line);
}

static char	*get_line(char **rest)
{
	size_t	size;
	char	*tmp;
	char	*line;

	size = 0;
	while (rest[0][size] && rest[0][size] != '\n')
		size++;
	line = linedup(rest, size + 1);
	tmp = ft_strdup(*(rest) + (size + 1));
	free(*rest);
	if (ft_strlen(tmp) > 0 && (*rest)[size] != '\0')
		*rest = tmp;
	else
	{
		*rest = NULL;
		free(tmp);
	}
	return (line);
}

static char	*return_line(ssize_t bytes_read, char **rest, char **buffer)
{
	free(*buffer);
	if (bytes_read > 0 || *rest != NULL)
		return (get_line(rest));
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	ssize_t		bytes_read;
	static char	*rest;
	char		*aux;

	buffer = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		if (rest == NULL)
			rest = ft_strdup(buffer);
		else
		{
			aux = ft_strjoin(rest, buffer);
			free(rest);
			rest = aux;
		}
		if (ft_strchr(buffer, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	return (return_line(bytes_read, &rest, &buffer));
}
