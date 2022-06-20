#include <sys/time.h>
#include <stdio.h>
#include "philo.h"

long	get_time(long curr)
{
	t_tval time;
	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000 + time.tv_usec / 1000 ) - curr);	
}

int main()
{
	long start = get_time(0);
	printf("%ld\n",start);
	usleep(10000);
	printf("%ld\n",get_time(start));

}
// void	*sleeping(void *arg)
// {
// 	printf("Sleeping...\n");
// 	sleep(10);
// }

int	chop_stick = 0;


int g_state = 42;

void	*take_fork(void	*arg)
{
	(void)arg;
	chop_stick = 1;
	printf("chop_stik is taken %d\n", chop_stick);
	return (NULL);
}

void	change_g_state(void)
{
	g_state = 24;
}

void	*put_back_fork(void	*arg)
{
	(void)arg;
	chop_stick = 0;
	return (NULL);
}

// int main()
// {

// 	pthread_t	thr;
// 	// pthread_t	thr_2;
// 	// pthread_t	thr_3;

// 	pthread_create(&thr, NULL, take_fork, NULL);
// 	// pthread_create(&thr_2, NULL, take_fork, NULL);
// 	// pthread_create(&thr_3, NULL, take_fork, NULL);
// 	// printf("The sate of the chop_stick is %d\n", chop_stick);
// 	printf("g_state : %d\n", g_state);
// 	change_g_state();
// 	printf("g_state : %d\n", g_state);
	
// }