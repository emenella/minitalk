/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emenella <emenella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 05:17:37 by emenella          #+#    #+#             */
/*   Updated: 2020/11/26 21:39:25 by emenella         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		length;
	char	*result;

	result = NULL;
	length = ft_strlen(s);
	i = 0;
	while (i < length + 1)
	{
		if (c == s[i])
			result = (char *)&s[i];
		i++;
	}
	return (result);
}
