/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emenella <emenella@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:28:21 by emenella          #+#    #+#             */
/*   Updated: 2021/06/18 14:37:12 by emenella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, int nb)
{
	if (nb == 0 && kill(pid, SIGUSR1) == -1)
	{
		ft_putstr_fd("Error: failure to send signal\n", 1);
		exit(0);
	}
	if (nb == 1 && kill(pid, SIGUSR2) == -1)
	{
		ft_putstr_fd("Error: failure to send signal\n", 1);
		exit(0);
	}
}

void	send_char_to_pid(int pid, char c)
{
	int	i;
	int	nb;

	i = 0;
	while (i < 8)
	{
		nb = (c >> i++) & 1;
		send_signal(pid, nb);
		pause();
	}
}

void	send_str_to_pid(int pid, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		send_char_to_pid(pid, str[i]);
	send_char_to_pid(pid, 0);
}

void	handler(int sig)
{
	sig = 0;
}

int	main(int argc, char **arg)
{
	int	pid_server;

	if (argc == 3)
	{
		pid_server = ft_atoi(arg[1]);
		if (pid_server <= 1)
			ft_putstr_fd("Error PID\n", 1);
		signal(SIGUSR1, &handler);
		send_str_to_pid(pid_server, arg[2]);
	}
	else
		ft_putstr_fd("./client <PID server> <message>\n", 1);
	return (0);
}
