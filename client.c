/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:23:13 by ajaidi            #+#    #+#             */
/*   Updated: 2021/12/16 19:23:36 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	send_signal(char *str, int pid)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == 48)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
	}
}

char	*convert(char c)
{
	int		x;
	char	*bin;
	int		i;

	i = 8;
	x = c;
	bin = malloc(10);
	bin[9] = 0;
	if (c < 0)
		bin[0] = '1';
	else
		bin[0] = '0';
	while (x)
	{
		bin[i] = (x % 2) + 48;
		x /= 2;
		i--;
	}
	while (i > 0)
	{
		bin[i] = 48;
		i--;
	}
	return (bin);
}

int	main(int argc, char *argv[])
{
	int		i;
	char	*str;

	i = -1;
	while (argv[2][++i])
	{
		str = convert(argv[2][i]);
		send_signal(str, atoi(argv[1]));
	}
	return (0);
}
