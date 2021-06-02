/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emenella <emenella@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 21:49:41 by emenella          #+#    #+#             */
/*   Updated: 2020/11/28 05:15:14 by emenella         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nextlst;

	if (lst)
	{
		while (*lst)
		{
			nextlst = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = nextlst;
		}
	}
}
