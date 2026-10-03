/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talkhati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:17:56 by talkhati          #+#    #+#             */
/*   Updated: 2025/10/09 14:45:14 by talkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*get(int fd, char *stash, char *buffer)
{
	ssize_t	bytes;

	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(stash);
			return (NULL);
		}
		buffer[bytes] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
		{
			free(stash);
			return (NULL);
		}
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (stash);
}

char	*extractline(char **str, char **newline)
{
	int		len;
	char	*new_stash;
	char	*line;

	*newline = ft_strchr(*str, '\n');
	if (*newline)
	{
		len = *newline - *str + 1;
		line = ft_substr(*str, 0, len);
		if (!line)
			return (NULL);
		new_stash = ft_substr(*str, len, ft_strlen(*str) - len);
		if (!new_stash)
			free(line);
		free(*str);
		*str = new_stash;
	}
	else
	{
		line = ft_substr(*str, 0, ft_strlen(*str));
		free(*str);
		*str = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*newline;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	stash = get(fd, stash, buffer);
	free(buffer);
	if (!stash || *stash == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = extractline(&stash, &newline);
	return (line);
}
// #include <stdio.h>
// int main()
// {
// int fd = open("1char.txt", O_RDWR);
// // int fd = -1;
// char *line;
// while (((line = get_next_line(fd)) != NULL))
// {
// printf("%s", line);
// free(line);
// }
// close(fd);
// }