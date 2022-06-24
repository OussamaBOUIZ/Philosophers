
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_routines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:35:36 by obouizga          #+#    #+#             */
/*   Updated: 2022/06/23 12:05:21 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	let's say we have N = 5
	philo -> left forks[i] = forks[0]
		  -> right forks[(i + 1) % 5] = forks[1]
	philo -> left forks[i] = forks[1]
		  -> right forks[(i + 1) % 5] = forks[2]
	philo -> left forks[i] = forks[2]
		  -> right forks[(i + 1) % 5] = forks[3]
	philo -> left forks[i] = forks[3]
		  -> right forks[(i + 1) % 5] = forks[4]
	philo -> left forks[i] = forks[4]
		  -> right forks[(i + 1) % 5] = forks[0] 
//ORIGINAL
void	eating_routine(t_philo *ph)
{
	int		left;
	int		right;
	long	es_time;

	left = ph->id - 1;
	right = (ph->id) % ph->n_philos;
	pthread_mutex_lock(&ph->forks[left]); // CHECK THE ACCURACY OF THIS
	printf("%ld %d has taken his left fork\n", get_time(ph->init_time), ph->id);
	pthread_mutex_lock(&ph->forks[right]);
	printf("%ld %d has taken his right fork\n", get_time(ph->init_time), ph->id);
	printf("%ld %d is eating\n", get_time(ph->init_time), ph->id);
	es_time = get_time(0);
	ph->last_eat = es_time;
	while (get_time(0) - es_time < ph->t_eat)
		usleep(50);
	pthread_mutex_unlock(&ph->forks[left]);
	pthread_mutex_unlock(&ph->forks[right]);
}


void	sleeping_routine(t_philo *ph)
{
	long	ss_time;

	printf("%ld %d is sleeping\n", get_time(ph->init_time), ph->id + 1); //this ph->id + 1 seems vulnerable
	ss_time = get_time(0);
	while (get_time(0) - ss_time < ph->t_sleep)
		usleep(50);
}
void	thinking_routine(t_philo *ph)
{
	printf("%ld %d is thinking\n", get_time(ph->init_time), ph->id);
}
*/
//TESTING
void	eating_routine(t_philo *ph)
{
	int		left;
	int		right;
	long	es_time;

	left = ph->id - 1;
	right = (ph->id) % ph->n_philos;
	pthread_mutex_lock(&ph->forks[left]);
	lock_print("has taken his left fork", get_time(ph->init_time), ph->id, ph->lock_write, 1);
	pthread_mutex_lock(&ph->forks[right]);
	lock_print("has taken his right fork", get_time(ph->init_time), ph->id, ph->lock_write, 1);
	lock_print("is eating", get_time(ph->init_time), ph->id, ph->lock_write,1);
	es_time = get_time(0);
	ph->last_eat = es_time;
	while (get_time(0) - es_time < ph->t_eat)
		usleep(250);
	pthread_mutex_unlock(&ph->forks[left]);
	pthread_mutex_unlock(&ph->forks[right]);
}

//TESTING
void	sleeping_routine(t_philo *ph)
{
	long	ss_time;

	lock_print("is sleeping", get_time(ph->init_time), ph->id, ph->lock_write, 1);
	ss_time = get_time(0);
	while (get_time(0) - ss_time < ph->t_sleep)
		usleep(250);
}

//TESTING
void	thinking_routine(t_philo *ph)
{
	lock_print("is thinking", get_time(ph->init_time), ph->id, ph->lock_write, 1);
}

void	*set_up_routines(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		eating_routine(philo);
		sleeping_routine(philo);
		thinking_routine(philo);
	}
	return (NULL);
}
