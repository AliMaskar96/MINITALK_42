/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 22:25:16 by aait-mas          #+#    #+#             */
/*   Updated: 2022/03/06 17:46:39 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_atoi(const char *str)
{	
	int	i;
	int	res;
	int	moins;

	i = 0;
	res = 0;
	moins = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			moins = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{	
		res = (res * 10) + (str[i] - '0');
		i++;
	}		
	return (res * moins);
}

void	convert_client(char c, int pid)
{
	int	j;
	int	b;

	j = 7;
	b = 0;
	while (j >= 0)
	{
		b = ((c >> j) & 1);
		if (b == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		j--;
	}
}

void	print_message(int sig)
{
	if (sig == SIGUSR1)
		write(1, "Message Reçu\n", 13);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	signal(SIGUSR1, print_message);
	i = 0;
	if (ac != 3)
	{
		write(1, "[./client_bonus] [PID] [MESSAGE]\n", 33);
		return (0);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		write(1, "WRONG PID !", 11);
		return (-1);
	}
	else
	{
		while (av[2][i])
		{
			convert_client(av[2][i], pid);
			i++;
		}
		convert_client(av[2][i], pid);
	}
}
