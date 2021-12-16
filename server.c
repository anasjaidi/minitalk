/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:52:14 by ajaidi            #+#    #+#             */
/*   Updated: 2021/12/16 19:52:21 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void	handler(int prb)
{
	static int	i;
	static char	x;
	static int	sign;

	prb -= SIGUSR1;
	if (i == 0 && prb == 1)
	{
		sign = -1;
		i++;
		return ;
	}
	else if (i == 0 && prb == 0)
		sign = 1;
	x = x << 1 | prb;
	i++;
	if (i == 9)
	{
		x *= sign;
		write(1, &x, 1);
		i = 0;
		x = 0;
		sign = 1;
	}
}

int	main(void)
{
	printf("pid	:	%d\n", getpid());
	signal(SIGUSR2, handler);
	signal(SIGUSR1, handler);
	while (1)
		sleep(1);
}
