/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:08:02 by victor            #+#    #+#             */
/*   Updated: 2022/03/26 13:46:45 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	n;

	n = 0;
	if (s == NULL)
		return (0);
	while (s[n] && s[n] != '\0')
		n++;
	return ((size_t) n);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		s_len;
	char		*d;
	const char	*s;

	if (!dst || !src)
		return (0);
	d = dst;
	s = src;
	s_len = ft_strlen(s);
	if (!size)
		return (s_len);
	while (size - 1 && *s)
	{
		*d++ = *s++;
		size--;
	}
	*d = '\0';
	return (s_len);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	l;

	l = ft_strlen(s) + 1;
	ptr = malloc(l * sizeof(char));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s, l);
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*output;
	size_t	l_s1;
	size_t	l_s2;

	if (!s1 || !s2)
		return (NULL);
	l_s1 = ft_strlen(s1);
	l_s2 = ft_strlen(s2);
	output = malloc((l_s1 + l_s2 + 1) * sizeof(char));
	if (output == NULL)
		return (NULL);
	ft_strlcpy(output, s1, l_s1 + 1);
	ft_strlcpy((output + l_s1), s2, l_s2 + 1);
	return (output);
}

char	*ft_strchr(const char *s, int c)
{
	const char	*tmp;

	if (!s)
		return (NULL);
	tmp = s;
	while (*tmp)
	{
		if ((unsigned char) *tmp == (unsigned char) c)
			return ((char *) tmp);
		tmp++;
	}
	if ((unsigned char) *tmp == (unsigned char) c)
		return ((char *) tmp);
	return (NULL);
}
