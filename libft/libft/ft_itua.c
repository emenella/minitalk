/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itua.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emenella <emenella@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 10:00:58 by emenella          #+#    #+#             */
/*   Updated: 2021/02/08 10:01:00 by emenella         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(unsigned int n)
{
	long int	i;

	i = 0;
	if (n <= 0)
	{
		n = -n;
		i++;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	ft_power(unsigned int nb, unsigned int power)
{
	unsigned int	result;

	result = nb;
	if (power == 0)
		return (1);
	--power;
	result *= ft_power(nb, power);
	return (result);
}

char	*ft_itua(unsigned int nbr)
{
	int		i;
	int		len;
	int		chr;
	char	*str;

	i = 0;
	len = ft_len(nbr);
	str = malloc(sizeof(char) * (len-- + 1));
	if (!str)
		return (NULL);
	while (i != len)
	{
		chr = nbr / ft_power(10, len - i);
		nbr -= chr * ft_power(10, len - i);
		str[i++] = chr + '0';
	}
	str[i++] = nbr + '0';
	str[i] = '\0';
	return (str);
}
