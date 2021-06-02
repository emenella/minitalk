/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emenella <emenella@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:29:29 by emenella          #+#    #+#             */
/*   Updated: 2020/11/26 14:00:56 by emenella         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*strsrc;
	unsigned char	*strdest;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	strsrc = (unsigned char *)src;
	strdest = (unsigned char *)dest;
	while (i < n)
	{
		strdest[i] = strsrc[i];
		i++;
	}
	return ((void *)dest);
}
