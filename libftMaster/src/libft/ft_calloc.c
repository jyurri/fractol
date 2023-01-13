/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:18:26 by jyurrita          #+#    #+#             */
/*   Updated: 2022/09/29 13:08:03 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*array;

	if (size * count < count && size * count < size)
		return (NULL);
	array = malloc(count * size);
	if (!array)
		return (NULL);
	ft_memset(array, '\0', count * size);
	return (array);
}
/*
 int main(void)
 {
	 char * arr;
	 int i;

	 i = 0;
	 arr = (char *)ft_calloc(3, sizeof(char));
	 *arr='1';
	 *(arr + 1)='2';
	 *(arr + 2)='\0';
	 while (arr[i])
	 {
		 printf("hola: %c,", *arr);
		 i++;
	 }
	 free(arr);

 }*/