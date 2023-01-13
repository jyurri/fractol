/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:48:51 by jyurrita          #+#    #+#             */
/*   Updated: 2022/09/19 13:32:37 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/*
int main(void)
{
	printf("\n%d is true", ft_isdigit(48));
	printf("\n%d is false", ft_isdigit(47));
	printf("\n%d is true", ft_isdigit(57));
	printf("\n%d is false", ft_isdigit(58));
		printf("\n%d is false", ft_isdigit(58));


}*/