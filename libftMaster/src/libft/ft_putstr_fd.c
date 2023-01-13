/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:02:01 by jyurrita          #+#    #+#             */
/*   Updated: 2022/09/29 09:45:19 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			write(fd, s, 1);
			s++;
		}
	}
}
/*
int main(void)
{
	char str[] = "hola";
	int fd = open("test_file.txt", O_WRONLY | O_CREAT | O_TRUNC);
	ft_putstr_fd(str, fd);
	close(fd);
}*/