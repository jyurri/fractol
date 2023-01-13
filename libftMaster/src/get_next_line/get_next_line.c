/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 08:58:42 by jyurrita          #+#    #+#             */
/*   Updated: 2022/12/16 10:32:32 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0)
		return (NULL);
	if (stash && *stash && ft_strchr_gnl(stash, '\n'))
		line = get_line_from_stash(&stash);
	else
	{
		fill_stash(&stash, fd);
		line = get_line_from_stash(&stash);
	}
	if (!line)
	{
		free(stash);
		return (NULL);
	}
	return (line);
}

char	*get_line_from_stash(char **stash)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!*stash || !**stash)
		return (NULL);
	while ((*stash)[i] != '\n' && (*stash)[i] != '\0')
		i++;
	if ((*stash)[i] == '\n')
		i++;
	line = ft_substr_gnl(*stash, 0, i);
	clear_stash(stash, i);
	return (line);
}

void	fill_stash(char **stash, int fd)
{
	int			size_read;
	char		*buf;

	size_read = 1;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (buf && size_read > 0)
	{
		size_read = read(fd, buf, BUFFER_SIZE);
		if (size_read == -1)
			break ;
		buf[size_read] = '\0';
		if (size_read > 0)
		{
			fill_stash_from_buf(stash, buf);
			if (ft_strchr_gnl(buf, '\n'))
				break ;
		}
	}
	free(buf);
}

void	clear_stash(char **stash, size_t i)
{
	char	*temp_stash;
	size_t	j;

	j = 0;
	if ((*stash)[i])
	{
		while ((*stash)[j + i] != '\0')
			j++;
		temp_stash = *stash;
		*stash = ft_substr_gnl(*stash, i, j);
		free(temp_stash);
	}
	else
	{
		free(*stash);
		*stash = NULL;
	}
}

void	fill_stash_from_buf(char **stash, char *buf)
{
	if (*stash)
		*stash = ft_strjoin_gnl(*stash, buf);
	else
	{
		*stash = ft_strdup_gnl(buf);
	}
}
