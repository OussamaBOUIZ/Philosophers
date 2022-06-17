#include <sys/time.h>
#include <stdio.h>
#include "philo.h"

long	get_time(long curr)
{
	t_tval time;
	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000 + time.tv_usec / 1000 ) - curr);	
}

void	*sleeping(void *arg)
{
	printf("Sleeping...\n");
	sleep(10);
}

int main()
{
	long ila = get_time(0);
	red();
	printf("%ld\n",get_time(ila));
	sleep(1);
	printf("%ld\n",get_time(ila));
}