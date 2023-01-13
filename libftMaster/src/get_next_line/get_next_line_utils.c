/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:52:25 by jyurrita          #+#    #+#             */
/*   Updated: 2022/12/16 10:21:18 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *s)
{
	size_t	n;

	n = 0;
	while (*s != '\0')
	{
		n++;
		s++;
	}
	return (n);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	total_len;
	char	*new_str;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	new_str = (char *)malloc((total_len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		new_str[i] = *s2;
		i++;
		s2++;
	}
	new_str[i] = '\0';
	free(s1);
	return (new_str);
}

char	*ft_strdup_gnl(char *s1)
{
	int		len;
	char	*new_string;
	size_t	i;

	i = 0;
	len = ft_strlen_gnl(s1);
	new_string = (char *)malloc((len + 1) * sizeof(char));
	if (new_string == NULL)
		return (NULL);
	while ((int)i < len)
	{
		new_string[i] = s1[i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*subs;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (ft_strdup_gnl(""));
	if ((ft_strlen_gnl(s) - start) < len)
		len = ft_strlen_gnl(s) - start;
	if (!*s || (size_t)start > ft_strlen_gnl(s))
		return (ft_strdup_gnl(""));
	while (start > i && s[i])
		i++;
	subs = (char *)malloc((len + 1) * sizeof(char));
	if (subs == NULL)
		return (NULL);
	while (j < len && s[i])
	{
		subs[j] = s[i];
		i++;
		j++;
	}
	subs[j] = '\0';
	return (subs);
}

char	*ft_strchr_gnl(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)c == (unsigned char)s[i])
			return ((char *)s + i);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}
