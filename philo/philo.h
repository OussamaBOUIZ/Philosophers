/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 06:56:58 by obouizga          #+#    #+#             */
/*   Updated: 2022/06/26 12:39:59 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

#include <stdio.h>

typedef struct timeval t_tval;  // number of i's right neighbor
typedef pthread_mutex_t	t_mutex;
typedef struct timeval	t_time;
typedef struct s_arg
{
	int	num_ph;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	ts_eat;
}			t_arg;

typedef struct s_philo
{
	int		n_philos;
	long	init_time;
	int		id;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		ts_eat;
	long	last_eat;
	t_mutex	*forks;
	t_mutex	*lock_write;
}				t_philo;

typedef struct s_cmp
{
	pthread_t	*threads;
	t_philo		**philos;
}				t_cmp;

long		get_time(long curr);
void		*set_up_routines(void	*arg);
void		*pthr_fail(void);
int			is_integer(char	*s);
t_arg		*check_get_args(int ac, char **av);
int			ft_atoi(const char *str);
void		*malloc_fail(void);
t_cmp		*launch_philos(t_arg *args);
size_t		ft_strlen(char *s);
// void		lock_print(char *s, t_philo *ph);
// void		lock_print_death(char *s, t_philo *ph);
void		lock_print(char *s, long time, int id, t_mutex *lock);
void		lock_print_death(char *s, long time, int id, t_mutex *lock);
int			check_range(char **nums, int n);
void		ft_usleep(long time_to_eat);
#endif



/*
		lock_print("has taken a fork", get_time(ph->init_time), ph->id, \
	ph->lock_write);
	pthread_mutex_lock(&ph->forks[right]);
	lock_print("has taken a fork", get_time(ph->init_time), ph->id, \
	ph->lock_write);
	lock_print("is eating", get_time(ph->init_time), ph->id, ph->lock_write);
	if (ph->ts_eat != -1)
		ph->ts_eat++;
	es_time = get_time(0);
	ph->last_eat = es_time;
	while (get_time(0) - es_time < ph->t_eat)
		usleep(200);
	pthread_mutex_unlock(&ph->forks[left]);
	pthread_mutex_unlock(&ph->forks[right]);
*/