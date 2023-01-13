/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:12:29 by jyurrita          #+#    #+#             */
/*   Updated: 2022/09/28 19:08:58 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			write(fd, s, 1);
			s++;
		}
		write(fd, "\n", 1);
	}
}
/*
int main(void)
{
	char str[] = "hola";
	int fd = open("test_file.txt", O_WRONLY | O_CREAT | O_TRUNC);
	ft_putendl_fd(str, fd);
	close(fd);
}*/