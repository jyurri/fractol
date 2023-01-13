/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 11:13:15 by jyurrita          #+#    #+#             */
/*   Updated: 2022/10/01 12:20:26 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lst_aux;

	if (lst && *lst)
	{
		while (*lst)
		{
			lst_aux = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = lst_aux;
		}
	}
}
