/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:23:52 by avialle-          #+#    #+#             */
/*   Updated: 2024/02/12 13:29:11 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	g_bit_handler;

void	validation_server(int signal)
{
	if (signal == SIGUSR2)
	{
		ft_printf("Message sent and receive.\n");
		exit(EXIT_SUCCESS);
	}
	else if (signal == SIGUSR1)
		g_bit_handler = 1;
}

int	check_args(int ac, char **av)
{
	pid_t	pid;
	int		i;

	if (ac != 3 || !av[2][0])
	{
		ft_printf("Error: arguments, please try again.\n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(av[1]);
	if (pid == 0)
	{
		ft_printf("Error: PID 0 reserved for the kernel.\n");
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (av[1][++i])
	{
		if (!(ft_isdigit(av[1][i]) || pid < 0))
		{
			ft_printf("Error: PID only has positive decimal numbers");
			exit(EXIT_FAILURE);
		}
	}
	return (pid);
}

void	send_bit(pid_t pid, char c)
{
	int	bit;

	bit = __CHAR_BIT__ * sizeof(c) - 1;
	while (bit >= 0)
	{
		g_bit_handler = 0;
		if ((c & (1 << bit)))
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
	signal(SIGUSR1, validation_server);
	signal(SIGUSR2, validation_server);
	while (av[2][++i])
		send_bit(pid, av[2][i]);
	send_bit(pid, '\n');
	send_bit(pid, 0);
	while (1)
		pause();
}
