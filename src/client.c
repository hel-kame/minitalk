/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 22:20:15 by hel-kame          #+#    #+#             */
/*   Updated: 2022/12/17 22:25:12 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int argc, char **argv)
{
	union sigval sigval;
	pid_t pid;

	pid = ft_atoi(argv[1]);
	if (argc < 3 || pid < 0)
		return (-1);
	sigval.sival_int = atoi(argv[2]);
	ft_printf("sender: sending %d to PID %d\n", sigval.sival_int, pid);
	sigqueue(pid, SIGUSR1, sigval);
	return (0);
}
