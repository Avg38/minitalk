/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:23:47 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/30 13:44:32 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	signal_handler(int signal, siginfo *info, void *context)
{
	static unsigned	char	c;
	static int				bit;

	c = 0;
	bit = -1;
	if (kill(info->si_pid) < 0)
	{
		ft_printf("Signal can't be send to PID: %d\n", info->si_pid);
		exit(EXIT_FAILURE);
	}
	if (bit < 0)
		bit = __CHAR_BIT__ * sizeof(c) - 1;
	if (signal == SIGUSR1)
		c |= (1 << bit);
	else if (signal == SIGUSR2)
		c &= ~(1 << bit);
	if (!bit && c)
		write(1, &c, 1);
	else if (!bit && !c)
		kill(info->si_pid, SIGUSR2);
	bit--;
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	action;
	sigset_t			signals;

	sigemptyset(&signal);
	sigaddset(&signals, SIGUSR1);
	sigaddset(&signals, SIGUSR2);
	action.sa_flags = SA_SIGINFO;
	action.sa_mask = signals;
	action.sa_handler = NULL;
	action.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	ft_printf("PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
