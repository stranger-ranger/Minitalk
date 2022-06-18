/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llatrice <llatrice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:18:04 by llatrice          #+#    #+#             */
/*   Updated: 2022/06/11 12:44:56 by llatrice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_data
{
	int		i;
	char	x;
	int		client_pid;
}	t_data;
void	send_byte(char byte, int pid);
void	send_message(char *str, int pid);
void	usage(void);
void	reset_data(void);
void	handler(int sig, siginfo_t *info, void *ucontext);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int n);

int		ft_atoi(const char *str);

#endif
