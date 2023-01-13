/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 08:13:11 by jyurrita          #+#    #+#             */
/*   Updated: 2022/09/29 12:15:23 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	if (s && f)
	{
		while (s[i])
		{
			f(i, s + i);
			i++;
		}
	}
}
/*
static void fun(unsigned int i, char *s)
{
	s[i] = 'a';
}
int main(void)
{
	void (*pfun)(unsigned int, char *);
	char str[] = "olee";
	pfun = &fun;
	ft_striteri(str, pfun);
	printf("%s", str);
}*/