/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:17:44 by jyurrita          #+#    #+#             */
/*   Updated: 2022/09/29 09:49:10 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	lnum;
	char		c;

	lnum = n;
	if (lnum < 0)
	{
		lnum = lnum * -1;
		write(fd, "-", 1);
	}
	if (lnum >= 10)
	{
		c = lnum % 10 + '0';
		lnum = lnum / 10;
		ft_putnbr_fd(lnum, fd);
		write(fd, &c, 1);
	}
	else
	{
		c = lnum % 10 + '0';
		write(fd, &c, 1);
	}
}
/*
int main(void)
{
	int num = -214748648;
	int fd = open("test_file.txt", O_WRONLY | O_CREAT | O_TRUNC);
	write(fd, "c", 4);
	close(fd);
}*/