/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:43:30 by jyurrita          #+#    #+#             */
/*   Updated: 2022/09/20 08:26:06 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
/*
int main(void)
{
	printf("\n%d is true", ft_isalpha(97));
	printf("\n%d is false", ft_isalpha(95));
	printf("\n%d is true", ft_isalpha(65));
	printf("\n%d is false", ft_isalpha(91));

}*/