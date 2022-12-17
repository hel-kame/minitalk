/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 21:54:08 by hel-kame          #+#    #+#             */
/*   Updated: 2022/12/17 22:35:46 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum, siginfo_t *siginfo, void *ucontext)
{
	(void)ucontext;
	if (signum != SIGUSR1)
		return ;
	if (siginfo->si_code != SI_QUEUE)
		return ;
	ft_printf("%d\n", siginfo->si_int);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	signal_action;

	pid = getpid();
	ft_printf("PID is %d\n", pid);
	signal_action.sa_sigaction = signal_handler;
	sigemptyset(&signal_action.sa_mask);
	signal_action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &signal_action, NULL);
	while (1)
		pause();
	return (0);
}
