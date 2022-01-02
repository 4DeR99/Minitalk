/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 17:43:53 by moulmado          #+#    #+#             */
/*   Updated: 2022/01/03 00:34:19 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(const char *s)
{
	int		nbr;
	int		n;
	int		i;

	n = 1;
	nbr = 0;
	i = 0;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == '\v'
		|| s[i] == '\f' || s[i] == '\r' || s[i] == ' ')
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			n *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		nbr = (nbr * 10) + (s[i] - '0');
		i++;
	}
	return (nbr * n);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else 
		ft_putchar(n + '0');
}