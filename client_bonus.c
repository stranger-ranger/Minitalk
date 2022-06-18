/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llatrice <llatrice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:08:02 by llatrice          #+#    #+#             */
/*   Updated: 2022/06/18 15:55:04 by llatrice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_byte(char byte, int pid)
{
	int	j;

	j = 7;
	while (j >= 0)
	{
		if (byte >> j & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(300);
		j--;
	}
}

void	send_message(char *str, int pid)
{
	int	i;

	i = -1;
	while (str[++i])
		send_byte(str[i], pid);
	send_byte(0, pid);
}

void	usage(void)
{
	ft_putstr("./client [server-pid] [message]\n");
	exit(0);
}

void	handler2(int sig)
{
	ft_putstr("The message was sent successfully\n");
}

int	main(int argc, char *argv[])
{
	int		server_pid;
	char	*msg;

	signal(SIGUSR2, handler2);
	if (argc != 3)
		usage();
	server_pid = ft_atoi(argv[1]);
	msg = argv[2];
	send_message(msg, server_pid);
	return (0);
}
