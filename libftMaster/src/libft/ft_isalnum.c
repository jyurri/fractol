/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:52:13 by jyurrita          #+#    #+#             */
/*   Updated: 2022/09/27 09:44:12 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1);
	else
		return (0);
}
/*
int main(void)
{
	printf("\n%d is true", ft_isalnum(33));
	printf("\n%d is false", ft_isalnum(32));
	printf("\n%d is true", ft_isalnum(127));
	printf("\n%d is false", ft_isalnum(128));

}*/