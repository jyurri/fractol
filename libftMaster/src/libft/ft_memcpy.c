/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:35:28 by jyurrita          #+#    #+#             */
/*   Updated: 2022/09/28 12:34:03 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (n > 0)
	{
		*((char *)dst + i) = *((char *)src + i);
		n--;
		i++;
	}
	return (dst);
}
/*
int main(void)
{
	char word1[20] = "holasd";
	// char word2[20] = "adios";
	char *pword;
	char *pword2 = word1 + 4;
	pword = ft_memcpy(pword2, word1, 10);
	printf("%s\n", pword);
	pword = memcpy(pword2, word1, 10);
	printf("%s", pword);
}*/