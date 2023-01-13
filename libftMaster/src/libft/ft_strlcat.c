/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:37:03 by jyurrita          #+#    #+#             */
/*   Updated: 2022/09/30 12:59:50 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_src;
	size_t	len_dst;

	len_dst = 0;
	len_src = 0;
	i = 0;
	while (dst[len_dst] && len_dst < dstsize)
		len_dst++;
	while (src[len_src])
		len_src++;
	if (dstsize <= len_dst)
		return (len_src + dstsize);
	while (src[i] != '\0' && ((len_dst + i) < (dstsize - 1)))
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}

/*
int main(void)
{
	char word1[20] = "hola";
	char word2[20] = "adios";
	int size;
	size = ft_strlcat(word2, word1, 9);
	printf("%s, %d", word2, size);
}*/