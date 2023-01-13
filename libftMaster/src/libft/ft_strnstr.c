/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 08:10:51 by jyurrita          #+#    #+#             */
/*   Updated: 2022/09/27 17:35:24 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_needle(const char *haystack, const char *needle);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (*needle == 0)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (haystack[i] && i < len && ((i + ft_strlen(needle)) <= len))
	{
		if (is_needle(haystack + i, needle) == 1)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}

static int	is_needle(const char *haystack, const char *needle)
{
	int	i;

	i = 0;
	while (((char *)needle)[i])
	{
		if (((char *)haystack)[i] != ((char *)needle)[i])
			return (0);
		i++;
	}
	return (1);
}
/*
int main(void)
{
	char word1[] = "";
	char word2[] = "";
	printf("%s", ft_strnstr(word1, word2, 0));
}*/