/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emenella <emenella@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:34:32 by emenella          #+#    #+#             */
/*   Updated: 2020/11/28 04:50:13 by emenella         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*result;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (ft_isset(s1[i], (char *)set) && s1[i])
		i++;
	start = i;
	i = ft_strlen(s1);
	while (ft_isset(s1[i - 1], (char *)set) && start < i)
		i--;
	end = i;
	if (start > end)
		return (NULL);
	result = malloc(sizeof(char) * end - start + 1);
	if (result == NULL)
		return (NULL);
	ft_bzero((void *)result, end - start + 1);
	return (ft_memcpy(result, s1 + start, end - start));
}
