#include "philo.h"

void    lock_printf(char    *s, long time, int ph_id)
{
    t_mutex lock;
    pthread_mutex_lock(&lock);
    printf("%ld %d %s\n", time, ph_id, s);
    pthread_mutex_unlock(&lock);
}
