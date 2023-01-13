/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:36:15 by jyurrita          #+#    #+#             */
/*   Updated: 2022/09/21 17:33:38 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dst_aux;
	char	*src_aux;

	if (!src && !dst)
		return (0);
	dst_aux = (char *)dst;
	src_aux = (char *)src;
	i = 0;
	if (dst > src)
		while (len-- > 0)
			dst_aux[len] = src_aux[len];
	else
	{
		while (i < len)
		{
			dst_aux[i] = src_aux[i];
			i++;
		}
	}
	return (dst);
}
/*
int main(void)
{
	char word1[20] = "holaei";
	//char word2[20] = "adio";
	char *pword;
	char *pword2 = word1 + 2;
	pword = ft_memmove(word1, pword2, 3);
	//pword = memmove(word1, pword2, 3);
	printf("%s", pword);
}*/