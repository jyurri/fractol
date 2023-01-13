/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:46:21 by jyurrita          #+#    #+#             */
/*   Updated: 2022/09/28 16:22:27 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	chr;

	chr = (char)c;
	ptr = NULL;
	while (*s)
	{
		if (*s == chr)
			ptr = (char *)s;
		s++;
	}
	if (*s == chr)
		ptr = (char *)s;
	return (ptr);
}
/*
int main(void)
{
	char word[] = "aholao";
	printf("%s", ft_strrchr(word, 'q'));
}*/