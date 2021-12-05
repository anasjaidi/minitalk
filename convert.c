#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
void	send_signal(char *str, int pid)
{
	int i = -1;
	while (str[++i])
	{
		if (str[i] == 48)
		{
			kill(pid, SIGUSR1);
			printf("0");
		}
		else{
			kill(pid, SIGUSR2);
			printf("1");
		}
		usleep(500);
	}
}

char	*convert(char	c)
{
	int x = (int)c;
	char	*bin = malloc(9);
	int i = 7;
	while(x)
	{
		bin[i] = (x % 2) + 48;
		x /= 2;
		i--;
	}
	while (i >= 0)
	{
		bin[i] = 48;
		i--;
	}
	return bin;
}

int main (int argc, char *argv[])
{
	int i = -1;
	char	*str;
	while(argv[2][++i])
	{
		str = convert(argv[2][i]);
		send_signal(str , atoi(argv[1]));
		printf("%d\n", atoi(argv[1]));
		//printf("%s\n", str);
	}
	return 0;
}
