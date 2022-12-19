/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 22:20:15 by hel-kame          #+#    #+#             */
/*   Updated: 2022/12/19 21:48:42 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	str_to_binary(char *s, pid_t pid)
{
	int		i;
	int		y;
	char	ch;

	i = 0;
	y = 7;
	while (i < (int)ft_strlen(s))
	{
		ch = s[i];
		while (y >= 0)
		{
			if(ch & (1 << y)) {
				ft_printf("1");
				kill(pid, SIGUSR1);
			} else {
				ft_printf("0");
				kill(pid, SIGUSR2);
			}
			y--;
		}
		ft_printf("i = %d\n", i);
		i++;
	}
}

void	one_handler(int signum)
{
	(void)signum;
	ft_printf("USR1 : Sending 0 to server.\n");
}

void	two_handler(int signum)
{
	(void)signum;
	ft_printf("USR2 : Sending 1 to server.\n");
}

int		main(int argc, char **argv)
{
	pid_t pid;

	pid = ft_atoi(argv[1]);
	if (argc < 3 || pid < 0)
		return (-1);
	ft_printf("Try to sending something to PID %d...\n", pid);
	sleep(1);
	str_to_binary(argv[2], pid);
/*	if (kill(pid, SIGUSR1) == 0)
	{
		signal(SIGUSR1, one_handler);
		kill(getpid(), SIGUSR1);
	}
	usleep(1000);
	if (kill(pid, SIGUSR2) == 0)
	{
		signal(SIGUSR2, two_handler);
		kill(getpid(), SIGUSR2);
	}*/
	return (0);
}
