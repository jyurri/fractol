/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 07:44:01 by jyurrita          #+#    #+#             */
/*   Updated: 2022/09/27 16:44:26 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)c == ((unsigned char *)s)[i])
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
	char word[] = "hola";
	printf("%s\n", ft_memchr(word, 'l', 3));
	printf("%s\n", memchr(word, 'l', 3));
	printf("%s\n", ft_memchr(word, 2, 3));
	printf("%s\n", word + 2);
}*/