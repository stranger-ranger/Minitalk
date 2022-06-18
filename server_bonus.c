/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llatrice <llatrice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:08:17 by llatrice          #+#    #+#             */
/*   Updated: 2022/06/11 13:16:05 by llatrice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_data	g_data;

void	reset_data(void)
{
	g_data.i = 0;
	g_data.x = 0;
	g_data.client_pid = 0;
}

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	sig -= SIGUSR1;
	if (g_data.client_pid != info->si_pid)
		reset_data();
	g_data.x = g_data.x << 1 | sig;
	g_data.i++;
	if (g_data.i == 8)
	{
		if (g_data.x == 0)
			kill(info->si_pid, SIGUSR2);
		write(1, &g_data.x, 1);
		reset_data();
	}
	g_data.client_pid = info->si_pid;
}

int	main(void)
{
	struct sigaction	sa;

	reset_data();
	ft_putstr("pid :    ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		sleep(1);
}
