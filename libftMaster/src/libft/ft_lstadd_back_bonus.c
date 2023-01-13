/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:58:56 by jyurrita          #+#    #+#             */
/*   Updated: 2022/10/01 12:20:58 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_aux;

	if (lst)
	{
		if (*lst)
		{
			lst_aux = ft_lstlast(*lst);
			lst_aux->next = new;
		}
		else
			*lst = new;
	}
}
