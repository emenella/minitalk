/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emenella <emenella@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:22:07 by emenella          #+#    #+#             */
/*   Updated: 2020/11/28 03:40:02 by emenella         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	lenneedle;

	i = 0;
	lenneedle = ft_strlen(needle);
	ft_strlen(haystack);
	if (lenneedle == 0)
		return ((char *)haystack);
	while (i < len && i + lenneedle <= len)
	{
		if (ft_strncmp(haystack, needle, lenneedle) == 0)
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (NULL);
}
