/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 21:54:08 by hel-kame          #+#    #+#             */
/*   Updated: 2022/12/20 20:47:32 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signal_checker(int signum, siginfo_t *siginfo, void *ucontext)
{
	(void)ucontext;
	if (signum != SIGUSR1 && signum != SIGUSR2)
		exit(-1);
	if (siginfo->si_code != SI_USER)
		exit(-1);
}

static void	signal_handler(int signum, siginfo_t *siginfo, void *ucontext)
{
	static int	i;
	static char	c;

	signal_checker(signum, siginfo, ucontext);
	c = c << 1;
	i++;
	if (siginfo->si_signo == SIGUSR1)
		c = c + 1;
	if (siginfo->si_signo == SIGUSR2)
		c = c + 0;
	if (i == 8)
	{
		if (c != '\0')
			ft_printf("%c", c);
		else if (c == '\0')
			ft_printf("\n");
		i = 0;
		c = 0;
	}
	kill(siginfo->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	signal_action;

	pid = getpid();
	ft_printf("PID is %d.\n", pid);
	signal_action.sa_sigaction = signal_handler;
	sigemptyset(&signal_action.sa_mask);
	signal_action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &signal_action, NULL);
	sigaction(SIGUSR2, &signal_action, NULL);
	while (1)
		pause();
	exit(0);
}
