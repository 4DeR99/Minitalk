/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 17:09:01 by moulmado          #+#    #+#             */
/*   Updated: 2022/01/03 00:40:09 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	recieved(int sig)
{
	(void)sig;
	write(1, "recieved\n", 9);
}

void	send_zero(int pid)
{
	int	i;

	i = 0;
	while (i++ < 8)
	{
		kill(pid, 30);
		usleep(400);
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;
	int	c;

	if (ac != 3)
	{
		ft_putstr("------------MINITALK_BONUS------------\n");
		ft_putstr("USAGE : ./client_bonus + PID + MESSAGE\n");
		exit(0);
	}
	pid = ft_atoi(av[1]);
	i = 0;
	while (av[2][i])
	{
		c = 0;
		while (c < 8)
		{	
			kill(pid, (av[2][i] >> c++ & 1) + 30);
			usleep(400);
		}
		i++;
	}
	signal(30, recieved);
	send_zero(pid);
	sleep(1);
}
