/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emenella <emenella@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:32:57 by emenella          #+#    #+#             */
/*   Updated: 2020/11/29 04:00:02 by emenella         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*strs1;
	unsigned char	*strs2;

	i = 0;
	strs1 = (unsigned char *)s1;
	strs2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n - 1 && strs1[i] == strs2[i])
		i++;
	return (strs1[i] - strs2[i]);
}
