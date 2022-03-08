/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:37:31 by aait-mas          #+#    #+#             */
/*   Updated: 2022/03/01 01:26:33 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putnbr(int n)
{
	unsigned long	nm;

	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	nm = n;
	if (nm >= 10)
		ft_putnbr(nm / 10);
	ft_putchar(nm % 10 + 48);
}

void	convert_server(int sig)
{
	static int	c;
	static int	i;

	if (sig == SIGUSR2)
		c += (1 << (7 - i));
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	if (pid <= 0)
		return (0);
	write(1, GRN, ft_strlen(GRN));
	write(1, "\n \n               *** Welcome in Ali's Minitalk *** \n\n\n\n", 56);
	write(1, "THE PID IS : ", 13);
	write(1, RED, ft_strlen(RED));
	ft_putnbr(pid);
	write(1, GRN, ft_strlen(GRN));
	write(1, "\n \nTo start the chat, ", 22);
	write(1, "share this code ", 16);
	write(1, RED, ft_strlen(RED));
	ft_putnbr(pid);
	write(1, GRN, ft_strlen(GRN));
	write(1, " to the client !\n\n\n\n", 20);
	write(1, "                ***** ***** ***** ***** *****\n\n", 47);
	write(1, WHT, ft_strlen(WHT));
	write(1, "\n", 1);
	signal(SIGUSR2, convert_server);
	signal(SIGUSR1, convert_server);
	while (42)
		pause();
}
