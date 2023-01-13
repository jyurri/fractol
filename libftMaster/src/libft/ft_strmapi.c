/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:23:21 by jyurrita          #+#    #+#             */
/*   Updated: 2022/09/28 19:04:12 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	len_str;
	size_t	i;

	if (!s)
		return (NULL);
	len_str = ft_strlen(s);
	result = (char *)malloc((len_str + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len_str)
	{
		result[i] = (*f)(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
char func(unsigned int i, char c)
{
	return (c + i);
}

int main(void)
{
	char (*pfunction)(unsigned int, char);
	char s[] = "hola";
	char *new_s;

	pfunction = &func;
	new_s = ft_strmapi(s, pfunction);
	printf("%s", new_s);
}*/