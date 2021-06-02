/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emenella <emenella@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:46:43 by emenella          #+#    #+#             */
/*   Updated: 2020/11/29 03:42:53 by emenella         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	spacejump(int *i, const char *nptr, int *j)
{
	while ((nptr[*i] >= 9 && nptr[*i] <= 13) || nptr[*i] == 32)
		*i += 1;
	*j = *i;
}

void	signjump(int *i, const char *nptr, int *minuscount)
{
	if (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i] == '-')
			*minuscount = 1;
		*i += 1;
	}
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	j;
	int	minuscount;
	int	result;

	i = 0;
	minuscount = 0;
	result = 0;
	spacejump(&i, nptr, &j);
	signjump(&i, nptr, &minuscount);
	while (ft_isdigit(nptr[i]))
	{
		result *= 10;
		result += nptr[i++] - 48;
	}
	if (minuscount == 1)
		result = -result;
	return (result);
}
