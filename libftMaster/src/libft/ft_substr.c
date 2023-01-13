/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 07:37:33 by jyurrita          #+#    #+#             */
/*   Updated: 2022/09/29 12:03:21 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*subs;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (ft_calloc(1, 1));
	if ((ft_strlen(s) - start) < len)
		len = ft_strlen(s) - start;
	if (!*s || (size_t)start > ft_strlen(s))
		return (ft_calloc(1, 1));
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
/*
int main(void)
{
	char * word2;

	word2 = ft_substr("", 1, 1);
	printf("%s", word2);
	return (0);
}*/