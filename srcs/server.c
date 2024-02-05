/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:39:31 by avialle-          #+#    #+#             */
/*   Updated: 2024/02/05 11:22:21 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				bit = -1;

	(void)context;
	if (kill(info->si_pid, 0) < 0)
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
	bit--;
}

int	main(void)
{
	sigset_t			signals;
	struct sigaction	action;

	sigemptyset(&signals);
	sigaddset(&signals, SIGUSR1);
	sigaddset(&signals, SIGUSR2);
	action.sa_flags = SA_SIGINFO;
	action.sa_mask = signals;
	action.sa_handler = NULL;
	action.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	printf("PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}

