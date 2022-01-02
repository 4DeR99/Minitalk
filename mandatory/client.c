/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 17:09:01 by moulmado          #+#    #+#             */
/*   Updated: 2022/01/03 00:33:17 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	int	pid;
	int	i;
	int	c;

	if (ac != 3)
	{
		ft_putstr("---------------MINITALK---------------\n");
		ft_putstr("USAGE : ./client_bonus + PID + MESSAGE\n");
		exit(1);
	}
	pid = ft_atoi(av[1]);
	i = 0;
	while (av[2][i])
	{
		c = 0;
		while (c < 8)
		{	
			kill(pid, (av[2][i] >> c & 1) + 30);
			usleep(400);
			c++;
		}
		i++;
	}
}
