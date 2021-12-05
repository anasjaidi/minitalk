#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


void	handler(int prb)
{
	static int i;
	prb -= SIGUSR1;
	static char x;
	x = x << 1 | prb;
	i++;
	if (i == 8)
	{
		write(1,&x,1);
		i = 0;
		x = 0;
	}
}


int main()
{
	printf("pid	:	%d\n",  getpid());
	signal(SIGUSR2, handler);
	signal(SIGUSR1, handler);
	while (1)
	{
		sleep(1);
	}
}



