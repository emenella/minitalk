/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emenella <emenella@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 03:29:28 by emenella          #+#    #+#             */
/*   Updated: 2020/12/02 02:24:06 by emenella         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	*ft_gnlnew(int fd)
{
	t_gnl	*gnl;

	gnl = malloc(sizeof(t_gnl));
	if (!gnl)
		return (NULL);
	gnl->content = ft_strdup("");
	gnl->fd = fd;
	gnl->next = NULL;
	return (gnl);
}

void	ft_gnladd_back(t_gnl **alst, int fd)
{
	t_gnl	*lstlast;

	lstlast = *alst;
	if (lstlast)
		while (lstlast->next != NULL)
			lstlast = lstlast->next;
	if (lstlast == NULL)
		*alst = ft_gnlnew(fd);
	else
		lstlast->next = ft_gnlnew(fd);
}
