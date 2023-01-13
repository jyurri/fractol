/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:06:44 by jyurrita          #+#    #+#             */
/*   Updated: 2022/10/01 12:21:55 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newhead;

	newhead = (struct s_list *)(malloc(sizeof(t_list)));
	if (!newhead)
		return (NULL);
	newhead->content = content;
	newhead->next = NULL;
	return (newhead);
}
