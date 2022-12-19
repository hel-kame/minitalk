/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 22:20:15 by hel-kame          #+#    #+#             */
/*   Updated: 2022/12/19 16:12:52 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	one_handler(int signum)
{
	(void)signum;
	ft_printf("USR1 : Sending 0 to server (\U0000FB2A).\n");
}

void	two_handler(int signum)
{
	(void)signum;
	ft_printf("USR2 :Sending 1 to server.\n");
}

int		main(int argc, char **argv)
{
	pid_t pid;

	pid = ft_atoi(argv[1]);
	if (argc < 2 || pid < 0)
		return (-1);
	ft_printf("Try to sending something to PID %d...\n", pid);
	sleep(1);
	signal(SIGUSR1, one_handler);
	kill(pid, SIGUSR1);
	kill(getpid(), SIGUSR1);
	sleep(1);
	signal(SIGUSR2, two_handler);
	kill(pid, SIGUSR2);
	kill(getpid(), SIGUSR2);
	return (0);
}
