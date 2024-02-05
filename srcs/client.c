/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:39:34 by avialle-          #+#    #+#             */
/*   Updated: 2024/02/02 13:11:09 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
int	g_bit_handler;

int	check_args(int ac, char **av)
{
	pid_t	pid;
	int		i;

	if (ac != 3 || !av[2][0])
	{
		ft_putstr_fd("Error: arguments, please try again.\n", 2);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(av[1]);
	if (pid == 0)
	{
		ft_putstr_fd("Error: PID 0 reserved for the kernel.\n", 2);
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (av[1][++i])
	{
		if (!(ft_isdigit(av[1][i]) || pid < 0))
		{
			ft_putstr_fd("Error: PID only has positive decimal numbers", 2);
			exit(EXIT_FAILURE);
		}
	}
	return (pid);
}

void	send_bit(int pid, char c)
{
	int	bit;

	bit = __CHAR_BIT__ * sizeof(c) - 1;
	while (bit >= 0)
	{
		g_bit_handler = 0;
		if ((c & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
		while (g_bit_handler != 1)
			usleep(100);
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;
	int		i;

	pid = check_args(ac, av);
	i = -1;
	while (av[2][++i])
		send_bit(pid, av[2][i]);
	send_bit(pid, '\n');
	send_bit(pid, 0);
	return (0);
}
