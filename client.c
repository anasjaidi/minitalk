/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:23:13 by ajaidi            #+#    #+#             */
/*   Updated: 2021/12/18 16:39:57 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>


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
		usleep(500);
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
	printf("./client [server-pid] [message]\n");
	exit(0);
}

void	handler(int sig)
{
	printf("every thing it's all right");
}

int	main(int ac, char *av[])
{
	int		server_pid;
	char	*msg;

	signal(SIGUSR2, handler);
	if (ac != 3)
		usage();
	server_pid = atoi(av[1]);
	msg = av[2];
	send_message(msg, server_pid);
	return (0);
}
