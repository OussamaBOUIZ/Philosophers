#include <sys/time.h>
#include <stdio.h>
#include "philo.h"

// long	get_time(long curr)
// {
// 	t_tval time;
// 	gettimeofday(&time, NULL);
// 	return ((time.tv_sec * 1000 + time.tv_usec / 1000 ) - curr);	
// }

long	get_time(long	curr)
{
	t_tval	time;
	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000 - curr);
}

int main(void)
{
	long	start = get_time(0);
	printf("%ld\n", start);
	usleep(12000);
	printf("%ld\n", get_time(start));
	return (0);
}