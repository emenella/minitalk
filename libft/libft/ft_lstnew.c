/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emenella <emenella@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:46:13 by emenella          #+#    #+#             */
/*   Updated: 2020/11/26 18:55:31 by emenella         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(char *content)
{
	struct s_list	*list;

	list = malloc(sizeof(struct s_list));
	if ((void *)list == NULL)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}
