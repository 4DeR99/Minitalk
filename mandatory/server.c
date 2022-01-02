/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 17:09:23 by moulmado          #+#    #+#             */
/*   Updated: 2022/01/02 23:35:01 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_client_pid;

void	shift(int sig, siginfo_t *siginfo, void *ucontext_t)
{
	static char	c;
	static int	i;

	(void)ucontext_t;
	if (!g_client_pid)
		g_client_pid = siginfo->si_pid;
	if (siginfo->si_pid != g_client_pid)
	{
		g_client_pid = siginfo->si_pid;
		c = 0;
		i = 0;
	}
	c += ((sig - 30) << i);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &shift;
	sa.sa_flags = SA_SIGINFO;
	ft_putstr("PID: ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	sigaction(30, &sa, NULL);
	sigaction(31, &sa, NULL);
	while (1)
		pause();
}
