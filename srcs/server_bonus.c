/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:23:47 by avialle-          #+#    #+#             */
/*   Updated: 2024/02/11 14:49:07 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	print_str(char **str, unsigned long long *i, siginfo_t *info)
{
	ft_printf("%s", *str);
	free(*str);
	*str = NULL;
	*i = 1;
	kill(info->si_pid, SIGUSR2);
}

char	*ft_strjoin_char(char *str, unsigned long long *len, char c)
{
	char		*dest;
	int			i;

	dest = (char *)malloc((*len + 1) * sizeof(char));
	(*len)++;
	if (!dest)
		return (NULL);
	i = 0;
	if (str)
	{
		while (str[i])
		{
			dest[i] = str[i];
			i++;
		}
	}
	dest[i] = c;
	dest[++i] = 0;
	if (str)
		free(str);
	return (dest);
}

void	handler_signal(int signal, siginfo_t *info, void *context)
{
	static unsigned char		c = 0;
	static int					bit = -1;
	static char					*str = NULL;
	static unsigned long long	i = 1;

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
		str = ft_strjoin_char(str, &i, c);
	else if (!bit && !c)
		print_str(&str, &i, info);
	bit--;
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	action;
	sigset_t			signals;

	sigemptyset(&signals);
	sigaddset(&signals, SIGUSR1);
	sigaddset(&signals, SIGUSR2);
	action.sa_flags = SA_SIGINFO;
	action.sa_mask = signals;
	action.sa_handler = NULL;
	action.sa_sigaction = handler_signal;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	ft_printf("PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
