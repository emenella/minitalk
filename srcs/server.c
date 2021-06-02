/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emenella <emenella@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:06:39 by emenella          #+#    #+#             */
/*   Updated: 2021/05/31 17:39:47 by emenella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_pid(void)
{
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
}

void	write_char(int sig)
{
	static char unsigned	c = 0;
	static int				i = 0;

	c |= (sig << i++);
	if (i > 7)
	{
		if (c == '\0')
		{
			ft_putchar_fd('\n', 1);
			ft_putchar_fd(c, 1);
		}
		else
			ft_putchar_fd(c, 1);
		i = 0;
		c = 0;
	}
}

void	write_signal(int code)
{
	if (code == SIGUSR1)
		write_char(0);
	if (code == SIGUSR2)
		write_char(1);
}

void	init_signal(void)
{
	if (signal(SIGUSR1, &write_signal) == SIG_ERR)
	{
		ft_putstr_fd("Error: initialize of signal is failed", 1);
		exit(0);
	}
	if (signal(SIGUSR2, &write_signal) == SIG_ERR)
	{
		ft_putstr_fd("Error: initialize of signal is failed", 1);
		exit(0);
	}
}

int	main(void)
{
	print_pid();
	init_signal();
	while (1)
		pause();
	return (0);
}
