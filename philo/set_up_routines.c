/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_routines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:35:36 by obouizga          #+#    #+#             */
/*   Updated: 2022/06/25 00:16:25 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating_routine(t_philo *ph)
{
	int		left;
	int		right;
	long	es_time;

	left = ph->id - 1;
	right = (ph->id) % ph->n_philos;
	pthread_mutex_lock(&ph->forks[left]);
	lock_print("has taken his left fork", get_time(ph->init_time), ph->id, \
	ph->lock_write);
	pthread_mutex_lock(&ph->forks[right]);
	lock_print("has taken his right fork", get_time(ph->init_time), ph->id, \
	ph->lock_write);
	lock_print("is eating", get_time(ph->init_time), ph->id, ph->lock_write);
	if (ph->ts_eat != -1)
		ph->ts_eat++;
	es_time = get_time(0);
	ph->last_eat = es_time;
	while (get_time(0) - es_time < ph->t_eat)
		usleep(250);
	pthread_mutex_unlock(&ph->forks[left]);
	pthread_mutex_unlock(&ph->forks[right]);
}

void	sleeping_routine(t_philo *ph)
{
	long	ss_time;

	lock_print("is sleeping", get_time(ph->init_time), ph->id, ph->lock_write);
	ss_time = get_time(0);
	while (get_time(0) - ss_time < ph->t_sleep)
		usleep(250);
}

void	thinking_routine(t_philo *ph)
{
	lock_print("is thinking", get_time(ph->init_time), ph->id, ph->lock_write);
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
