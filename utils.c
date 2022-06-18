/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llatrice <llatrice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 12:38:26 by llatrice          #+#    #+#             */
/*   Updated: 2022/06/11 12:49:02 by llatrice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			znak;
	long long	output;

	i = 0;
	znak = 1;
	output = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\v')
		|| (str[i] == '\n') || (str[i] == '\r') || (str[i] == '\f'))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i++] == '-')
			znak = znak * (-1);
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
		output = (output * 10) + ((long)(str[i++] - '0'));
	output = output * (long long)znak;
	if (((-1) * 2147483648 <= output) && (output <= 2147483647))
		return ((int)output);
	else
		return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(n * (-1));
	}
	else
	{
		if (n >= 10)
			ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
	}
}
