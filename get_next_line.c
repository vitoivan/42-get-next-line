/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:11:51 by victor            #+#    #+#             */
/*   Updated: 2022/03/24 19:00:19 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	get_line_len(char *line)
{
	size_t	size;

	size = 0;
	while (line[size] && line[size] != '\n' && line[size] != '\0')
		size++;
	return (size);
}

static char	*linedup(char **rest, size_t size)
{
	char	*line;
	size_t	i;

	i = 0;
	line = (char *) malloc(sizeof(char) + size);
	if (!line)
	{
		free(*rest);
		return (NULL);
	}
	while (i < size)
	{
		line[i] = (*rest)[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*get_line(char **rest)
{
	size_t	size;
	char	*tmp;
	char	*line;

	size = get_line_len(*rest);
	line = linedup(rest, size + 1);
	tmp = ft_strdup(*(rest) + (size + 1));
	if ((*rest)[size] != '\0')
	{
		free(*rest);
		*rest = tmp;
	}
	else
	{
		free(*rest);
		*rest = NULL;
		free(tmp);
	}
	return (line);
}

static char	*return_line(ssize_t bytes_read, char **rest, char **buffer)
{
	free(*buffer);
	if ((bytes_read > 0 || bytes_read == 0) && *rest != NULL)
		return (get_line(rest));
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	ssize_t		bytes_read;
	static char	*rest;
	char		*aux;

	buffer = malloc(BUFFER_SIZE + 1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		if (rest == NULL)
			rest = ft_strdup(&buffer[0]);
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
