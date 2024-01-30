/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:23:52 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/30 11:51:24 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	g_bit_hander;

void validation_server(int signal)
{
	
}

int	check_args(int ac, char **av)
{
	
}

void	send_bit(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (0x01 << bit) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(10);
		bit++;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;
	int		i;

	pid = check_args(ac, av);
	i = -1;
	signal(SIGUSR1, validation_server);
	signal(SIGUSR2, validation_server);
	while (av[2][++i])
		send_bit(pid, av[2][i]);
	send_bit(pid, '\n');
	send_bit(pid, 0);
	while (1)
		pause();
	return (0);
}