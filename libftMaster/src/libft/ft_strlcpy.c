/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:07:51 by jyurrita          #+#    #+#             */
/*   Updated: 2022/09/27 10:53:17 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	int		len_scr;

	i = 0;
	len_scr = 0;
	while (src[len_scr])
		len_scr++;
	while (i + 1 < dstsize && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (len_scr);
}

/*
int main(void)
{
	char word1[20] = "hola";
	char word2[20] = "adios";
	int size;
	size = ft_strlcpy(word2, word1, 4);
	printf("%s, %d", word2, size);

}*/