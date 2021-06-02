/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emenella <emenella@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:07:12 by emenella          #+#    #+#             */
/*   Updated: 2020/11/26 21:16:43 by emenella         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*strdst;
	unsigned char	*strsrc;
	size_t			i;

	strdst = (unsigned char *)dst;
	strsrc = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst > src)
	{
		while (n > 0)
		{
			strdst[n - 1] = strsrc[n - 1];
			n--;
		}
	}
	else
	{
		i = -1;
		while (++i < n)
			strdst[i] = strsrc[i];
	}
	return (dst);
}
