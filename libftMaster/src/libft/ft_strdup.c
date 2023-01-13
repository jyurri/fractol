/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 07:16:10 by jyurrita          #+#    #+#             */
/*   Updated: 2022/09/20 08:32:55 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*new_string;

	len = ft_strlen(s1);
	new_string = (char *)malloc((len + 1) * sizeof(char));
	if (new_string == NULL)
		return (NULL);
	ft_strlcpy(new_string, s1, len + 1);
	return (new_string);
}
/*
int main(void)
{
	char word1[20] = "hola";
	char * word2;

	word2 = ft_strdup(word1);
	printf("%s", word2);
}*/