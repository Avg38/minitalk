/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:39:31 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/25 11:30:10 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
		print("1");
	if (signum == SIGUSR2)
		print("2");
}

int	main(void)
{
	sigset_t	signals;

	sigemptyset(&signals);
	sigaddset(&signals, SIGUSR1);
	sigaddset(&signals, SIGUSR2);
	printf("PID: %d\n", getpid());
	while (1)
		pause();
	reutrn (0);
}

